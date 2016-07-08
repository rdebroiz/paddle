#include <QApplication>

#include <PBoolPresenter.h>
#include <PBoolGroup.h>
#include <PParameterPool.h>
#include <PIntPresenter.h>
#include <PDoublePresenter.h>


#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QUrl>


int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    QWidget widget;
    QVBoxLayout *mainLayout = new QVBoxLayout();
    widget.setLayout(mainLayout);

    QGroupBox *exclusiveWidget = new QGroupBox("Exclusive group");
    mainLayout->addWidget(exclusiveWidget);
    QHBoxLayout *exclusiveLayout = new QHBoxLayout();
    exclusiveWidget->setLayout(exclusiveLayout);

    PBoolParameter *param1 = new PBoolParameter("exclusive1", &widget);
    PBoolParameter *param2 = new PBoolParameter("exclusive2", &widget);
    PBoolParameter *param3 = new PBoolParameter("exclusive3", &widget);

    PBoolGroup *group = new PBoolGroup(&widget);
    group->addParameter(param1);
    group->addParameter(param2);
    group->addParameter(param3);

    PBoolPresenter *pres1 = new PBoolPresenter(param1);
    PBoolPresenter *pres2 = new PBoolPresenter(param2);
    PBoolPresenter *pres3 = new PBoolPresenter(param3);

    exclusiveLayout->addWidget(pres1->buildCheckBox());
    exclusiveLayout->addWidget(pres2->buildCheckBox());
    exclusiveLayout->addWidget(pres3->buildCheckBox());

    param1->setCaption("Parameter 1");
    param2->setCaption("Parameter 2");
    param3->setCaption("Parameter 3");

    QGroupBox *poolWidget = new QGroupBox("Pool of 6 boolean, 3 in a group and 3 other in another group");
    QGroupBox *exclusiveWidget1 = new QGroupBox("exclusive group 1");
    QGroupBox *exclusiveWidget2 = new QGroupBox("exclusive group 2");
    mainLayout->addWidget(poolWidget);
    QVBoxLayout *poolLayout = new QVBoxLayout();
    poolWidget->setLayout(poolLayout);
    poolLayout->addWidget(exclusiveWidget1);
    poolLayout->addWidget(exclusiveWidget2);

    QHBoxLayout *exclusiveLayout1 = new QHBoxLayout;
    QHBoxLayout *exclusiveLayout2 = new QHBoxLayout;

    exclusiveWidget1->setLayout(exclusiveLayout1);
    exclusiveWidget2->setLayout(exclusiveLayout2);

    PBoolParameter *param10 = new PBoolParameter("exclusive1_in_pool", &widget);
    PBoolParameter *param11 = new PBoolParameter("exclusive2_in_pool", &widget);
    PBoolParameter *param12 = new PBoolParameter("exclusive3_in_pool", &widget);

    PBoolParameter *param13 = new PBoolParameter("exclusive1_in_pool", &widget);
    PBoolParameter *param14 = new PBoolParameter("exclusive2_in_pool", &widget);
    PBoolParameter *param15 = new PBoolParameter("exclusive3_in_pool", &widget);

    PBoolGroup *group2 = new PBoolGroup(&widget);
    PBoolGroup *group3 = new PBoolGroup(&widget);

    group2->addParameter(param10);
    group2->addParameter(param11);
    group2->addParameter(param12);

    group3->addParameter(param13);
    group3->addParameter(param14);
    group3->addParameter(param15);

    PParameterPool * pool = new PParameterPool(&widget);

    pool->append(param10);
    pool->append(param11);
    pool->append(param12);
    pool->append(param13);
    pool->append(param14);
    pool->append(param15);

    PBoolPresenter *pres10 = new PBoolPresenter(param10);
    PBoolPresenter *pres11 = new PBoolPresenter(param11);
    PBoolPresenter *pres12 = new PBoolPresenter(param12);
    PBoolPresenter *pres13 = new PBoolPresenter(param13);
    PBoolPresenter *pres14 = new PBoolPresenter(param14);
    PBoolPresenter *pres15 = new PBoolPresenter(param15);

    pres14->setCaptionVisibility(false);
    pres15->setCaptionVisibility(false);
    pres15->setIcon(QIcon(":/icon/keyboardcat.jpg"));
    pres15->setIconSize(QSize(150, 150));

    exclusiveLayout1->addWidget(pres10->buildRadioButton());
    exclusiveLayout1->addWidget(pres11->buildRadioButton());
    exclusiveLayout1->addWidget(pres12->buildRadioButton());
    exclusiveLayout2->addWidget(pres13->buildPushButton());
    exclusiveLayout2->addWidget(pres14->buildPushButton());
    exclusiveLayout2->addWidget(pres15->buildPushButton());

    param10->setCaption("parameter 10");
    param11->setCaption("parameter 11");
    param12->setCaption("parameter 12");
    param13->setCaption("parameter 13");
    param14->setCaption("parameter 14");
    param15->setCaption("parameter 15");


    QCheckBox *c1 = new QCheckBox;
    QCheckBox *c2 = new QCheckBox;
    QCheckBox *c3 = new QCheckBox;

    QButtonGroup *b = new QButtonGroup;
    b->addButton(c1);
    b->addButton(c2);
    b->addButton(c3);

    QGroupBox *intWidget = new QGroupBox("Integer parameter");
    mainLayout->addWidget(intWidget);
    QHBoxLayout *intLayout = new QHBoxLayout;
    intWidget->setLayout(intLayout);

    PIntParameter *intParam = new PIntParameter("Integer Parameter", &widget);
    PIntPresenter *intPres = new PIntPresenter(intParam);

    intLayout->addWidget(intPres->buildSpinBox());
    intLayout->addWidget(intPres->buildProgressBar());
    intLayout->addWidget(intPres->buildSlider());


    QGroupBox *doubleWidget = new QGroupBox("Double parameter");
    mainLayout->addWidget(doubleWidget);
    QHBoxLayout *doubleLayout = new QHBoxLayout;
    doubleWidget->setLayout(doubleLayout);

    PDoubleParameter *doubleParam = new PDoubleParameter("Double Parameter", &widget);
    PDoublePresenter *doublePres = new PDoublePresenter(doubleParam);

    doubleLayout->addWidget(doublePres->buildSpinBox());
    doubleLayout->addWidget(doublePres->buildProgressBar());
    doubleLayout->addWidget(doublePres->buildSlider());
    doubleLayout->addWidget(doublePres->buildSlider());

    doubleParam->setRange(-10, 10);

    widget.show();

    return app.exec();
}

