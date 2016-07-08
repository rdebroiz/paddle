#include "PDoublePresenter.h"
#include "PAbstractParameterPresenter_p.h"

#include <QtDebug>

class PDoubleSpinBox : public QDoubleSpinBox
{
public:
    // Overloaded textFromValue, so we can what value we want in the combo box.
    virtual QString textFromValue(double value) const
    {
        return QString::number(value, 'g', 7);
    }
};

class PDoublePresenterPrivate: public PAbstractParameterPresenterPrivate
{
public:
    Q_DECLARE_PUBLIC(PDoublePresenter)

    PDoubleParameter *parameter;
    double singleStep;
    int decimals;
    int ival;

    PDoublePresenterPrivate(PDoublePresenter *q, PDoubleParameter *p)
        : PAbstractParameterPresenterPrivate(q, p)
    {
        parameter = p;
        singleStep = 0.01;
        decimals = 2;
        ival = this->valueToInt(parameter->value());
    }

    inline int valueToInt(double value) const
    {
        return static_cast<int>((value - parameter->min()) / singleStep);
    }

    inline double intToValue(int ival) const
    {        
        return static_cast<double>(ival) * singleStep + parameter->min();
    }
};

PDoublePresenter::PDoublePresenter(PDoubleParameter *parent)
    : PAbstractParameterPresenter(*new PDoublePresenterPrivate(this, parent), parent)
{
    Q_D(PDoublePresenter);

    QObject::connect(d->parameter, &PDoubleParameter::valueChanged,
                     this, &PDoublePresenter::_dispatchIval);
    QObject::connect(d->parameter, &PDoubleParameter::rangeChanged,
                     this, &PDoublePresenter::_dispatchIRange);
}

PDoublePresenter::~PDoublePresenter()
{

}

PDoubleParameter *PDoublePresenter::parameter() const
{
    Q_D(const PDoublePresenter);

    return d->parameter;
}

QWidget *PDoublePresenter::buildWidget() const
{
    return this->buildSpinBox();
}

QDoubleSpinBox *PDoublePresenter::buildSpinBox() const
{
    Q_D(const PDoublePresenter);

    QDoubleSpinBox *spinBox = new QDoubleSpinBox;

    spinBox->setValue(d->parameter->value());
    // static cast needed on the functor because it's overloaded
    // Q_SIGNALS: void valueChanged(int); void valueChanged(const QString &);
    connect(spinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            d->parameter, &PDoubleParameter::setValue);

    connect(d->parameter, &PDoubleParameter::valueChanged,
            spinBox, &PDoubleSpinBox::setValue);


    spinBox->setRange(d->parameter->min(), d->parameter->max());
    connect(d->parameter, &PDoubleParameter::rangeChanged,
            spinBox, &PDoubleSpinBox::setRange);

    spinBox->setSingleStep(d->singleStep);
    connect(this, &PDoublePresenter::singleStepChanged,
            spinBox, &PDoubleSpinBox::setSingleStep);

    spinBox->setDecimals(d->decimals);
    connect(this, &PDoublePresenter::decimalChanged,
            spinBox, &PDoubleSpinBox::setDecimals);

    d->connectWidget(spinBox);

    return spinBox;
}

QProgressBar *PDoublePresenter::buildProgressBar() const
{
    Q_D(const PDoublePresenter);

    QProgressBar *progressBar = new QProgressBar;
    d->connectWidget(progressBar);

    progressBar->setRange(0, d->valueToInt(d->parameter->max()));
    connect(this, &PDoublePresenter::iRangeChanged,
            progressBar, &QProgressBar::setMaximum);

    progressBar->setValue(d->valueToInt(d->parameter->value()));
    connect(this, &PDoublePresenter::iValChanged,
            progressBar, &QProgressBar::setValue);

    return progressBar;
}

QSlider *PDoublePresenter::buildSlider() const
{
    Q_D(const PDoublePresenter);

    QSlider *slider = new QSlider;
    d->connectWidget(slider);

    slider->setOrientation(Qt::Horizontal);
    slider->setTracking(true);

    slider->setRange(0, d->valueToInt(d->parameter->max()));
    connect(this, &PDoublePresenter::iRangeChanged,
            slider, &QSlider::setMaximum);

    slider->setValue(d->valueToInt(d->parameter->value()));
    connect(this, &PDoublePresenter::iValChanged,
            slider, &QSlider::setValue);

    connect(slider, &QSlider::valueChanged,
            this, &PDoublePresenter::_setValueFromInt);

    return slider;
}

void PDoublePresenter::setSingleStep(double step)
{
    Q_D(PDoublePresenter);

    if(step != d->singleStep)
    {
        d->singleStep = step;
        emit singleStepChanged(d->singleStep);
        // Recompute ranges and ival for sliders and progress bars:
        this->_dispatchIRange(d->parameter->min(), d->parameter->max());
    }
}

double PDoublePresenter::singleStep() const
{
    Q_D(const PDoublePresenter);

    return d->singleStep;
}

void PDoublePresenter::setDecimals(int precision)
{
    Q_D(PDoublePresenter);

    if(precision != d->decimals)
    {
        d->decimals = precision;
        emit decimalChanged(d->decimals);
    }
}

int PDoublePresenter::decimals() const
{
    Q_D(const PDoublePresenter);

    return d->decimals;
}

void PDoublePresenter::_setValueFromInt(int ival)
{
    Q_D(PDoublePresenter);

    // We need to check that ival actually changed.
    // This slots could have been called because of a slider update due to another slider's value change.
    // And result in an infinite signals/slots loop if there is no check.
    if(ival != d->ival)
    {
        d->ival = ival;
        d->parameter->setValue(d->intToValue(d->ival));
        emit iValChanged(d->ival);
    }
}

void PDoublePresenter::_dispatchIval(double value)
{
    Q_D(PDoublePresenter);

    // This slots is supposed to be called in only tow cases:
    // 1. The value of the parameter has changed.
    // 2. The range of the parameter has changed.
    // In both cases 'ival' will change, so no need to check for it here.
    d->ival = d->valueToInt(value);
    emit iValChanged(d->ival);
}

void PDoublePresenter::_dispatchIRange(double min, double max)
{
    Q_UNUSED(min);
    Q_D(PDoublePresenter);

    emit iRangeChanged(d->valueToInt(max));
    // Recompute eval for sliders and progress bars:
    this->_dispatchIval(d->parameter->value());
}


PDoublePresenter::PDoublePresenter(PDoublePresenterPrivate &d, PDoubleParameter *parent)
    : PAbstractParameterPresenter(d, parent)
{

}

