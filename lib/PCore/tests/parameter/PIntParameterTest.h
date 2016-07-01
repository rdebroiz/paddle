#pragma once

#include <QtTest>

#include "PIntParameter.h"

class PIntParameterTest: public QObject
{
    Q_OBJECT

private slots:

    void type();
    void setValue();
    void trigger();
    void setRange();
};
