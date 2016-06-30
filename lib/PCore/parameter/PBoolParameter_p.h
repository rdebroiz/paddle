#pragma once

#include "PAbstractParameter_p.h"

#include "PBoolGroup.h"

#include <QPointer>

class PBoolParameterPrivate: public PAbstractParameterPrivate
{
public:
    PBoolParameterPrivate(PBoolParameter *q, QString const& q_id);

    bool value;
    QPointer<PBoolGroup> group;
};
