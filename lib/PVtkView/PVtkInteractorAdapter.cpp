#include "PVtkInteractorAdapter.h"

#include <QMouseEvent>

#include <vtkRenderWindowInteractor.h>
#include <vtkCommand.h>

PVtkInteractorAdapter::PVtkInteractorAdapter(QObject* parent):
    QVTKInteractorAdapter(parent)
{

}

bool PVtkInteractorAdapter::processDoubleClickEvent(QEvent* e, vtkRenderWindowInteractor* iren)
{
    if(iren == NULL || e == NULL || e->type() != QEvent::MouseButtonDblClick)
      return false;

    QMouseEvent *e2 = static_cast<QMouseEvent *>(e);
    iren->SetEventInformationFlipY(e2->x(), e2->y(),
                                (e2->modifiers() & Qt::ControlModifier) > 0 ? 1 : 0,
                                (e2->modifiers() & Qt::ShiftModifier ) > 0 ? 1 : 0,
                                1,
                                1);
    switch(e2->button())
    {
        case Qt::LeftButton:
        iren->InvokeEvent(vtkCommand::LeftButtonPressEvent, e2);
        break;

        case Qt::MidButton:
        iren->InvokeEvent(vtkCommand::MiddleButtonPressEvent, e2);
        break;

        case Qt::RightButton:
        iren->InvokeEvent(vtkCommand::RightButtonPressEvent, e2);
        break;

        default:
        break;
    }
    return true;
}
