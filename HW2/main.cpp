#include "viewingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewingWindow w;
    w.show();

    return a.exec();
}
