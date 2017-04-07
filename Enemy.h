#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <time.h>
#include "Bullet.h"

class Enemy: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    protected:

        //Attributes
        int _type;
        int _width;
        int _height;
        int _scoreValue;
        int _speedX;
        int _speedY;
        int _damage;
        int _lifePoints;
        bool _powerUp;
        bool pared;
        bool imapcto;
        bool seguir;
        bool enPantalla;
    public:

        Enemy(int, int, int);

        virtual void move();

        virtual void moveToPlayerPosition(int);

        void decreaseLifePoints(int);

        bool isCarryPowerUp() const;

        int getType() const;
        void setType(int);

        int getWidth() const;
        void setWidth(int);

        int getHeight() const;
        void setHeight(int);

        int getScoreValue() const;
        void setScoreValue(int);

        void setSpeedX(int speedX);
        int getSpeedX()const;

        int getSpeedY() const;
        void setSpeedY(int);

        int getDamage() const;
        void setDamage(int);

        int getLifePoints() const;
        void setLifePoints(int);

        void setPared(bool);
        bool getPared()const;

        void setImpacto(bool);
        bool getImpacto()const;

        void setSeguir(bool speedX);
        bool getSeguir()const;

        void setEnPantalla(bool);
        bool getEnPantalla()const;

};

#endif // ENEMY_H
