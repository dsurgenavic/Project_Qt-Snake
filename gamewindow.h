#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "GameRules.h"

namespace Ui {
    class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    GameWindow(GameRules* gamerules, QWidget *parent = nullptr);
    ~GameWindow();

    GameRules* gamerules;

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
