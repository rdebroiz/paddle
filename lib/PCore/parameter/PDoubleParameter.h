#pragma once

#include "PAbstractParameter.h"

class PDoubleParameterPrivate;
class PDoubleParameter : public PAbstractParameter
{
    Q_OBJECT

public:
    PDoubleParameter(const QString & id, QObject *parent = NULL);
    virtual ~PDoubleParameter();

    virtual PAbstractParameter::ParameterType type() const {return PAbstractParameter::P_PARAMETER_DOUBLE;}

    double value() const;

    void setRange(double min, double max);
    double min() const;
    double max() const;

public slots:
    void setValue(double value);

    virtual void trigger();

signals:
    void valueChanged(double value);
    void rangeChanged(double min, double max);

protected:
    PDoubleParameter(PDoubleParameterPrivate &d, const QString & id, QObject *parent = NULL);

private:
    Q_DECLARE_PRIVATE(PDoubleParameter)
};
