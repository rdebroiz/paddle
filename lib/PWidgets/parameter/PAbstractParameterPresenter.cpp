#include "PAbstractParameterPresenter.h"
#include "PAbstractParameterPresenter_p.h"

#include <PAbstractParameter.h>

PAbstractParameterPresenterPrivate::PAbstractParameterPresenterPrivate(PAbstractParameterPresenter *q, PAbstractParameter *p)
    : q_ptr(q), parameter(p)
{
    visibility = true;
    isEnable = true;
}

void PAbstractParameterPresenterPrivate::connectWiget(QWidget *widget) const
{
    Q_Q(const PAbstractParameterPresenter);

    QObject::connect(parameter, &PAbstractParameter::descriptionChanged,
                     widget, &QWidget::setToolTip);

    QObject::connect(q, &PAbstractParameterPresenter::visibilityChanged,
                     widget, &QWidget::setVisible);

    QObject::connect(q, &PAbstractParameterPresenter::isEnabledChanged,
                     widget, &QWidget::setEnabled);
}

PAbstractParameterPresenter::PAbstractParameterPresenter(PAbstractParameter *parent)
    : QObject(parent), d_ptr(new PAbstractParameterPresenterPrivate(this, parent))
{

}


void PAbstractParameterPresenter::setVisible(bool visibility)
{
    Q_D(PAbstractParameterPresenter);

    if(visibility != d->visibility)
    {
        d->visibility = visibility;
        emit visibilityChanged(d->visibility);
    }
}

bool PAbstractParameterPresenter::isVisible() const
{
    Q_D(const PAbstractParameterPresenter);

    return d->visibility;
}

void PAbstractParameterPresenter::setEnable(bool enabled)
{
    Q_D(PAbstractParameterPresenter);

    if(enabled != d->isEnable)
    {
        d->isEnable = enabled;
        emit isEnabledChanged(d->isEnable);
    }
}

bool PAbstractParameterPresenter::isEnable() const
{
    Q_D(const PAbstractParameterPresenter);

    return d->isEnable;
}

PAbstractParameterPresenter::PAbstractParameterPresenter(PAbstractParameterPresenterPrivate &d, PAbstractParameter* parent)
    :QObject(parent), d_ptr(&d)
{

}

