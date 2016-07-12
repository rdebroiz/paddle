#include "PVtkGraphicsItem.h"

#include <QApplication>
#include <QGLFramebufferObject>
#include <QGraphicsSceneMouseEvent>

#include <QVTKInteractor.h>


PVtkGraphicsItem::PVtkGraphicsItem(QGLContext* ctx, QGraphicsItem* parent, QGLWidget* glWidget)
    :QVTKGraphicsItem(ctx, parent), mGlWidget(glWidget)
{
    this->moveToThread(QApplication::instance()->thread());
    this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    mVtkViewIrenAdapter = new PVtkInteractorAdapter(this);
}

QImage PVtkGraphicsItem::toImage()
{
    QImage img;
    if(mFBO)
        img = mFBO->toImage();

    return img;
}

void PVtkGraphicsItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e)
{
    QPointF pf = e->pos();
    QPoint pi = pf.toPoint();

    e->accept();
    QMouseEvent e2(QEvent::MouseButtonDblClick, pi, e->button(),
        e->buttons(), e->modifiers());
    mVtkViewIrenAdapter->processDoubleClickEvent(&e2, mIren);
}
