#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Bullet: public QObject, public QGraphicsRectItem {

    Q_OBJECT

    private:
        //Attributes
        int _speed;
        QTimer* _timer;

    private slots:
        void move();

    public:
        Bullet(int, int, int, int);

};

#endif // BULLET_H
