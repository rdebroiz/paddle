#include "PVtkGraphicsView.h"

#include <PVtkGraphicsItem.h>

class PVtkGraphicsViewPrivate
{
public:
    Q_DISABLE_COPY(PVtkGraphicsViewPrivate)
    Q_DECLARE_PUBLIC(PVtkGraphicsView)

    PVtkGraphicsView *q_ptr;
    PVtkGraphicsItem *item;


    PVtkGraphicsViewPrivate(PVtkGraphicsView *q):
        q_ptr(q)
    {
        item = NULL;
    }

};

PVtkGraphicsView::PVtkGraphicsView(QWidget *parent):
    QGraphicsView(parent), d_ptr(new PVtkGraphicsViewPrivate(this))
{
    Q_D(PVtkGraphicsView);

    this->setAcceptDrops(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setCursor(QCursor(Qt::CrossCursor));
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    QGLWidget *viewPort = new QGLWidget;
    this->setViewport(viewPort);

    d->item = new PVtkGraphicsItem(const_cast<QGLContext*>(viewPort->context()), NULL, viewPort);
    QGraphicsScene *scene = new QGraphicsScene;
    this->setScene(scene);
    scene->addItem(d->item);

//    // Don'yt ask me why, this is necessary ... - RDE
//    d->item->resize(this->size())
}


PVtkGraphicsView::~PVtkGraphicsView()
{

}

PVtkGraphicsItem *PVtkGraphicsView::item() const
{
    Q_D(const PVtkGraphicsView);

    return d->item;
}

void PVtkGraphicsView::resizeEvent(QResizeEvent *event)
{
    Q_D(PVtkGraphicsView);

    QGraphicsView::resizeEvent(event);
    if(d->item)
        d->item->resize(event->size());
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
