#include <QApplication>

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    QWidget w;
    QVBoxLayout l(&w);

    QCheckBox b1;
    QCheckBox b2;
    QCheckBox b3;
    QCheckBox b4;

    QSlider s;

    b2.setChecked(true);

    l.addWidget(&b1);
    l.addWidget(&b2);
    l.addWidget(&b3);
    l.addWidget(&b4);
    l.addWidget(&s);

    s.setRange(18, 5);
    qDebug() << s.minimum();
    qDebug() << s.maximum();

    QButtonGroup g1;
    QButtonGroup g2;

    g1.addButton(&b1);
    g1.addButton(&b2);
    g1.addButton(&b3);

    g2.addButton(&b1);
    g2.addButton(&b4);

    w.show();

    return app.exec();
}
