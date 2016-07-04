#include "PStringParameterTest.h"

#include <QSignalSpy>

void PStringParameterTest::type()
{
    PStringParameter *param = new PStringParameter("foo", this);
    QCOMPARE(param->type(), PAbstractParameter::P_PARAMETER_STRING);
}

void PStringParameterTest::setValue()
{
    PStringParameter *param = new PStringParameter("foo", this);
    QSignalSpy spy(param, &PStringParameter::valueChanged);

    param->setValue("test");
    int nbSignalEmitted = spy.count();
    QVERIFY(param->value() == "test");

    param->setValue("other_test");
    QVERIFY(param->value() == "other_test");
    QCOMPARE(spy.count(), nbSignalEmitted + 1);

    param->setValue("other_test");
    QVERIFY(param->value() == "other_test");
    QCOMPARE(spy.count(), nbSignalEmitted + 1);
}

void PStringParameterTest::trigger()
{
    PStringParameter *param = new PStringParameter("foo", this);
    QSignalSpy spy(param, &PStringParameter::valueChanged);

    param->setValue("test");
    int nbSignalEmitted = spy.count();
    QString paramValue = param->value();

    param->trigger();
    QVERIFY(param->value() == paramValue);
    QCOMPARE(spy.count(), nbSignalEmitted + 1);
}

QTEST_MAIN(PStringParameterTest)
