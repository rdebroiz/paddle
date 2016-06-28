#pragma once

#include <PAbstractParameter.h>


class PBoolParameterPrivate;
class PBoolParameter : public PAbstractParameter
{
    Q_OBJECT

public:
    PBoolParameter(const QString & name, QObject *parent = NULL);
    virtual ~PBoolParameter();

    virtual ParameterType type() const {return ParameterType::P_PARAMETER_BOOL;}

    bool value() const;
public slots:
    void setValue(bool value);

    virtual void trigger();

signals:
    void valueChanged(bool value);

private:
    const QScopedPointer<PBoolParameterPrivate> d;
};
