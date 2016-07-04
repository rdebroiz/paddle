#include "PDoubleParameter.h"
#include "PAbstractParameter_p.h"

#include <QtDebug>

class PDoubleParameterPrivate: public PAbstractParameterPrivate
{
public:
    double value, min, max;

    PDoubleParameterPrivate(PDoubleParameter *q, QString const& q_id)
        : PAbstractParameterPrivate(q, q_id)
    {
        value = 0.0;
        min = 0.0;
        max = 100.0;
    }
};

PDoubleParameter::PDoubleParameter(QString const& id,  QObject *parent)
    : PAbstractParameter(*new PDoubleParameterPrivate(this, id), id, parent)
{
}

PDoubleParameter::~PDoubleParameter()
{

}

double PDoubleParameter::value() const
{
    Q_D(const PDoubleParameter);

    return d->value;
}

void PDoubleParameter::setValue(double value)
{
    Q_D(PDoubleParameter);

        if(value < d->min)
            value = d->min;
        else if(value > d->max)
            value = d->max;

        // Comparison with epsilon value ?
        if(value != d->value)
        {
            d->value = value;
            emit valueChanged(d->value);
        }
}


void PDoubleParameter::setRange(double min, double max)
{
    Q_D(PDoubleParameter);

    // Comparison with epsilon value ?
    if((min != d->min || max != d->max) && min <= max)
    {
        d->min = min;
        d->max = max;
        emit rangeChanged(min, max);
    }
    else
        qWarning() << Q_FUNC_INFO << "Attempt to set invalid range.";
}

double PDoubleParameter::min() const
{
    Q_D(const PDoubleParameter);

    return d->min;
}

double PDoubleParameter::max() const
{
    Q_D(const PDoubleParameter);

    return d->max;
}

void PDoubleParameter::trigger()
{
    Q_D(PDoubleParameter);

    emit valueChanged(d->value);
}
