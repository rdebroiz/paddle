#pragma once

#include <QtTest>

#include <PAbstractParameter.h>

class PAbstractParameterMoc: public PAbstractParameter
{
    Q_OBJECT

public:
    PAbstractParameterMoc(QString const& id, QObject* parent = NULL): PAbstractParameter(id, parent) {}
    PAbstractParameter::ParameterType type() const {return PAbstractParameter::P_PARAMETER_UNDEFINED;}
public slots:
    void trigger () {}
};

class PAbstractParameterMoc2: public PAbstractParameter
{
    Q_OBJECT

public:
    PAbstractParameterMoc2(QString const& id, QObject* parent = NULL): PAbstractParameter(id, parent) {}
    PAbstractParameter::ParameterType type() const
    {
        return static_cast<PAbstractParameter::ParameterType>(PAbstractParameter::P_PARAMETER_UNDEFINED + 42);
    }
public slots:
    void trigger () {}
};


class PAbstractParameterTest: public QObject
{
    Q_OBJECT

private slots:

    void match();
    void match_data();

    void captionChanged();
    void descriptionChanged();
};


