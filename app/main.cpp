#include <QApplication>

#include "PMainWindow.h"


int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    PMainWindow *mainWindow = new PMainWindow;
    mainWindow->show();

    return app.exec();
}
