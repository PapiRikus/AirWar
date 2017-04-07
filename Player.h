#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <string>
#include <QGraphicsScene>
#include <QList>
#include "PowerUp.h"

class Player: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    private:

        //Attributes
        QString _name;
        int _width;
        int _height;
        int _score;
        int _maximumLevel;
        int _timePLayed;
        int _usedMemory;
        int _lives;
        int _weaponType;
        int _speedX;
        int _speedY;
        bool _shieldPowerUp;

        QList<PowerUp*> _powerUpsList;

    public:

        Player(QString, int, int);

        void moveRight();

        void moveLeft();

        void moveUp();

        void moveDown();

        void move(int, int);

        void increaseScore(int);

        void increaseLives();

        void decreaseLives();

        void receivePowerUp(PowerUp*);

        void activatePowerUp();

        QString getName() const;
        void setName(QString);

        int getScore() const;
        void setScore(int);

        int getWidth() const;
        void setWith(int);

        int getHeight() const;
        void setHeight(int);

        int getMaximumLevel() const;
        void setMaximumLevel(int);

        int getTimePlayed() const;
        void setTimePlayed(int);

        int getMemoryUsed() const;
        void setMemoryUsed(int);

        int getLives() const;
        void setLives(int);

        int getWeaponType() const;
        void setWeaponType(int);

        int getSpeedX() const;
        void setSpeedX(int);

        int getSpeedY() const;
        void setSpeedY(int) const;

        bool haveShield();
        void changeStateOfShield();

        void resetStatistics();

};

#endif // PLAYER_H
