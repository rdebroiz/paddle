#pragma once

#include <QVTKGraphicsItem.h>

class QGLWidget;

class PQtVtkInteractorAdapter;

class  PQtVtkGraphicsItem : public QVTKGraphicsItem
{
public:
    PQtVtkInteractorAdapter* mVtkViewIrenAdapter;
    QGLWidget *mGlWidget;

public:
    PQtVtkGraphicsItem(QGLContext* ctx, QGraphicsItem* p = 0, QGLWidget* glWidget = 0);
    QImage toImage();

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e);
};
