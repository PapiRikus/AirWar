#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Enemy: public QObject, public QGraphicsRectItem {

    Q_OBJECT

    private:
        //Attributes
        int _type;
        int _speed;
        int _damage;
        int _lifePoints;
        QTimer* _timer;

        //Methods
        void shoot();


    private slots:
        void move();

    public:
        Enemy(int, int, int);

};

#endif // ENEMY_H
