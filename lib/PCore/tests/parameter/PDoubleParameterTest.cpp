#include "PDoubleParameterTest.h"

#include <QSignalSpy>

void PDoubleParameterTest::type()
{
    PDoubleParameter *param = new PDoubleParameter("foo", this);
    QCOMPARE(param->type(), PAbstractParameter::P_PARAMETER_DOUBLE);
}

void PDoubleParameterTest::setValue()
{
    PDoubleParameter *param = new PDoubleParameter("foo", this);
    QSignalSpy spy(param, &PDoubleParameter::valueChanged);

    param->setValue(1.0);
    int nbSignalEmitted = spy.count();
    QVERIFY(param->value() == 1.0);

    param->setValue(2.0);
    QVERIFY(param->value() == 2.0);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);

    param->setValue(2.0);
    QVERIFY(param->value() == 2.0);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);

    param->setValue(param->min());
    QVERIFY(param->value() == param->min());
    QCOMPARE(spy.count(), nbSignalEmitted + 2);

    param->setValue(param->min() - 1.0);
    QVERIFY(param->value() == param->min());
    QCOMPARE(spy.count(), nbSignalEmitted + 2);

    param->setValue(param->max() + 1.0);
    QVERIFY(param->value() == param->max());
    QCOMPARE(spy.count(), nbSignalEmitted + 3);
}

void PDoubleParameterTest::trigger()
{
    PDoubleParameter *param = new PDoubleParameter("foo", this);
    QSignalSpy spy(param, &PDoubleParameter::valueChanged);

    param->setValue(1.0);
    int nbSignalEmitted = spy.count();
    int paramValue = param->value();

    param->trigger();
    QVERIFY(param->value() == paramValue);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);
}

void PDoubleParameterTest::setRange()
{
    PDoubleParameter *param = new PDoubleParameter("foo", this);
    QSignalSpy spy(param, &PDoubleParameter::rangeChanged);
    int nbSignalEmitted = spy.count();

    int min = param->min();
    int max = param->max();

    param->setRange(min, max);
    QVERIFY(param->min() == min && param->max() == max);
    QVERIFY(spy.count() == nbSignalEmitted);

    param->setRange(max, min);
    QVERIFY(param->min() == min && param->max() == max);
    QVERIFY(spy.count() == nbSignalEmitted);

    param->setRange(min, max + 1.0);
    QVERIFY(param->min() == min && param->max() == max + 1.0);
    QVERIFY(spy.count() == nbSignalEmitted + 1);

    param->setRange(min - 1.0, max);
    QVERIFY(param->min() == min - 1.0 && param->max() == max);
    QVERIFY(spy.count() == nbSignalEmitted + 2.0);

    param->setRange(min - 1.0, max + 1.0);
    QVERIFY(param->min() == min - 1.0 && param->max() == max + 1.0);
    QVERIFY(spy.count() == nbSignalEmitted + 3);
}

QTEST_MAIN(PDoubleParameterTest)
