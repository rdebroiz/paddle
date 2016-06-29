#include "PBoolParameter.h"

#include "PAbstractParameter_p.h"

class PBoolParameterPrivate: public PAbstractParameterPrivate
{
public:
    PBoolParameterPrivate(PBoolParameter *q, QString const& q_id)
        : PAbstractParameterPrivate(q, q_id) {}
    bool value;
};

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
        d->value = value;
        emit valueChanged(d->value);
    }
}

void PBoolParameter::trigger()
{
    Q_D(PBoolParameter);

    emit valueChanged(d->value);
}
