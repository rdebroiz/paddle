#include "PBoolGroupTest.h"

void PBoolGroupTest::addParameterTest()
{
    //------------------------------------------------------------------------------
    // Test initial list.
    //------------------------------------------------------------------------------
    PBoolGroup *group = new PBoolGroup(this);
    QVERIFY2(group->parameters().size() == 0
             , "Test initial list.");


    //------------------------------------------------------------------------------
    // Test list after adding one parameter.
    //------------------------------------------------------------------------------
    PBoolParameter *param = new PBoolParameter("foo", this);
    group->addParameter(param);
    QVERIFY2(group->parameters().size() == 1
             , "Test list after adding one parameter.");
    QVERIFY2(group->parameters().contains(param)
             , "Test list after adding one parameter.");


    //------------------------------------------------------------------------------
    // Test list after adding one parameter twice.
    //------------------------------------------------------------------------------
    group->addParameter(param);
    QVERIFY2(group->parameters().size() == 1
             , "Test list after adding one parameter twice.");
    QVERIFY2(group->parameters().contains(param)
             , "Test list after adding one parameter twice.");


    //------------------------------------------------------------------------------
    // Test list after adding two parameters.
    //------------------------------------------------------------------------------
    PBoolParameter *param2 = new PBoolParameter("foo", this);
    group->addParameter(param2);
    QVERIFY2(group->parameters().size() == 2
             , "Test list after adding two parameters.");
    QVERIFY2(group->parameters().contains(param)
             , "Test list after adding two parameters.");
    QVERIFY2(group->parameters().contains(param2)
             , "Test list after adding two parameters.");
}

void PBoolGroupTest::removeParameterTest()
{

    //------------------------------------------------------------------------------
    // Test list after removing one parameter.
    //------------------------------------------------------------------------------
    PBoolGroup *group = new PBoolGroup(this);
    PBoolParameter *param = new PBoolParameter("foo", this);
    group->addParameter(param);
    group->removeParameter(param);
    QVERIFY2(group->parameters().size() == 0
             , "Test list after removing one parameter.");
    QVERIFY2(!group->parameters().contains(param)
             , "Test list after removing one parameter.");


    //------------------------------------------------------------------------------
    // Test list after removing one parameter not owned by the group.
    //------------------------------------------------------------------------------
    group->addParameter(param);
    PBoolParameter *param2 = new PBoolParameter("foo", this);
    group->removeParameter(param2);
    QVERIFY2(group->parameters().size() == 1
             , "Test list after removing one parameter not owned by the group.");
    QVERIFY2(group->parameters().contains(param)
             , "Test list after removing one parameter not owned by the group.");
}

void PBoolGroupTest::trueParameterTest()
{
    //------------------------------------------------------------------------------
    // Test trueParameter at initial state.
    //------------------------------------------------------------------------------
    PBoolGroup *group = new PBoolGroup(this);
    QVERIFY2(group->trueParameter() == NULL
             , "Test trueParameter at initial state.");


    //------------------------------------------------------------------------------
    // Test trueParameter after adding one parameter.
    //------------------------------------------------------------------------------
    PBoolParameter *param = new PBoolParameter("foo", this);
    param->setValue(false);
    group->addParameter(param);
    QVERIFY2(group->trueParameter() == param
             , "Test trueParameter after adding one parameter.");
    QVERIFY2(param->value() == true
             , "Test trueParameter after adding one parameter.");


    //------------------------------------------------------------------------------
    // Test trueParameter after adding one parameter with 'false' value.
    //------------------------------------------------------------------------------
    PBoolParameter *param2 = new PBoolParameter("foo", this);
    param2->setValue(false);
    group->addParameter(param2);
    QVERIFY2(group->trueParameter() == param
             , "Test trueParameter after adding one parameter with 'false' value.");
    QVERIFY2(param->value() == true
             , "Test trueParameter after adding one parameter with 'false' value.");
    QVERIFY2(param2->value() == false
             , "Test trueParameter after adding one parameter with 'false' value.");


    //------------------------------------------------------------------------------
    // Test trueParameter after adding one parameter with 'true' value.
    //------------------------------------------------------------------------------
    PBoolParameter *param3 = new PBoolParameter("foo", this);
    param3->setValue(true);
    group->addParameter(param3);
    QVERIFY2(group->trueParameter() == param3
             , "Test trueParameter after adding one parameter with 'true' value.");
    QVERIFY2(param3->value() == true
             , "Test trueParameter after adding one parameter with 'true' value.");
    QVERIFY2(param->value() == false
             , "Test trueParameter after adding one parameter with 'true' value.");
    QVERIFY2(param2->value() == false
             , "Test trueParameter after adding one parameter with 'true' value.");


    //------------------------------------------------------------------------------
    // Test trueParameter after changing value of param2.
    //------------------------------------------------------------------------------
    param2->setValue(true);
    QVERIFY2(group->trueParameter() == param2
             , "Test trueParameter after changing value of param2.");
    QVERIFY2(param2->value() == true
             , "Test trueParameter after changing value of param2.");
    QVERIFY2(param->value() == false
             , "Test trueParameter after changing value of param2.");
    QVERIFY2(param3->value() == false
             , "Test trueParameter after changing value of param2.");


    //------------------------------------------------------------------------------
    // Test trueParameter after removing the previsous one.
    //------------------------------------------------------------------------------
    group->removeParameter(param2);
    QVERIFY2(group->trueParameter() != param2
             , "Test trueParameter after removing the previsous one.");
    QVERIFY2(group->trueParameter() != NULL
             , "Test trueParameter after removing the previsous one.");
    QVERIFY2(group->parameters().contains(group->trueParameter())
             , "Test trueParameter after removing the previsous one.");
    QVERIFY2(group->trueParameter()->value() == true
             , "Test trueParameter after removing the previsous one.");


    //------------------------------------------------------------------------------
    // Test trueParameter after removing all parameeters.
    //------------------------------------------------------------------------------
    group->removeParameter(param);
    group->removeParameter(param3);
    QVERIFY2(group->trueParameter() == NULL
             , "Test trueParameter after removing all parameeters.");

}

void PBoolGroupTest::noParameterinMultipleGroup()
{
    PBoolGroup *group1 = new PBoolGroup(this);
    PBoolGroup *group2 = new PBoolGroup(this);
    PBoolParameter *param = new PBoolParameter("foo", this);
    group1->addParameter(param);
    group2->addParameter(param);
    QVERIFY(!group1->parameters().contains(param));
    QVERIFY(group2->parameters().contains(param));
}

QTEST_MAIN(PBoolGroupTest)
