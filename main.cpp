#include "tabwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TabWidget t;

    t.show();
    return a.exec();
}
