#pragma once

#include <QVTKInteractorAdapter.h>

class PQtVtkInteractorAdapter : public QVTKInteractorAdapter
{
public:
    PQtVtkInteractorAdapter(QObject *parent = NULL): QVTKInteractorAdapter(parent)
    {

    }

    bool processDoubleClickEvent(QEvent* e, vtkRenderWindowInteractor* iren);
};
