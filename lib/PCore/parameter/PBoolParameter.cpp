#include "PBoolParameter.h"

class PBoolParameterPrivate
{
public:
    bool value;
};

PBoolParameter::PBoolParameter(QString const& name,  QObject *parent)
    : PAbstractParameter(name, parent), d(new PBoolParameterPrivate)
{

}

PBoolParameter::~PBoolParameter()
{

}

bool PBoolParameter::value() const
{
    return d->value;
}

void PBoolParameter::setValue(bool value)
{
    if(value != d->value)
    {
        d->value = value;
        emit valueChanged(d->value);
    }
}

void PBoolParameter::trigger()
{
    emit valueChanged(d->value);
}
