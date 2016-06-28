#pragma once

#include <QtTest>

#include "PBoolParameter.h"

class PBoolParameterTest: public QObject
{
    Q_OBJECT

private slots:

    void type();
    void setValue();
    void trigger();
};
