#pragma once

#include "PAbstractParameter.h"

class PAbstractParameterPrivate
{
public:
    Q_DISABLE_COPY(PAbstractParameterPrivate)
    Q_DECLARE_PUBLIC(PAbstractParameter)
    // Constructor that initializes the q-ptr
    PAbstractParameterPrivate(PAbstractParameter *q, QString const& q_id);
    PAbstractParameter *q_ptr; // q-ptr points to the API class

    QString id;
    QString description;
    QString caption;
};
