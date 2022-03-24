#include "mainwindow.h"
#include "gamewindow.h"
#include "GameRules.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameRules *gamerules = new GameRules;
    gamerules->gameSpeed = NORMAL;
    gamerules->multiplayer = false;

    MainWindow w(gamerules);
    w.show();

    return a.exec();
}
