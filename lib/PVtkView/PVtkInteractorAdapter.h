#pragma once

#include <QVTKInteractorAdapter.h>

class PVtkInteractorAdapter: public QVTKInteractorAdapter
{
    Q_OBJECT

public:
    PVtkInteractorAdapter(QObject *parent = NULL);

    bool processDoubleClickEvent(QEvent* e, vtkRenderWindowInteractor* iren);
};
