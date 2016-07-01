#include "PIntParameterTest.h"

#include <QSignalSpy>

void PIntParameterTest::type()
{
    PIntParameter *param = new PIntParameter("foo", this);
    QCOMPARE(param->type(), PAbstractParameter::P_PARAMETER_INT);
}

void PIntParameterTest::setValue()
{
    PIntParameter *param = new PIntParameter("foo", this);
    QSignalSpy spy(param, &PIntParameter::valueChanged);

    param->setValue(1);
    int nbSignalEmitted = spy.count();
    QVERIFY(param->value() == 1);

    param->setValue(2);
    QVERIFY(param->value() == 2);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);

    param->setValue(2);
    QVERIFY(param->value() == 2);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);

    param->setValue(param->min());
    QVERIFY(param->value() == param->min());
    QCOMPARE(spy.count(), nbSignalEmitted + 2);

    param->setValue(param->min() - 1);
    QVERIFY(param->value() == param->min());
    QCOMPARE(spy.count(), nbSignalEmitted + 2);

    param->setValue(param->max() + 1);
    QVERIFY(param->value() == param->max());
    QCOMPARE(spy.count(), nbSignalEmitted + 3);
}

void PIntParameterTest::trigger()
{
    PIntParameter *param = new PIntParameter("foo", this);
    QSignalSpy spy(param, &PIntParameter::valueChanged);

    param->setValue(1);
    int nbSignalEmitted = spy.count();
    int paramValue = param->value();

    param->trigger();
    QVERIFY(param->value() == paramValue);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);
}

void PIntParameterTest::setRange()
{
    PIntParameter *param = new PIntParameter("foo", this);
    QSignalSpy spy(param, &PIntParameter::rangeChanged);
    int nbSignalEmitted = spy.count();

    int min = param->min();
    int max = param->max();

    param->setRange(min, max);
    QVERIFY(param->min() == min && param->max() == max);
    QVERIFY(spy.count() == nbSignalEmitted);

    param->setRange(max, min);
    QVERIFY(param->min() == min && param->max() == max);
    QVERIFY(spy.count() == nbSignalEmitted);

    param->setRange(min, max + 1);
    QVERIFY(param->min() == min && param->max() == max + 1);
    QVERIFY(spy.count() == nbSignalEmitted + 1);

    param->setRange(min - 1, max);
    QVERIFY(param->min() == min - 1 && param->max() == max);
    QVERIFY(spy.count() == nbSignalEmitted + 2);

    param->setRange(min - 1, max + 1);
    QVERIFY(param->min() == min - 1 && param->max() == max + 1);
    QVERIFY(spy.count() == nbSignalEmitted + 3);
}

QTEST_MAIN(PIntParameterTest)
