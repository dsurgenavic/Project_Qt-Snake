#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
}

MainWindow::MainWindow(GameRules* gamerules) : QMainWindow(), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->gamerules = gamerules;
    ui->MediumMode->setChecked(true);

    game = new Snake(gamerules);

}

MainWindow::~MainWindow() {

    delete ui;
}


void MainWindow::on_Begin_1P_clicked() {

    gamerules->multiplayer = false;
    gamerules->running = true;

    this->hide();
    game->show();
    game->StartGame();
}

void MainWindow::on_Begin_2P_clicked() {

    gamerules->multiplayer = true;
    gamerules->running = true;

    this->hide();
    game->show();
    game->StartGame();
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
