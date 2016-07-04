#pragma once

#include <QObject>

#include "PAbstractParameter.h"
#include "PStringParameter.h"
#include "PBoolParameter.h"
#include "PIntParameter.h"
#include "PDoubleParameter.h"

class PParameterPoolPrivate;
class PParameterPool: public QObject
{
    Q_OBJECT

//TODO find a better implementation of this class.
//     (less connec/disconnect, and less cast).

public:
    PParameterPool(QObject *parent = 0);
    virtual ~PParameterPool();

    void append(PStringParameter *parameter);
    void remove(PStringParameter *parameter);

    void append(PBoolParameter *parameter);
    void remove(PBoolParameter *parameter);

    void append(PIntParameter *parameter);
    void remove(PIntParameter *parameter);

    void append(PDoubleParameter *parameter);
    void remove(PDoubleParameter *parameter);

    void append(PAbstractParameter *parameter);
    void remove(PAbstractParameter *parameter);

protected slots:
    void _dispatchString(QString const& value);
    void _dispatchBool(bool value);
    void _dispatchInt(int value);
    void _dispatchDouble(double value);
    void _removeSender(QObject *sender);

protected:
    PParameterPool(PParameterPoolPrivate &d, QObject* parent = NULL);
    QScopedPointer<PParameterPoolPrivate> const d_ptr;
private:
    Q_DECLARE_PRIVATE(PParameterPool)
};
