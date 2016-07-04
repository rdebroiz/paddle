#pragma once

#include <QtTest>

#include "PParameterPool.h"

class PParameterPoolTest: public QObject
{
    Q_OBJECT

private slots:

    void appendString();
    void appendBool();
    void appendInt();
    void appendDouble();

    void removeString();
    void removeBool();
    void removeInt();
    void removeDouble();
};
