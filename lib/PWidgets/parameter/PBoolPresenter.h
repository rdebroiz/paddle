#pragma once

#include "PAbstractParameterPresenter.h"

#include <PBoolParameter.h>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>

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
    QPushButton* buildPushButton() const;
    QRadioButton* buildRadioButton() const;


public slots:
    void setCaptionVisibility(bool visibility);
    void setIcon(QIcon const& icon);

protected slots:
    void _dispatchCaption();
signals:
    void captionChanged(QString caption);
    void iconChange(QIcon icon);

protected:
    PBoolPresenter(PBoolPresenterPrivate &d, PBoolParameter *parent);

private:
    Q_DECLARE_PRIVATE(PBoolPresenter)
};
