#include "PIntParameter.h"
#include "PAbstractParameter_p.h"

#include <QtDebug>

class PIntParameterPrivate: public PAbstractParameterPrivate
{

public:
    int value, min, max;

    PIntParameterPrivate(PIntParameter *q, QString const& q_id)
        : PAbstractParameterPrivate(q, q_id)
    {
        value = 0;
        min = 0;
        max = 100;
    }

};

PIntParameter::PIntParameter(QString const& id,  QObject *parent)
    : PAbstractParameter(*new PIntParameterPrivate(this, id), id, parent)
{

}

PIntParameter::PIntParameter(PIntParameterPrivate &d, QString const& id,  QObject *parent)
    : PAbstractParameter(d, id, parent)
{

}

PIntParameter::~PIntParameter()
{

}

int PIntParameter::value() const
{
    Q_D(const PIntParameter);

    return d->value;
}

void PIntParameter::setValue(int value)
{
    Q_D(PIntParameter);

    if(value < d->min)
        value = d->min;
    else if(value > d->max)
        value = d->max;

    if(value != d->value)
    {
        d->value = value;
        emit valueChanged(d->value);
    }
}

void PIntParameter::setRange(int min, int max)
{
    Q_D(PIntParameter);

    if((min != d->min || max != d->max) && min <= max)
    {
        d->min = min;
        d->max = max;
        emit rangeChanged(min, max);
    }
    else
        qWarning() << Q_FUNC_INFO << "Attempt to set invalid range.";
}

int PIntParameter::min() const
{
    Q_D(const PIntParameter);

    return d->min;
}

int PIntParameter::max() const
{
    Q_D(const PIntParameter);

    return d->max;
}

void PIntParameter::trigger()
{
    Q_D(PIntParameter);

    emit valueChanged(d->value);
}
