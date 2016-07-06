#include "PBoolPresenter.h"
#include "PAbstractParameterPresenter_p.h"

class PBoolPresenterPrivate: public PAbstractParameterPresenterPrivate
{
public:
    Q_DECLARE_PUBLIC(PBoolPresenter)

    PBoolParameter *parameter;
    bool captionVisibility;
    QIcon icon;
    QSize iconSize;

    PBoolPresenterPrivate(PBoolPresenter *q, PBoolParameter *p)
        : PAbstractParameterPresenterPrivate(q, p)
    {
        parameter = p;
        captionVisibility = true;
    }

    void connectButton(QAbstractButton *button) const
    {
        Q_Q(const PBoolPresenter);

        button->setCheckable(true);
        button->setChecked(parameter->value());

        // duplicate _dispatchCaption to preserve constness
        if(captionVisibility)
            button->setText(parameter->caption());
        else
            button->setText("");

        button->setIcon(icon);
        button->setIconSize(iconSize);

        QObject::connect(button, &QAbstractButton::toggled,
                         parameter, &PBoolParameter::setValue);

        QObject::connect(parameter, &PBoolParameter::valueChanged,
                         button, &QAbstractButton::setChecked);

        QObject::connect(parameter, &PBoolParameter::captionChanged,
                         q, &PBoolPresenter::_dispatchCaption);

        QObject::connect(q, &PBoolPresenter::captionChanged,
                         button, &QAbstractButton::setText);

        QObject::connect(q, &PBoolPresenter::iconChange,
                         button, &QAbstractButton::setIcon);

        QObject::connect(q, &PBoolPresenter::iconSizeChange,
                         button, &QAbstractButton::setIconSize);

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

    d->connectButton(checkBox);
    d->connectWiget(checkBox);

    return checkBox;
}

QPushButton *PBoolPresenter::buildPushButton() const
{
    Q_D(const PBoolPresenter);

    QPushButton *button = new QPushButton();
    d->connectButton(button);
    d->connectWiget(button);

    return button;
}

QRadioButton *PBoolPresenter::buildRadioButton() const
{
    Q_D(const PBoolPresenter);

    QRadioButton *button = new QRadioButton();
    d->connectButton(button);
    d->connectWiget(button);

    return button;
}

void PBoolPresenter::setCaptionVisibility(bool visibility)
{
    Q_D(PBoolPresenter);

    if(visibility != d->captionVisibility)
    {
        d->captionVisibility = visibility;
       this->_dispatchCaption();
    }
}

void PBoolPresenter::setIcon(const QIcon &icon)
{
    Q_D(PBoolPresenter);

    d->icon = icon;
    emit iconChange(d->icon);
}

void PBoolPresenter::setIconSize(const QSize &size)
{
    Q_D(PBoolPresenter);

    if(d->iconSize != size)
    {
        d->iconSize = size;
        emit iconSizeChange(d->iconSize);
    }
}

void PBoolPresenter::_dispatchCaption()
{
    Q_D(const PBoolPresenter);

    if(d->captionVisibility)
        emit captionChanged(d->parameter->caption());
    else
        emit captionChanged("");
}

PBoolPresenter::PBoolPresenter(PBoolPresenterPrivate &d, PBoolParameter *parent)
    : PAbstractParameterPresenter(d, parent)
{

}
