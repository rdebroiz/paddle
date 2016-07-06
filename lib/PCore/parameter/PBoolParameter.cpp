#include "PBoolParameter.h"
#include "PBoolParameter_p.h"

#include <QPointer>

#include "PBoolGroup.h"

PBoolParameterPrivate::PBoolParameterPrivate(PBoolParameter *q, QString const& q_id)
    : PAbstractParameterPrivate(q, q_id)
{
    value = true;
    group = NULL;
}

PBoolParameter::PBoolParameter(QString const& id,  QObject *parent)
    : PAbstractParameter(*new PBoolParameterPrivate(this, id), id, parent)
{

}

PBoolParameter::PBoolParameter(PBoolParameterPrivate &d, QString const& id,  QObject *parent)
    : PAbstractParameter(d, id, parent)
{

}

PBoolParameter::~PBoolParameter()
{

}

bool PBoolParameter::value() const
{
    Q_D(const PBoolParameter);

    return d->value;
}

void PBoolParameter::setValue(bool value)
{
    Q_D(PBoolParameter);

    if(value != d->value)
    {
        // We don't want to toggle the value if it is "true" and the parameter belong
        // to an exclusive group
        if(d->group.isNull() || d->group->trueParameter() != this)
            d->value = value;

        // Emit value change even if hasn't change.
        // So widgets go back to a 'checked' state when the user tries to activate it
        // when we belongs to one group and we are the 'true' parameter.
        emit valueChanged(d->value);
    }
}

void PBoolParameter::trigger()
{
    Q_D(PBoolParameter);

    emit valueChanged(d->value);
}
