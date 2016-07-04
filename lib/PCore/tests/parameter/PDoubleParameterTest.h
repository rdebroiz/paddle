#pragma once

#include <QtTest>

#include "PDoubleParameter.h"

class PDoubleParameterTest: public QObject
{
    Q_OBJECT

private slots:

    void type();
    void setValue();
    void trigger();
    void setRange();
};
