#include "Bullet.h"

/**
 * @brief Bullet::Bullet - Constructor of the class
 * @param pPosX - The position on the X axis
 * @param pPosY - The position on the Y axis
 * @param pWidth - The width of the bullet
 * @param pHeight - The height of the bullet
 */
Bullet::Bullet(int pPosX, int pPosY, int pWidth, int pHeight): QObject(), QGraphicsRectItem() {

    //The size of the bullet is establishes
    this->setRect(0, 0, pWidth, pHeight);
    //The position in the screen of the bullet is establishes
    this->setPos(pPosX, pPosY);

    //The speed to move the bullet is defined
    this->_speed = 10;

    //Create a timer to handle the time in which its got to move
    this->_timer = new QTimer(this);
    //Connect the timer with the moving function
    connect(this->_timer, SIGNAL(timeout()), this, SLOT(move()));
    //The time to call the moving function is defined
    this->_timer->start(50);

}


/**
 * @brief Bullet::move - Function that moves the bullet through the screen
 */
void Bullet::move() {

    //Move the bullet up
    this->setPos(x(), y() - this->_speed);

}
