#pragma once

#include "PAbstractParameter.h"

class PIntParameterPrivate;
class PIntParameter : public PAbstractParameter
{
    Q_OBJECT

public:
    PIntParameter(const QString & id, QObject *parent = NULL);
    virtual ~PIntParameter();

    virtual PAbstractParameter::ParameterType type() const {return PAbstractParameter::P_PARAMETER_INT;}

    int value() const;

    void setRange(int min, int max);
    int min() const;
    int max() const;

public slots:
    void setValue(int value);

    virtual void trigger();

signals:
    void valueChanged(int value);
    void rangeChanged(int min, int max);

protected:
    // Allow PBoolParameter subclasses to pass on their Private d pointer.
    PIntParameter(PIntParameterPrivate &d, const QString & id, QObject *parent = NULL);

private:
    Q_DECLARE_PRIVATE(PIntParameter)
};
