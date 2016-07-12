#pragma once

#include <QGraphicsView>

#include <vtkObject.h>
#include <vtkRenderWindow.h>

class PVtkGraphicsViewPrivate;
class PVtkGraphicsView: public QGraphicsView
{
    Q_OBJECT
public:
    PVtkGraphicsView(QWidget *parent = NULL);
    virtual ~PVtkGraphicsView();

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

protected:
    QScopedPointer<PVtkGraphicsViewPrivate> const d_ptr;

private:
    Q_DECLARE_PRIVATE(PVtkGraphicsView)
};
