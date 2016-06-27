#include "PQtVtkGraphicsItem.h"

#include "PQtVtkInteractorAdapter.h"

#include <QVTKInteractor.h>

#include <QApplication>
#include <QGLWidget>
#include <QGLFramebufferObject>
#include <QGraphicsSceneEvent>

PQtVtkGraphicsItem::PQtVtkGraphicsItem(QGLContext* ctx, QGraphicsItem* p, QGLWidget* glWidget):
    QVTKGraphicsItem(ctx, p), mGlWidget(glWidget)
{
    this->moveToThread(QApplication::instance()->thread()); // should already be the case, no ?
    this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    mVtkViewIrenAdapter = new PQtVtkInteractorAdapter(this);
}

QImage PQtVtkGraphicsItem::toImage()
{
    QImage img;
    if(mFBO)
        img = mFBO->toImage();

    return img;
}

void PQtVtkGraphicsItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e)
{
    QPoint pi =  e->pos().toPoint();

    e->accept();
    QMouseEvent e2(QEvent::MouseButtonDblClick, pi, e->button(),
                   e->buttons(), e->modifiers());
    mVtkViewIrenAdapter->processDoubleClickEvent(&e2, mIren);
}
