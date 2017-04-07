#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Bullet: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    private:

        //Attributes
        int _type;
        int _damage;
        int _speedX;
        int _speedY;
        bool seguir;
    public:

        Bullet(int, int, int);

        void move();

        void moveToPlayer(int, int);

        int getType() const;
        void setType(int);

        int getDamage() const;
        void setDamage(int);

        int getSpeedX() const;
        void setSpeedX(int);

        int getSpeedY() const;
        void setSpeedY(int);

        bool getSeguir() const;
        void setSeguir(bool);

};

#endif // BULLET_H
