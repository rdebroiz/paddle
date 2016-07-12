#pragma once

#include <QVTKGraphicsItem.h>

#include "PVtkInteractorAdapter.h"

#include <QGLWidget>
#include <QGLContext>

class PVtkGraphicsItem: public QVTKGraphicsItem
{
    Q_OBJECT
public:
    PVtkInteractorAdapter *mVtkViewIrenAdapter;
    QGLWidget *mGlWidget;

    PVtkGraphicsItem(QGLContext* ctx, QGraphicsItem* parent = NULL, QGLWidget* glWidget = NULL);
    QImage toImage();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e);

};
