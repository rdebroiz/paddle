#pragma once

#include <QMainWindow>
#include <QSettings>

#include <vtkImageData.h>

#include <PVtkView.h>

class MainWindow: public QMainWindow
{
    Q_OBJECT

private:
    PVtkView *m_view;
    QSettings *m_settings;


public:
    MainWindow(QWidget *parent = NULL);
    virtual ~MainWindow();

    void openImage();

protected:
    static vtkImageData* vtkitkToVtkImage(QString const& filename);

    virtual void closeEvent(QCloseEvent *event);

};
