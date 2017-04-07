#ifndef POWERUP_H
#define POWERUP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <stdlib.h>
#include <time.h>

class PowerUp: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    private:

        //Attributes
        int _type;
        int _speed;


    public:

        PowerUp(int, int);

        void move();

        int getType() const;
        void setType(int);

        int getSpeed() const;
        void setSpeed(int);

};

#endif // POWERUP_H
