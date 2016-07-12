#include "PVtkGraphicsView.h"

#include <QVTKGraphicsItem.h>

class PVtkGraphicsViewPrivate
{
public:
    Q_DISABLE_COPY(PVtkGraphicsViewPrivate)
    Q_DECLARE_PUBLIC(PVtkGraphicsView)

    PVtkGraphicsView *q_ptr;
    QVTKGraphicsItem *vtkItem;


    PVtkGraphicsViewPrivate(PVtkGraphicsView *q):
        q_ptr(q)
    {
        vtkItem = NULL;
    }

};

PVtkGraphicsView::PVtkGraphicsView(QWidget *parent):
    QGraphicsView(parent), d_ptr(new PVtkGraphicsViewPrivate(this))
{
    this->setAcceptDrops(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setCursor(QCursor(Qt::CrossCursor));
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}


PVtkGraphicsView::~PVtkGraphicsView()
{

}

void PVtkGraphicsView::resizeEvent(QResizeEvent *event)
{
    Q_D(PVtkGraphicsView);

    QGraphicsView::resizeEvent(event);
    if(d->vtkItem)
        d->vtkItem->resize(event->size());
}

void PVtkGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    QWidget::dragEnterEvent(event);
}

void PVtkGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    QWidget::dragMoveEvent(event);
}

void PVtkGraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
    QWidget::dragLeaveEvent(event);
}

void PVtkGraphicsView::dropEvent(QDropEvent *event)
{
    QWidget::dropEvent(event);
}

void PVtkGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    QWidget::mousePressEvent(event);
}

void PVtkGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    QWidget::mouseMoveEvent(event);
}

void PVtkGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    QWidget::mouseReleaseEvent(event);
}
