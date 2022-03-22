#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
}

MainWindow::MainWindow(GameRules* gamerules) : QMainWindow(), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->gamerules = gamerules;

}

MainWindow::~MainWindow() {

    delete ui;
}


void MainWindow::on_Begin_1P_clicked() {

    gamerules->multiplayer = false;
    delete this;
}

void MainWindow::on_Begin_2P_clicked() {

    gamerules->multiplayer = true;
    delete this;
}

void MainWindow::on_EasyMode_clicked()
{
    gamerules->gameSpeed = SLOW;
}

void MainWindow::on_MediumMode_clicked()
{
    gamerules->gameSpeed = NORMAL;
}

void MainWindow::on_HardMode_clicked()
{
    gamerules->gameSpeed = FAST;
}
