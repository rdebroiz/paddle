#include "PQtVtkGraphicsView.h"

#include <QVTKGraphicsItem.h>
#include <QGLWidget>

PQtVtkGraphicsView::PQtVtkGraphicsView(QWidget *parent):
    QGraphicsView(parent)
{
    this->setAcceptDrops(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setCursor(QCursor(Qt::CrossCursor));
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    mRenWin = vtkGenericOpenGLRenderWindow::New();
    mRenWin->SetAlphaBitPlanes(1);
    mRenWin->SetMultiSamples(8);

    QGLWidget *glWidget = new QGLWidget();
    this->setViewport(glWidget);

    mVtkItem = NULL;
}

PQtVtkGraphicsView::~PQtVtkGraphicsView()
{
}

void PQtVtkGraphicsView::setQVtkGraphicsItem(QVTKGraphicsItem *vtkItem)
{
    mVtkItem = vtkItem;
    mVtkItem->SetRenderWindow(mRenWin);
}

QVTKGraphicsItem* PQtVtkGraphicsView::qVtkGraphicsItem() const
{
    return mVtkItem;
}

void PQtVtkGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    if(mVtkItem)
        mVtkItem->resize(event->size());
}

void PQtVtkGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    QWidget::dragEnterEvent(event);
}

void PQtVtkGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    QWidget::dragMoveEvent(event);
}

void PQtVtkGraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
    QWidget::dragLeaveEvent(event);
}

void PQtVtkGraphicsView::dropEvent(QDropEvent *event)
{
    QWidget::dropEvent(event);
}

void PQtVtkGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    QWidget::mousePressEvent(event);
}

void PQtVtkGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    QWidget::mouseMoveEvent(event);
}

void PQtVtkGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    QWidget::mouseReleaseEvent(event);
}
