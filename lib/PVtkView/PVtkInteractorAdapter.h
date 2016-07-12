#pragma once

#include <QVTKInteractorAdapter.h>

class PVtkInteractorAdapter: public QVTKInteractorAdapter
{
public:
    PVtkInteractorAdapter(QObject *parent = NULL);

    bool processDoubleClickEvent(QEvent* e, vtkRenderWindowInteractor* iren);
};
