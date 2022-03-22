#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {


}

GameWindow::~GameWindow() {

    delete this;
}

void GameWindow::paintEvent(QPaintEvent *) {

}

void GameWindow::keyPressEvent(QKeyEvent *event) {

}
