#pragma once

#include <QGraphicsView>

class QVTKGraphicsItem;

class PQtVtkGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    PQtVtkGraphicsView(QWidget * parent = NULL);
    virtual ~PQtVtkGraphicsView();

    void setQVtkGraphicsItem(QVTKGraphicsItem *vtkItem);
    QVTKGraphicsItem* qVtkGraphicsItem() const;


protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    QVTKGraphicsItem *m_vtkItem;

};
