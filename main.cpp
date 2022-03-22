#include "mainwindow.h"
#include "gamewindow.h"
#include "GameRules.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameRules *gamerules;

    MainWindow w((void*)gamerules);
    w.show();
    return a.exec();
}
