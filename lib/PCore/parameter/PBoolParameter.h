#pragma once

#include <PAbstractParameter.h>


class PBoolParameterPrivate;
class PBoolParameter : public PAbstractParameter
{
    Q_OBJECT

    Q_DECLARE_PRIVATE(PBoolParameter)

public:
    PBoolParameter(const QString & id, QObject *parent = NULL);
    virtual ~PBoolParameter();

    virtual ParameterType type() const {return ParameterType::P_PARAMETER_BOOL;}

    bool value() const;
public slots:
    void setValue(bool value);

    virtual void trigger();

signals:
    void valueChanged(bool value);

protected:
    // allow PBoolParameter subclasses to pass on their Private
    PBoolParameter(PBoolParameterPrivate &d, const QString & id, QObject *parent = NULL);
};
