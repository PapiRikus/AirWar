#include "Enemy.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QDebug>

/**
 * @brief Enemy::Enemy - Constructor of the class
 * @param pType - The type of enemy
 * @param pPosX - The position on the X axis
 * @param pPosY - The position on the Y axis
 */
Enemy::Enemy(int pType, int pPosX, int pPosY): QObject(), QGraphicsRectItem() {

    //The type of the Enemy is establishes
    this->_type = pType;

    //If the enemy is a Jet
    if(1 == this->_type) {
        //High movility
        this->_speed = 15;
        //Low damage
        this->_damage = 20;
        //Low life points
        this->_lifePoints = 100;
    }

    //If the enemy is a Bomber
    else if(2 == this->_type) {
        //Average movility
        this->_speed = 10;
        //High damage
        this->_damage = 40;
        //Average life points
        this->_lifePoints = 150;
    }

    //The position in the screen is establishes
    this->setPos(pPosX, pPosY);
    //The size of the enemy is defined
    this->setRect(0, 0, 100, 100);

    //Create a timer to handle the time in which its got to move
    this->_timer = new QTimer(this);
    //Connect the timer with the moving function
    connect(this->_timer, SIGNAL(timeout()), this, SLOT(move()));
    //The time to call the moving function is defined
    this->_timer->start(50);

}


/**
 * @brief Enemy::move - Function that moves the enemy through the screen
 */
void Enemy::move() {

    //Move the enemy down
    this->setPos(this->x(), this->y() + this->_speed);

    /*if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }*/

}
