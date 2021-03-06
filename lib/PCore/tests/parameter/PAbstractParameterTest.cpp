#include "PAbstractParameterTest.h"

#include <QSignalSpy>

void PAbstractParameterTest::match_data()
{
    QTest::addColumn<PAbstractParameter *>("parameter");
    QTest::addColumn<PAbstractParameter *>("otherParameter");
    QTest::addColumn<bool>("match");

    PAbstractParameter *param, *otherParam;

    param = new PAbstractParameterMoc("foo", this); otherParam =  new PAbstractParameterMoc("foo", this);
    QTest::newRow("string ==, type ==") << param << otherParam << true;
    param = new PAbstractParameterMoc("foo", this); otherParam =  new PAbstractParameterMoc2("foo", this);
    QTest::newRow("string ==, type !=") << param << otherParam << false;
    param = new PAbstractParameterMoc("foo", this); otherParam =  new PAbstractParameterMoc2("bar", this);
    QTest::newRow("string !=, type ==") << param << otherParam << false;
    param = new PAbstractParameterMoc("foo", this); otherParam =  new PAbstractParameterMoc2("bar", this);
    QTest::newRow("string !=, type !=") << param << otherParam << false;
    param = new PAbstractParameterMoc("foo", this); otherParam =  NULL;
    QTest::newRow("other is NULL") << param << otherParam << false;
}

void PAbstractParameterTest::match()
{
    QFETCH(PAbstractParameter*, parameter);
    QFETCH(PAbstractParameter*, otherParameter);
    QFETCH(bool, match);

    QVERIFY(parameter->match(otherParameter) ==  match);
}

void PAbstractParameterTest::descriptionChanged()
{
    PAbstractParameter *param = new PAbstractParameterMoc("foo", this);
    QSignalSpy spy(param, &PAbstractParameter::descriptionChanged);

    param->setDescription("description");
    QCOMPARE(spy.count(), 1);

    param->setDescription("description");
    QCOMPARE(spy.count(), 1);

    param->setDescription("other description");
    QCOMPARE(spy.count(), 2);
}

void PAbstractParameterTest::captionChanged()
{
    PAbstractParameter *param = new PAbstractParameterMoc("foo", this);
    QSignalSpy spy(param, &PAbstractParameter::captionChanged);

    param->setCaption("caption");
    QCOMPARE(spy.count(), 1);

    param->setCaption("caption");
    QCOMPARE(spy.count(), 1);

    param->setCaption("other caption");
    QCOMPARE(spy.count(), 2);
}

QTEST_MAIN(PAbstractParameterTest)
