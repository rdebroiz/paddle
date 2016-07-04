#pragma once

#include "PParameterPool.h"

#include <QMultiHash>

class PParameterPoolPrivate
{

public:
    Q_DISABLE_COPY(PParameterPoolPrivate)
    Q_DECLARE_PUBLIC(PParameterPool)
    // Constructor that initializes the q-ptr
    PParameterPoolPrivate(PParameterPool *q);
    PParameterPool *q_ptr; // q-ptr points to the API class

    QMultiHash<QString, PStringParameter*> stringHash;
    QMultiHash<QString, PBoolParameter *> boolHash;
    QMultiHash<QString, PIntParameter *> intHash;
    QMultiHash<QString, PDoubleParameter *> doubleHash;

    void connect(PStringParameter *param);
    void disconnect(PStringParameter *param);

    void connect(PBoolParameter *param);
    void disconnect(PBoolParameter *param);

    void connect(PIntParameter *param);
    void disconnect(PIntParameter *param);

    void connect(PDoubleParameter *param);
    void disconnect(PDoubleParameter *param);
};
