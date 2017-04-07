#include <QApplication>
#include "LogginWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogginWindow w;
    w.show();

    return a.exec();
}
