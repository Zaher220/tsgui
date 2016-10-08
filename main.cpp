#define NOMINMAX
#include "mainwindow.h"
#include "datatypes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<parameters>("parameters");
    MainWindow w;
    w.showMaximized();

    return a.exec();
}
