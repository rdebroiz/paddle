#include "PMainWindow.h"

PMainWindow::PMainWindow(QWidget *parent)
{
    mSettings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "inria", "paddle", this);
    this->restoreGeometry(mSettings->value("pmainwindow/geometry").toByteArray());

    mQtVtkGraphicsView = new PQtVtkGraphicsView;
    this->setCentralWidget(mQtVtkGraphicsView);
}

PMainWindow::~PMainWindow()
{
}

void PMainWindow::closeEvent(QCloseEvent *event)
{
    mSettings->setValue("pmainwindow/geometry", this->saveGeometry());
}
