#include "PParameterPoolTest.h"

#include "PStringParameter.h"


void PParameterPoolTest::appendString()
{
    PParameterPool *pool = new PParameterPool(this);

    PStringParameter * param1 = new PStringParameter("foo", this);
    PAbstractParameter * param2 = new PStringParameter("foo", this);
    PStringParameter * param3 = new PStringParameter("foo", this);
    PStringParameter * param4 = new PStringParameter("bar", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    QString str = "test";
    param1->setValue(str);

    QVERIFY(static_cast<PStringParameter *>(param2)->value() == str);
    QVERIFY(param3->value() == str);
    QVERIFY(param4->value() != str);
}

void PParameterPoolTest::appendBool()
{
    PParameterPool *pool = new PParameterPool(this);

    PBoolParameter * param1 = new PBoolParameter("foo", this);
    PAbstractParameter * param2 = new PBoolParameter("foo", this);
    PBoolParameter * param3 = new PBoolParameter("foo", this);
    PBoolParameter * param4 = new PBoolParameter("bar", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    bool val = !param1->value();
    param1->setValue(val);

    QVERIFY(static_cast<PBoolParameter *>(param2)->value() == val);
    QVERIFY(param3->value() == val);
    QVERIFY(param4->value() != val);
}

void PParameterPoolTest::appendInt()
{
    PParameterPool *pool = new PParameterPool(this);

    PIntParameter * param1 = new PIntParameter("foo", this);
    PAbstractParameter * param2 = new PIntParameter("foo", this);
    PIntParameter * param3 = new PIntParameter("foo", this);
    PIntParameter * param4 = new PIntParameter("bar", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    int val = param1->value() + 42;
    param1->setValue(val);

    QVERIFY(static_cast<PIntParameter *>(param2)->value() == val);
    QVERIFY(param3->value() == val);
    QVERIFY(param4->value() != val);
}

void PParameterPoolTest::appendDouble()
{
    PParameterPool *pool = new PParameterPool(this);

    PDoubleParameter * param1 = new PDoubleParameter("foo", this);
    PAbstractParameter * param2 = new PDoubleParameter("foo", this);
    PDoubleParameter * param3 = new PDoubleParameter("foo", this);
    PDoubleParameter * param4 = new PDoubleParameter("bar", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    double val = param1->value() + 42.0;
    param1->setValue(val);

    QVERIFY(static_cast<PDoubleParameter *>(param2)->value() == val);
    QVERIFY(param3->value() == val);
    QVERIFY(param4->value() != val);
}

void PParameterPoolTest::removeString()
{
    PParameterPool *pool = new PParameterPool(this);

    PStringParameter *param1 = new PStringParameter("foo", this);
    PAbstractParameter *param2 = new PStringParameter("foo", this);
    PStringParameter *param3 = new PStringParameter("foo", this);
    PStringParameter *param4 = new PStringParameter("foo", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    QString str = "test";
    param1->setValue(str);

    pool->remove(param2);
    pool->remove(param3);
    delete param4;

    static_cast<PStringParameter *>(param2)->setValue("param2");
    param3->setValue("param3");

    QVERIFY(param1->value() == "test");
    QVERIFY(static_cast<PStringParameter *>(param2)->value() == "param2");
    QVERIFY(param3->value() == "param3");
}

void PParameterPoolTest::removeBool()
{
    PParameterPool *pool = new PParameterPool(this);

    PBoolParameter *param1 = new PBoolParameter("foo", this);
    PAbstractParameter *param2 = new PBoolParameter("foo", this);
    PBoolParameter *param3 = new PBoolParameter("foo", this);
    PBoolParameter *param4 = new PBoolParameter("foo", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    bool val = !param1->value();
    param1->setValue(val);

    pool->remove(param2);
    pool->remove(param3);
    delete param4;

    static_cast<PBoolParameter *>(param2)->setValue(!val);
    param3->setValue(!val);

    QVERIFY(param1->value() == val);
    QVERIFY(static_cast<PBoolParameter *>(param2)->value() == !val);
    QVERIFY(param3->value() == !val);
}

void PParameterPoolTest::removeInt()
{
    PParameterPool *pool = new PParameterPool(this);

    PIntParameter *param1 = new PIntParameter("foo", this);
    PAbstractParameter *param2 = new PIntParameter("foo", this);
    PIntParameter *param3 = new PIntParameter("foo", this);
    PIntParameter *param4 = new PIntParameter("foo", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    int val = param1->value() + 42;
    param1->setValue(val);

    pool->remove(param2);
    pool->remove(param3);
    delete param4;

    static_cast<PIntParameter *>(param2)->setValue(val + 2);
    param3->setValue(val + 3);

    QVERIFY(param1->value() == val);
    QVERIFY(static_cast<PIntParameter *>(param2)->value() == val + 2);
    QVERIFY(param3->value() == val + 3);
}

void PParameterPoolTest::removeDouble()
{
    PParameterPool *pool = new PParameterPool(this);

    PDoubleParameter *param1 = new PDoubleParameter("foo", this);
    PAbstractParameter *param2 = new PDoubleParameter("foo", this);
    PDoubleParameter *param3 = new PDoubleParameter("foo", this);
    PDoubleParameter *param4 = new PDoubleParameter("foo", this);

    pool->append(param1);
    pool->append(param2);
    pool->append(param3);
    pool->append(param4);

    int val = param1->value() + 42.0;
    param1->setValue(val);

    pool->remove(param2);
    pool->remove(param3);
    delete param4;

    static_cast<PDoubleParameter *>(param2)->setValue(val + 2.0);
    param3->setValue(val + 3);

    QVERIFY(param1->value() == val);
    QVERIFY(static_cast<PDoubleParameter *>(param2)->value() == val + 2.0);
    QVERIFY(param3->value() == val + 3.0);
}

QTEST_MAIN(PParameterPoolTest)
