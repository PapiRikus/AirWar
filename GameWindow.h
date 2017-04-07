#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "PowerUp.h"
#include "Server.h"
#include "jefe.h"
const int GAME_WINDOW_WIDTH = 1200;
const int GAME_WINDOW_HEIGHT = 800;

class GameWindow: public QGraphicsView {

    Q_OBJECT

    private:

        //Attributes
        Player* _player;
        QGraphicsScene* _gameScene;
        QGraphicsTextItem* _playerNameText;
        QGraphicsTextItem* _playerScoreText;
        QGraphicsTextItem* _playerLivesText;
        QGraphicsPixmapItem* _airWarPauseLogoImage;
        QTimer* _moveTimer;
        QTimer* _shootEnemyTimer;
        QTimer* _serverCallTimer;
        bool _mobileControl;
        bool _gameOnPause;
        int nNivel;
        int cantidadEnemigos;
        int indexEnemigo;
        bool jefeCreado;
        // -- TEMPORAL --
        int Random1;
        QTimer* _spawnTimer;
        QList<Enemy*> _enemiesList; //Pasar a las listas hechas por nosotros
        QList<PowerUp*> _powerUpsList;
        QList<Bullet*> _bulletsList;
        // -- TEMPORAL --

        //Methods
        void drawStatistics();
        void keyPressEvent(QKeyEvent*);
        void checkBulletsColisions(Bullet*);
        void updatePlayerScoreOnScreen();
        void updatePlayerLivesOnScreen();
        void pauseGame();
        void quitPauseGame();
        void gameOver();
        int hacerRand(int);
        void llenarLista(int);

private slots:
        void mobileControlEvent();
        void moveEnemies();
        void enemiesShoot();
        void moveBullets();
        void movePowerUps();
        void detectCollisions();
        //llena
        void seguirBalas();
        void detecPared();
        // -- TEMPORAL --
        void spawnEnemies(); // Los enemigos ya estan definidos al inicial el nivel
        void spawnJefe ();
        // -- TEMPORAL --
        void randomN();
    public:
        GameWindow(QString, bool, QWidget *parent = 0);
        ~GameWindow();

};


#endif // MAINWINDOW_H
