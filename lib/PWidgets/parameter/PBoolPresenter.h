#pragma once

#include "PAbstractParameterPresenter.h"

#include <PBoolParameter.h>
#include <QCheckBox>

class PBoolPresenterPrivate;
class  PBoolPresenter : public PAbstractParameterPresenter
{
    Q_OBJECT

public:
    PBoolPresenter(PBoolParameter *parent);
    virtual ~PBoolPresenter();

    virtual PBoolParameter *parameter() const;

    virtual QWidget *buildWidget() const;
    QCheckBox *buildCheckBox() const;



protected:
    PBoolPresenter(PBoolPresenterPrivate &d, PBoolParameter *parent);

private:
    Q_DECLARE_PRIVATE(PBoolPresenter)
};
