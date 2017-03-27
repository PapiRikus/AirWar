#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <string>
//TEMP
#include <QGraphicsScene> // --------
//TEMP
#include "Bullet.h"

class Player: public QObject, public QGraphicsRectItem {

    Q_OBJECT

    private:
        //Attributes
        std::string _name;
        int _width;
        int _height;
        int _score;
        int _maximumLevel;
        int _timePLayed;
        int _usedMemory;
        int _lives;
        int _weaponType;
        int _speed;


    public:
        Player(std::string, int, int, int, int);

        void moveRight();

        void moveLeft();

        void shoot();

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

        int getSpeed() const;
        void setSpeed(int);

        //void insertPowerUp(PowerUp pPowerUp);

};

#endif // PLAYER_H
