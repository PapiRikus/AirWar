#include <QApplication>
#include "LogginWindow.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogginWindow w;
    w.show();

    return a.exec();
}
