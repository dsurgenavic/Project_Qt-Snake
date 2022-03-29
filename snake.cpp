#include "snake.h"
#include "ui_snake.h"

Snake::Snake(GameRules *gamerules, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snake)
{
    ui->setupUi(this);
    this->gamerules = gamerules;

    dir1 = NONE;
    dir2 = NONE;

    setFixedSize(B_WIDTH, B_HEIGHT);
}

Snake::~Snake()
{
    delete ui;
}

void Snake::StartGame() {
                    // SETTING MODE
    tailsize1 = 3;
    if (gamerules->multiplayer){
        tailsize2 = 3;
    }


    if (gamerules->multiplayer){                                 //change later
        for (int z1 = 0; z1 <= tailsize1; z1++) {
            x1[z1] = 200;
            y1[z1] = 400 + 40 * z1;
        }
        for (int z2 = 0; z2 <= tailsize2; z2++) {
            x2[z2] = 600;
            y2[z2] = 400 + 40 * z2;
        }
    }
    else{
        for (int z = 0; z <= tailsize1; z++) {
            x1[z] = 200;
            y1[z] = 400 + 40 * z;

       }
    }
    CreateApple();

    if(gamerules->gameSpeed == FAST){
        timerId = startTimer(DELAY1);  // fast
    }
    else if(gamerules->gameSpeed == NORMAL){
        timerId = startTimer(DELAY2);  // medium
    }
    else if(gamerules->gameSpeed == SLOW){
        timerId = startTimer(DELAY3);  // slow
    }
}

void Snake::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    Draw();
}

void Snake::Draw(){
    QPainter p(this);

    if (gamerules->running) {

        p.setBrush(Qt::red);
        p.drawEllipse(applex,appley, 40, 40);

        for (int z = 0; z <= tailsize1; z++) {
            if (z == 0) {
                p.setBrush(Qt::blue);
                p.drawEllipse(x1[z], y1[z], 40, 40);
            } else {
                p.setBrush(Qt::darkBlue);
                p.drawEllipse(x1[z], y1[z], 40, 40);
            }
        }
        if(gamerules->multiplayer) {
            for (int z = 0; z <= tailsize2; z++) {
                if (z == 0) {
                    p.setBrush(Qt::cyan);
                    p.drawEllipse(x2[z], y2[z], 40, 40);
                } else {
                    p.setBrush(Qt::darkCyan);
                    p.drawEllipse(x2[z], y2[z], 40, 40);
                }
            }
        }

    }
    else {

        gameOver(p);
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
        if(x1[tailsize1-1] == x1[tailsize1-2]) {
            x1[tailsize1] = x1[tailsize1-1];
            if(y1[tailsize1-1] > y1[tailsize1-2]) {
                y1[tailsize1] = y1[tailsize1-1] + DOT_SIZE;
            } else {
                y1[tailsize1] = y1[tailsize1-1] - DOT_SIZE;
            }
        } else {
            y1[tailsize1] = y1[tailsize1-1];
            if(x1[tailsize1-1] > x1[tailsize1-2]) {
                x1[tailsize1] = x1[tailsize1-1] + DOT_SIZE;
            } else {
                x1[tailsize1] = x1[tailsize1-1] - DOT_SIZE;
            }
        }
    }


    if ((x2[0] == applex) && (y2[0] == appley)) {

        tailsize2++;
        CreateApple();
        if(x2[tailsize2-1] == x2[tailsize2-2]) {
            x2[tailsize2] = x2[tailsize2-1];
            if(y2[tailsize2-1] > y2[tailsize2-2]) {
                y2[tailsize2] = y2[tailsize2-1] + DOT_SIZE;
            } else {
                y2[tailsize2] = y2[tailsize2-1] - DOT_SIZE;
            }
        } else {
            y2[tailsize2] = y2[tailsize2-1];
            if(x2[tailsize2-1] > x2[tailsize2-2]) {
                x2[tailsize2] = x2[tailsize2-1] + DOT_SIZE;
            } else {
                x2[tailsize2] = x2[tailsize2-1] - DOT_SIZE;
            }
        }
    }
}

void Snake::move1() {

    if(dir1 == NONE) return;

    for (int z = tailsize1; z > 0; z--) {
        x1[z] = x1[(z - 1)];
        y1[z] = y1[(z - 1)];
    }

    switch(dir1) {
        case(UP): {
            y1[0] -= DOT_SIZE;
            break;
        }
        case(DOWN): {
            y1[0] += DOT_SIZE;
            break;
        }
        case(LEFT): {
            x1[0] -= DOT_SIZE;
            break;
        }
        case(RIGHT): {
            x1[0] += DOT_SIZE;
            break;
        }
    default: break;
    }
}

void Snake::move2() {

    if(dir2 == NONE) return;

    for (int z = tailsize2; z > 0; z--) {
        x2[z] = x2[(z - 1)];
        y2[z] = y2[(z - 1)];
    }

    switch(dir2) {
        case(UP): {
            y2[0] -= DOT_SIZE;
            break;
        }
        case(DOWN): {
            y2[0] += DOT_SIZE;
            break;
        }
        case(LEFT): {
            x2[0] -= DOT_SIZE;
            break;
        }
        case(RIGHT): {
            x2[0] += DOT_SIZE;
            break;
        }
    default: break;
    }
}

void Snake::CheckCollision() {
    for (int z = tailsize1; z > 0; z--) {
        if ((x1[0] == x1[z]) && (y1[0] == y1[z])) gamerules->running = false;
    }
    for (int z = tailsize2; z > 0; z--) {
        if ((x1[0] == x2[z]) && (y1[0] == y2[z])) gamerules->running = false;
    }
    if (y1[0] >= B_HEIGHT) gamerules->running = false;
    if (y1[0] < 0) gamerules->running = false;
    if (x1[0] >= B_WIDTH) gamerules->running = false;
    if (x1[0] < 0)gamerules->running = false;

    if(gamerules->multiplayer){

        for (int q = tailsize2; q > 0; q--) {
            if ((x2[0] == x2[q]) && (y2[0] == y2[q])) gamerules->running = false;
        }
        for (int q = tailsize1; q > 0; q--) {
            if ((x2[0] == x1[q]) && (y2[0] == y1[q])) gamerules->running = false;
        }
        if (y2[0] >= B_HEIGHT) gamerules->running = false;
        if (y2[0] < 0) gamerules->running = false;
        if (x2[0] >= B_WIDTH) gamerules->running = false;
        if (x2[0] < 0) gamerules->running = false;
    }

    if(gamerules->running == false) killTimer(timerId);
}

void Snake::CreateApple() {

    int randx = QRandomGenerator::global()->bounded(1, 20);
    int randy = QRandomGenerator::global()->bounded(1, 20);
    applex = (randx)*40;
    appley = (randy)*40;
}

void Snake::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (gamerules->running) {

        move1();
        move2();
        CheckApple();
        CheckCollision();
    }

    repaint();
}

void Snake::keyPressEvent(QKeyEvent *e) {

    int key = e->key();

    switch(key) {
    case(Qt::Key_Up): dir1 = UP; break;
    case(Qt::Key_Down): dir1 = DOWN; break;
    case(Qt::Key_Left): dir1 = LEFT; break;
    case(Qt::Key_Right): dir1 = RIGHT; break;
    case(Qt::Key_W): dir2 = UP; break;
    case(Qt::Key_A): dir2 = LEFT; break;
    case(Qt::Key_S): dir2 = DOWN; break;
    case(Qt::Key_D): dir2 = RIGHT; break;
    default: break;
    }

    QWidget::keyPressEvent(e);
}
