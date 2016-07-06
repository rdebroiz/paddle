#include "PIntPresenter.h"
#include "PAbstractParameterPresenter_p.h"

class PIntPresenterPrivate: public PAbstractParameterPresenterPrivate
{
public:
    Q_DECLARE_PUBLIC(PIntPresenter)

    PIntParameter *parameter;
    int singleStep;

    PIntPresenterPrivate(PIntPresenter *q, PIntParameter *p)
        : PAbstractParameterPresenterPrivate(q, p)
    {
        parameter = p;
        singleStep = 1;
    }

};

PIntPresenter::PIntPresenter(PIntParameter *parent)
    : PAbstractParameterPresenter (*new PIntPresenterPrivate(this, parent), parent)
{

}

PIntPresenter::~PIntPresenter()
{

}

PIntParameter *PIntPresenter::parameter() const
{
    Q_D(const PIntPresenter);

    return d->parameter;
}

QWidget *PIntPresenter::buildWidget() const
{
    return this->buildSpinBox();
}

QSpinBox *PIntPresenter::buildSpinBox() const
{
    Q_D(const PIntPresenter);

    QSpinBox *spinBox = new QSpinBox;

    spinBox->setValue(d->parameter->value());
    // static cast needed on the functor beacause it's overloaded
    // Q_SIGNALS: void valueChanged(int); void valueChanged(const QString &);
    connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            d->parameter, &PIntParameter::setValue);

    connect(d->parameter, &PIntParameter::valueChanged,
            spinBox, &QSpinBox::setValue);


    spinBox->setRange(d->parameter->min(), d->parameter->max());
    connect(d->parameter, &PIntParameter::rangeChanged,
            spinBox, &QSpinBox::setRange);

    spinBox->setSingleStep(d->singleStep);
    connect(this, &PIntPresenter::singleStepChanged,
            spinBox, &QSpinBox::setSingleStep);

    d->connectWidget(spinBox);

    return spinBox;
}

QProgressBar *PIntPresenter::buildProgressBar() const
{
    Q_D(const PIntPresenter);

    QProgressBar *progressBar = new QProgressBar;
    progressBar->setValue(d->parameter->value());
    connect(d->parameter, &PIntParameter::valueChanged,
            progressBar, &QProgressBar::setValue);

    progressBar->setToolTip(d->parameter->description());
    d->connectWidget(progressBar);

    progressBar->setRange(d->parameter->min(), d->parameter->max());
    connect(d->parameter, &PIntParameter::rangeChanged,
            progressBar, &QProgressBar::setRange);

    return progressBar;
}

QSlider *PIntPresenter::buildSlider() const
{
    Q_D(const PIntPresenter);

    QSlider *slider = new QSlider;
    slider->setOrientation(Qt::Horizontal);
    slider->setTracking(true);

    slider->setValue(d->parameter->value());
    connect(slider, &QSlider::valueChanged,
            d->parameter, &PIntParameter::setValue);

    connect(d->parameter, &PIntParameter::valueChanged,
            slider, &QSlider::setValue);

    slider->setToolTip(d->parameter->description());
    d->connectWidget(slider);

    slider->setRange(d->parameter->min(), d->parameter->max());
    connect(d->parameter, &PIntParameter::rangeChanged,
            slider, &QSlider::setRange);

    return slider;
}

void PIntPresenter::setSingleStep(int step)
{
    Q_D(PIntPresenter);

    if(step != d->singleStep)
    {
        d->singleStep = step;
        emit singleStepChanged(d->singleStep);
    }
}

int PIntPresenter::singleStep() const
{
    Q_D(const PIntPresenter);

    return d->singleStep;
}

PIntPresenter::PIntPresenter(PIntPresenterPrivate &d, PIntParameter *parent)
    : PAbstractParameterPresenter(d, parent)
{

}


