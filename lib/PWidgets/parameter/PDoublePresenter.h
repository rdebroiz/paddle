#pragma once

#include "PAbstractParameterPresenter.h"

#include <PDoubleParameter.h>

#include <QDoubleSpinBox>
#include <QProgressBar>
#include <QSlider>

class PDoublePresenterPrivate;
class PDoublePresenter: public PAbstractParameterPresenter
{
    Q_OBJECT

public:
    PDoublePresenter(PDoubleParameter *parent);
    virtual ~PDoublePresenter();

    virtual PDoubleParameter* parameter() const;

    virtual QWidget *buildWidget() const;
    QDoubleSpinBox *buildSpinBox() const;
    QProgressBar *buildProgressBar() const;
    QSlider *buildSlider() const;

    void setSingleStep(double step);
    double singleStep() const;

    void setDecimals(int precision);
    int decimals() const;

signals:
    void singleStepChanged(double step);
    void decimalChanged(int step);
    void iValChanged(int ival);
    void iRangeChanged(int imax);

protected slots:
    void _setValueFromInt(int ival);
    void _dispatchIval(double value);
    void _dispatchIRange(double min, double max);

protected:
    PDoublePresenter(PDoublePresenterPrivate &d, PDoubleParameter *parent);

private:
    Q_DECLARE_PRIVATE(PDoublePresenter)
};
