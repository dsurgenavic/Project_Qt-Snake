#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include "GameRules.h"

enum direction{
    UP, DOWN, LEFT, RIGHT
};

struct Snake {
    int headx;
    int heady;
    enum direction head_dir;
    int length;
};

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = nullptr);
    GameWindow(GameRules* gamerules);
    ~GameWindow();

    GameRules gamerules;

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

signals:

};

#endif // GAMEWINDOW_H
