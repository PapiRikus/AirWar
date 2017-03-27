#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class GameWindow: public QGraphicsView {

    Q_OBJECT

    private:
        //Attributes
        Player* player;
        QGraphicsScene* gameScene;

        //Methods
        void keyPressEvent(QKeyEvent*);

    private slots:
        void spawnEnemys();

    public:
        GameWindow(QWidget *parent = 0);
        ~GameWindow();

};

#endif // MAINWINDOW_H
