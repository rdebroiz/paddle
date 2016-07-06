#pragma once

#include <QWidget>

class PAbstractParameter;
class PAbstractParameterPresenterPrivate;
class PAbstractParameterPresenter : public QObject
{
    Q_OBJECT

public:
    PAbstractParameterPresenter(PAbstractParameter *parent);
    virtual ~PAbstractParameterPresenter();

    virtual QWidget *buildWidget() const = 0;
    virtual PAbstractParameter *parameter() const = 0;

    void setVisible(bool visibility);
    bool isVisible() const;
    void setEnable(bool enabled);
    bool isEnable() const;

signals:
    void visibilityChanged(bool);
    void isEnabledChanged(bool);

protected:
    PAbstractParameterPresenter(PAbstractParameterPresenterPrivate &d, PAbstractParameter *parent);
    const QScopedPointer<PAbstractParameterPresenterPrivate> d_ptr;
private:
    Q_DECLARE_PRIVATE(PAbstractParameterPresenter)
};

