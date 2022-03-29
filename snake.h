#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QPainter>
#include <QTime>
#include "GameRules.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Snake; }
QT_END_NAMESPACE

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    Snake(GameRules *gamerules, QWidget *parent = nullptr);
    ~Snake();
    void StartGame();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    Ui::Snake *ui;
    static const int B_WIDTH = 800;
    static const int B_HEIGHT = 800;
    static const int DOT_SIZE = 40;
    static const int ALL_DOTS = 400;
    static const int RAND_POS = 29;
    static const int DELAY1 = 250;
    static const int DELAY2 = 500;
    static const int DELAY3 = 1000;

    GameRules *gamerules;

    int timerId;
    int tailsize1;
    int tailsize2;
    int applex;
    int appley;

    int x1[ALL_DOTS];
    int y1[ALL_DOTS];
    int x2[ALL_DOTS];
    int y2[ALL_DOTS];



    enum direction {UP, DOWN, LEFT, RIGHT, NONE};
    direction dir1;
    direction dir2;



    void loadImages();
    void CreateApple();
    void CheckApple();
    void CheckCollision();
    void move1();
    void move2();
    void Update();
    void gameOver(QPainter &);
    void Draw();

};
#endif // SNAKE_H
