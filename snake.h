#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QPainter>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Snake; }
QT_END_NAMESPACE

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();

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
    static const int DELAY1 = 140;
    static const int DELAY2 = 200;
    static const int DELAY3 = 300;

    int timerId;
    int tailsize1;
    int tailsize2;
    int applex;
    int appley;
    //int playerss = 2;

    int x1[ALL_DOTS];
    int y1[ALL_DOTS];
    int x2[ALL_DOTS];
    int y2[ALL_DOTS];



    bool leftDirection1;
    bool rightDirection1;
    bool upDirection1;
    bool downDirection1;
    bool leftDirection2;
    bool rightDirection2;
    bool upDirection2;
    bool downDirection2;
    bool inGame;

    void loadImages();
    void StartGame();
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
