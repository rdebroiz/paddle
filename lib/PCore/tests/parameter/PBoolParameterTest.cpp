#include "PBoolParameterTest.h"

#include <QSignalSpy>

void PBoolParameterTest::type()
{
    PBoolParameter *param = new PBoolParameter("foo", this);
    QCOMPARE(param->type(), PAbstractParameter::P_PARAMETER_BOOL);
}

void PBoolParameterTest::setValue()
{
    PBoolParameter *param = new PBoolParameter("foo", this);
    QSignalSpy spy(param, &PBoolParameter::valueChanged);

    param->setValue(true);
    int nbSignalEmitted = spy.count();
    QVERIFY(param->value() == true);

    param->setValue(false);
    QVERIFY(param->value() == false);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);

    param->setValue(false);
    QVERIFY(param->value() == false);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);
}

void PBoolParameterTest::trigger()
{
    PBoolParameter *param = new PBoolParameter("foo", this);
    QSignalSpy spy(param, &PBoolParameter::valueChanged);

    param->setValue(true);
    int nbSignalEmitted = spy.count();
    bool paramValue = param->value();

    param->trigger();
    QVERIFY(param->value() == paramValue);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);
}

QTEST_MAIN(PBoolParameterTest)
