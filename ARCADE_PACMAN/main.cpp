#include "arcade.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Arcade w;
    w.show();
    return a.exec();
}
