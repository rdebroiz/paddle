#include "PBoolPresenter.h"
#include "PAbstractParameterPresenter_p.h"

class PBoolPresenterPrivate: public PAbstractParameterPresenterPrivate
{
public:
    PBoolParameter *parameter;

    PBoolPresenterPrivate(PBoolPresenter *q, PBoolParameter *p)
        : PAbstractParameterPresenterPrivate(q, p)
    {
        parameter = p;
    }

    void connectButton(QAbstractButton *button) const
    {
        QObject::connect(button, &QAbstractButton::toggled,
                         parameter, &PBoolParameter::setValue);

        QObject::connect(parameter, &PBoolParameter::valueChanged,
                         button, &QAbstractButton::setChecked);
    }
};

PBoolPresenter::PBoolPresenter(PBoolParameter *parent)
    : PAbstractParameterPresenter(*new PBoolPresenterPrivate(this, parent), parent)
{

}

PBoolPresenter::~PBoolPresenter()
{

}

PBoolParameter *PBoolPresenter::parameter() const
{
    Q_D(const PBoolPresenter);

    return d->parameter;
}

QWidget *PBoolPresenter::buildWidget() const
{
    return this->buildCheckBox();
}

QCheckBox *PBoolPresenter::buildCheckBox() const
{
    Q_D(const PBoolPresenter);

    QCheckBox *checkBox = new QCheckBox;
    checkBox->setChecked(d->parameter->value());
    d->connectButton(checkBox);

    checkBox->setToolTip(d->parameter->description());
    d->connectWiget(checkBox);

    checkBox->setText(this->parameter()->caption());
    connect(d->parameter, &PBoolParameter::captionChanged,
            checkBox, &QCheckBox::setText);

    return checkBox;
}

PBoolPresenter::PBoolPresenter(PBoolPresenterPrivate &d, PBoolParameter *parent)
    : PAbstractParameterPresenter(d, parent)
{

}
