#pragma once

#include <QWidget>

#include <vtkImageData.h>

class PVtkViewPrivate;
class PVtkView: public QWidget
{
    Q_OBJECT

public:
    PVtkView(QWidget *parent = NULL);
    virtual ~PVtkView();

    void addData(vtkImageData *data);

protected:
    QScopedPointer<PVtkViewPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(PVtkView)

};
