#pragma once

#include <QtTest>

#include "PBoolGroup.h"

class PBoolGroupTest: public QObject
{
    Q_OBJECT

private slots:

    void addParameterTest();
    void removeParameterTest();
    void trueParameterTest();

    void noParameterinMultipleGroup();
};
