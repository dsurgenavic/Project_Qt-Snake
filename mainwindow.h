#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GameRules.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(GameRules* gamerules);
    ~MainWindow();

    GameRules* gamerules;

private slots:
    void on_Begin_1P_clicked();

    void on_Begin_2P_clicked();

    void on_EasyMode_clicked();

    void on_MediumMode_clicked();

    void on_HardMode_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
