#pragma once

#include "PAbstractParameterPresenter.h"

#include <PIntParameter.h>

#include <QSpinBox>
#include <QProgressBar>
#include <QSlider>

class PIntPresenterPrivate;
class PIntPresenter: public PAbstractParameterPresenter
{
    Q_OBJECT

public:
    PIntPresenter(PIntParameter *parent);
    virtual ~PIntPresenter();

    virtual PIntParameter* parameter() const;

    virtual QWidget *buildWidget() const;
    QSpinBox *buildSpinBox() const;
    QProgressBar *buildProgressBar() const;
    QSlider *buildSlider() const;

    void setSingleStep(int step);
    int singleStep() const;

signals:
    void singleStepChanged(int step);

protected:
    PIntPresenter(PIntPresenterPrivate &d, PIntParameter *parent);

private:
    Q_DECLARE_PRIVATE(PIntPresenter)
};
