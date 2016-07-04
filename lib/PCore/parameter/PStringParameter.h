#pragma once

#include "PAbstractParameter.h"

class PStringParameterPrivate;
class PStringParameter : public PAbstractParameter
{
    Q_OBJECT

public:
    PStringParameter(const QString & id, QObject *parent = NULL);
    virtual ~PStringParameter();

    virtual PAbstractParameter::ParameterType type() const {return PAbstractParameter::P_PARAMETER_STRING;}

    QString value() const;
public slots:
    void setValue(QString const& value);

    virtual void trigger();

signals:
    void valueChanged(QString const& value);

protected:
    PStringParameter(PStringParameterPrivate &d, QString const& id, QObject *parent = NULL);

private:
    Q_DECLARE_PRIVATE(PStringParameter)
};
