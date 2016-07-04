#pragma once

#include <QtTest>

#include "PStringParameter.h"

class PStringParameterTest: public QObject
{
    Q_OBJECT

private slots:

    void type();
    void setValue();
    void trigger();
};
