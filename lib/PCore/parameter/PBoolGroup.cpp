#include "PBoolGroup.h"

#include <QObject>
#include <QPointer>
#include <QSet>
#include <QDebug>

#include "PBoolParameter_p.h"

class PBoolGroupPrivate
{
public:
    Q_DISABLE_COPY(PBoolGroupPrivate)
    Q_DECLARE_PUBLIC(PBoolGroup)

    PBoolGroupPrivate(PBoolGroup *q);
    PBoolGroup *q_ptr;

    QList <PBoolParameter *> parameters;
    QPointer<PBoolParameter> trueParam;
};

PBoolGroupPrivate::PBoolGroupPrivate(PBoolGroup *q):
    q_ptr(q)
{
}

void PBoolGroup::_toggleParameters(bool value)
{   
    Q_D(PBoolGroup);
    // TODO: Not the most efficient way to do it.
    // Another way would to notify other parameter throug signals
    // And so avoid to walk throug all the set of parameters to give them
    // the right value.

    // if !value, it just been called after triggering a parameter with 'false 'as value.
    // if sender ==  trueParameter, it been called after triggering the 'true' parameter.
    if(value && this->sender() != d->trueParam)
    {
        PBoolParameter *previous = d->trueParam;
        d->trueParam = NULL;

        for(PBoolParameter* param : d->parameters)
        {
            if(param != previous && param->value())
                d->trueParam = param;
            else
                param->setValue(false);
        }
    }
}

PBoolGroup::PBoolGroup(QObject *parent)
    : QObject(parent), d_ptr(new PBoolGroupPrivate(this))
{
}

PBoolGroup::~PBoolGroup()
{
    Q_D(PBoolGroup);

    for(PBoolParameter *param : d->parameters)
        param->d_func()->group = NULL;
}

void PBoolGroup::addParameter(PBoolParameter *param)
{
    Q_D(PBoolGroup);

    if(param->d_func()->group != this)
    {
        // If param is already in a group, remove it from it.
        if(!param->d_func()->group.isNull())
            param->d_func()->group->removeParameter(param);

        // Affect the group of the param to 'this'.
        param->d_func()->group = this;

        // If it is the first parameter of the group, set its value to 'true'.
        // It's supposed to always have one and only one parameter to true.
        if(d->parameters.isEmpty())
            param->setValue(true);

        d->parameters << param;
        connect(param, &PBoolParameter::valueChanged,
                this, &PBoolGroup::_toggleParameters);

        param->trigger();
    }
}

void PBoolGroup::removeParameter(PBoolParameter *param)
{
    Q_D(PBoolGroup);

    d->parameters.removeAll(param);
    param->d_func()->group = NULL;

    // If we removed the true parameter we set the value of the last added one to true,
    // so there is always a valid true parameter.
    if(param == d->trueParam && !d->parameters.isEmpty())
        d->parameters.last()->setValue(true);
    else
        d->trueParam = NULL;

}

QList<PBoolParameter *> PBoolGroup::parameters() const
{
    Q_D(const PBoolGroup);

    return d->parameters;
}

PBoolParameter* PBoolGroup::trueParameter() const
{
    Q_D(const PBoolGroup);

    return d->trueParam;
}



