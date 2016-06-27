#include <PQtVtkInteractorAdapter.h>

#include <QMouseEvent>

#include <vtkCommand.h>
#include <vtkRenderWindowInteractor.h>

bool PQtVtkInteractorAdapter::processDoubleClickEvent(QEvent* e, vtkRenderWindowInteractor* iren)
{
    bool exit = true;

    if(iren == NULL || e == NULL || e->type() != QEvent::MouseButtonDblClick)
    {
        exit = false;
    }
    else
    {
        QMouseEvent *e2 = static_cast<QMouseEvent *>(e);
        iren->SetEventInformationFlipY(e2->x(), e2->y()
                                       , (e2->modifiers() & Qt::ControlModifier) > 0 ? 1 : 0
                                       , (e2->modifiers() & Qt::ShiftModifier ) > 0 ? 1 : 0
                                       , 1, 1);
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
    }
    return exit;
}
