#include "Player.h"

/**
 * @brief Player::Player - Constructor of the class
 * @param pName - The name of the player
 * @param pPosX - The position on the X axis
 * @param pPosY - The position on the Y axis
 * @param pWidth - The width of the player
 * @param pHeight - The height of the player
 */
Player::Player(std::string pName, int pPosX, int pPosY, int pWidth, int pHeight): QObject(), QGraphicsRectItem() {

    //The name of the player is establishes
    this->_name = pName;
    //The width of the player is establishes
    this->_width = pWidth;
    //The height of the player is establishes
    this->_height = pHeight;

    //The speed to move the player is defined
    this->_speed = 10;

    //The size of the player is defined
    this->setRect(0, 0, this->_width, this->_height);

    //The position in the screen of the player is defined
    this->setPos(pPosX, pPosY - this->_height);


}

/**
 * @brief Player::moveRight - Function that moves the player to the right on screen
 */
void Player::moveRight() {

    this->setPos(x() + _speed, y());

}


/**
 * @brief Player::moveLeft - Function that moves the player to the left on screen
 */
void Player::moveLeft() {

    this->setPos(x() - _speed, y());

}


//TEMPORAL ???????
/**
 * @brief Player::shoot -
 */
void Player::shoot() {

    Bullet* bullet = new Bullet(this->x(), this->y(), 10, 50);
    scene()->addItem(bullet);

}
