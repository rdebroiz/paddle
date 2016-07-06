#pragma once

#include <PAbstractParameter.h>

class PBoolGroup;
class PBoolGroupPrivate;
class PBoolParameterPrivate;
class PBoolParameter : public PAbstractParameter
{
    Q_OBJECT

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
    // Allow PBoolParameter subclasses to pass on their Private d pointer.
    PBoolParameter(PBoolParameterPrivate &d, const QString & id, QObject *parent = NULL);

private:
    Q_DECLARE_PRIVATE(PBoolParameter)
    // Needed to avoid to have a parameter owned by more than only one PBoolGroup.
    friend class PBoolGroup;
    friend class PBoolGroupPrivate;
};
