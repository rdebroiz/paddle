#pragma once

#include "PAbstractParameterPresenter.h"

class PAbstractParameterPresenterPrivate
{
public:
    Q_DISABLE_COPY(PAbstractParameterPresenterPrivate)
    Q_DECLARE_PUBLIC(PAbstractParameterPresenter)
    // Constructor that initializes the q-ptr
    PAbstractParameterPresenterPrivate(PAbstractParameterPresenter *q, PAbstractParameter *parameter);
    PAbstractParameterPresenter *q_ptr; // q-ptr points to the API class

    bool visibility;
    bool isEnable;
    PAbstractParameter *parameter;

    void connectWiget(QWidget *widget) const;
};
