#include "snake.h"
#include "ui_snake.h"

Snake::Snake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snake)
{
    ui->setupUi(this);
    leftDirection1 = false;
    rightDirection1 = true;
    upDirection1 = false;
    downDirection1 = false;
    inGame = true;

    setFixedSize(B_WIDTH, B_HEIGHT);
    StartGame();
}

Snake::~Snake()
{
    delete ui;
}




void Snake::StartGame() {
    int players=2;                  //SETTING PLAYER COUNT
    int mode=1;                     // SETTING MODE
    if (players==1){
        tailsize1 = 3;
    }
    if (players==2){
        tailsize1 = 3;
        tailsize2 = 3;
    }


    if (players==2){                                 //change later
        for (int z1 = 0; z1 < tailsize1; z1++) {
            x1[z1] = 80;
            y1[z1] = 40;
        }
        for (int z2 = 0; z2 < tailsize2; z2++) {
            x2[z2] = 720;
            y2[z2] = 40;
        }
    }
    else{
        for (int z = 0; z < tailsize1; z++) {
            x1[z] = 40;
            y1[z] = 40;

       }
    }
    CreateApple();

    if(mode==1){
        timerId = startTimer(DELAY1);  // fast
    }
    if(mode==2){
        timerId = startTimer(DELAY2);  // medium
    }
    if(mode==3){
        timerId = startTimer(DELAY3);  // slow
    }
}

void Snake::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    Draw();
}


void Snake::Draw(){
    QPainter qp(this);

    if (inGame==true) {

        QRectF apple(applex,appley, 40, 40);
        QPainter a(this);
        a.setBrush(Qt::red);
        a.drawEllipse(apple);

        for (int z = 0; z < tailsize1; z++) {
            if (z == 0) {
                QRectF head(x1[z], y1[z], 40, 40);
                QPainter h(this);
                h.setBrush(Qt::blue);
                h.drawEllipse(head);
            } else {
                QRectF head(x1[z], y1[z], 40, 40);
                QPainter h(this);
                h.setBrush(Qt::darkBlue);
                h.drawEllipse(head);
            }
        }

        for (int z = 0; z < tailsize2; z++) {
            if (z == 0) {
                QRectF head(x2[z], y2[z], 40, 40);
                QPainter h(this);
                h.setBrush(Qt::cyan);
                h.drawEllipse(head);
            } else {
                QRectF head(x2[z], y2[z], 40, 40);
                QPainter h(this);
                h.setBrush(Qt::darkCyan);
                h.drawEllipse(head);
            }
        }

    }
    else {

        gameOver(qp);
    }
}






void Snake::gameOver(QPainter &qp) {

    QString message = "Game over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}







void Snake::CheckApple() {


    if ((x1[0] == applex) && (y1[0] == appley)) {

        tailsize1++;
        CreateApple();
    }

    if ((x2[0] == applex) && (y2[0] == appley)) {

        tailsize2++;
        CreateApple();
    }
}



void Snake::move1() {

    for (int z = tailsize1; z > 0; z--) {
        x1[z] = x1[(z - 1)];
        y1[z] = y1[(z - 1)];
    }

    if (leftDirection1) {
        x1[0] -= DOT_SIZE;
    }

    if (rightDirection1) {
        x1[0] += DOT_SIZE;
    }

    if (upDirection1) {
        y1[0] -= DOT_SIZE;
    }

    if (downDirection1) {
        y1[0] += DOT_SIZE;
    }
}

void Snake::move2() {

    for (int z = tailsize2; z > 0; z--) {
        x2[z] = x2[(z - 1)];
        y2[z] = y2[(z - 1)];
    }

    if (leftDirection2) {
        x2[0] -= DOT_SIZE;
    }

    if (rightDirection2) {
        x2[0] += DOT_SIZE;
    }

    if (upDirection2) {
        y2[0] -= DOT_SIZE;
    }

    if (downDirection2) {
        y2[0] += DOT_SIZE;
    }
}

void Snake::CheckCollision() {
    int playerss = 2;                 // CHANGE PLAYER COUNT

    for (int z = tailsize1; z > 0; z--) {

        if ((z > 4) && (x1[0] == x1[z]) && (y1[0] == y1[z])) {
            inGame = false;
        }
    }

    for (int z = tailsize2; z > 0; z--) {

        if ((z > 4) && (x1[0] == x2[z]) && (y1[0] == y2[z])) {
            inGame = false;
        }
    }

    if (y1[0] >= B_HEIGHT) {
        inGame = false;
    }

    if (y1[0] < 0) {
        inGame = false;
    }

    if (x1[0] >= B_WIDTH) {
        inGame = false;
    }

    if (x1[0] < 0) {
        inGame = false;
    }

    if(!inGame) {
        killTimer(timerId);
    }

    if(playerss==2){

        for (int q = tailsize2; q > 0; q--) {

            if ((q > 4) && (x2[0] == x2[q]) && (y2[0] == y2[q])) {
                inGame = false;
            }
        }

        for (int q = tailsize1; q > 0; q--) {

            if ((q > 1) && (x2[0] == x1[q]) && (y2[0] == y1[q])) {
                    inGame = false;
            }

        }

        if (y2[0] >= B_HEIGHT) {
            inGame = false;
        }

        if (y2[0] < 0) {
            inGame = false;
        }

        if (x2[0] >= B_WIDTH) {
            inGame = false;
        }

        if (x2[0] < 0) {
            inGame = false;
        }

        if(!inGame) {
            killTimer(timerId);
        }
    }
}



void Snake::CreateApple() {

    int randx = QRandomGenerator::global()->bounded(1, 20);
    int randy = QRandomGenerator::global()->bounded(1, 20);
    applex = (randx)*40;
    appley = (randy)*40;
}



void Snake::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (inGame) {

        CheckApple();
        CheckCollision();
        move1();
        move2();
    }

    repaint();
}

void Snake::keyPressEvent(QKeyEvent *e) {

    int key1 = e->key();
    int key2 = e->key();

    if ((key1 == Qt::Key_Left) && (!rightDirection1)) {
        leftDirection1 = true;
        upDirection1 = false;
        downDirection1 = false;
    }

    if ((key1 == Qt::Key_Right) && (!leftDirection1)) {
        rightDirection1 = true;
        upDirection1 = false;
        downDirection1 = false;
    }

    if ((key1 == Qt::Key_Up) && (!downDirection1)) {
        upDirection1 = true;
        rightDirection1 = false;
        leftDirection1 = false;
    }

    if ((key1 == Qt::Key_Down) && (!upDirection1)) {
        downDirection1 = true;
        rightDirection1 = false;
        leftDirection1 = false;
    }

    if ((key2 == Qt::Key_A) && (!rightDirection2)) {
        leftDirection2 = true;
        upDirection2 = false;
        downDirection2 = false;
    }

    if ((key2 == Qt::Key_D) && (!leftDirection2)) {
        rightDirection2 = true;
        upDirection2 = false;
        downDirection2 = false;
    }

    if ((key2 == Qt::Key_W) && (!downDirection2)) {
        upDirection2 = true;
        rightDirection2 = false;
        leftDirection2 = false;
    }

    if ((key2 == Qt::Key_S) && (!upDirection2)) {
        downDirection2 = true;
        rightDirection2 = false;
        leftDirection2 = false;
    }

    QWidget::keyPressEvent(e);
}
