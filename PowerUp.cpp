#include "PowerUp.h"

/**
 * @brief PowerUp::PowerUp - Constructor of the class
 * @param pPosX - The position on the X axis
 * @param pPosY - The position on the Y axis
 */
PowerUp::PowerUp(int pPosX, int pPosY): QObject(), QGraphicsPixmapItem() {

    srand(time(NULL));

    //Choose a random number (1-3)
    this->_type = 1 + rand() % 3;

    //If the Power Up is a shield
    if(1 == this->_type) {
        //The respective image to this type of PowerUp is defined
        this->setPixmap(QPixmap(":/images/powerUpShield.png"));
    }

    //If the Power Up is a rocket
    if(2 == this->_type) {
        //The respective image to this type of PowerUp is defined
        this->setPixmap(QPixmap(":/images/powerUpRocket.png"));
    }

    //If the Power Up is a laser
    if(3 == this->_type) {
        //The respective image to this type of PowerUp is defined
        this->setPixmap(QPixmap(":/images/powerUpLaser.png"));
    }

    //The speed to move the PowerUp is defined
    this->_speed = 12.5;

    //The position in the screen is establishes
    this->setPos(pPosX, pPosY);

}


/**
 * @brief PowerUp::move - Function that moves the Power Up down on the screen
 */
void PowerUp::move() {

    this->setPos(this->x(), this->y() + this->_speed);

}


int PowerUp::getType() const {

    return this->_type;

}

void PowerUp::setType(int pType) {

    this->_type = pType;

}


int PowerUp::getSpeed() const {

    return this->_speed;

}

void PowerUp::setSpeed(int pSpeed) {

    this->_speed = pSpeed;

}

