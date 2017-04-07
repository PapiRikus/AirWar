#include "Player.h"

#include <QDebug>
#include <QTimer>

/**
 * @brief Player::Player - Constructor of the class
 * @param pName - The name of the player
 * @param pPosX - The position on the X axis
 * @param pPosY - The position on the Y axis
 * @param pWidth - The width of the player
 * @param pHeight - The height of the player
 */
Player::Player(QString pName, int pPosX, int pPosY): QObject(), QGraphicsPixmapItem() {

    //The name of the player is establishes
    this->_name = pName;

    //The width of the player is defined
    this->_width = 150;

    //The height of the player is defined
    this->_height = 100;

    //The initial score of the player is defined
    this->_score = 0;

    //The initial maximum level of the player is defined
    this->_maximumLevel = 0;

    //The initial time played of the player is defined
    this->_timePLayed = 0;

    //The initial used memory of the player is defined
    this->_usedMemory = 0;

    //The initials lives of the player is defined
    this->_lives = 3;

    //The initial type of bullet is defined
    this->_weaponType = 1;

    //The speed to move the player is defined
    this->_speedX = this->_speedY = 12;

    //The initial state of shield power up is defined
    this->_shieldPowerUp = false;

    //The respective image of the player is defined
    this->setPixmap(QPixmap(":/images/playerAirplane.png"));

    //The position in the screen of the player is defined
    this->setPos(pPosX, pPosY - this->_height);

}


/**
 * @brief Player::moveRight - Function that moves the player to the right on screen
 */
void Player::moveRight() {

    this->setPos(this->x() + this->_speedX, this->y());

}


/**
 * @brief Player::moveLeft - Function that moves the player to the left on screen
 */
void Player::moveLeft() {

    this->setPos(this->x() - this->_speedX, this->y());

}


/**
 * @brief Player::moveUp - Function that moves the player up on screen
 */
void Player::moveUp() {

    this->setPos(this->x(), this->y() - this->_speedY);

}


/**
 * @brief Player::moveDown - Funtion that moves the player down on screen
 */
void Player::moveDown() {

    this->setPos(this->x(), this->y() + this->_speedY);

}


/**
 * @brief Player::move - Function that moves the player on screen with a mobile control
 * @param pSpeed - The level of speed with which to move
 */
void Player::move(int pSpeedX, int pSpeedY) {

    this->setPos(this->x() + pSpeedX, this->y() + pSpeedY);

}


/**
 * @brief Player::increaseScore - Function that increases the player's score certain amount of points
 */
void Player::increaseScore(int pScore) {

    this->_score += pScore;

}


/**
 * @brief Player::increaseLives - Function that increases the player's lives
 */
void Player::increaseLives() {

    this->_lives += 1;

}


/**
 * @brief Player::decreaseLives - Function that decreases the player's lives
 */
void Player::decreaseLives() {

    this->_lives -= 1;

}


/**
 * @brief Player::receivePowerUp - Function that adds a new power up to the list
 */
void Player::receivePowerUp(PowerUp* pPowerUp) {

    this->_powerUpsList.append(pPowerUp);

}


/**
 * @brief Player::activatePowerUp - Function that activates a power up from the list
 */
void Player::activatePowerUp() {

    //If the player has power up in list
    if(!this->_powerUpsList.isEmpty()) {
        //Move throug the power ups list of the player
        for(int i = 0; i < this->_powerUpsList.size(); i++) {
            //If the power up received is a shield
            if(1 == this->_powerUpsList[i]->getType()) {
                //Change the state of shield power up
                changeStateOfShield();
            }
            //If the power up received is a rocket
            else if(2 == this->_powerUpsList[i]->getType()) {
                //Change the weapon type to a rocket
                this->_weaponType = 2;
            }
            //If the power up received is a laser
            else {
                // -- activar laser --
            }
            //Remove the current power up from the power ups list
            this->_powerUpsList.removeOne(this->_powerUpsList[i]);
            //Leaves the cycle because a power up has been activated
            break;
        }
    }
    else {
        qDebug() << "No Power Ups in list";
    }

}


QString Player::getName() const {

    return this->_name;

}


int Player::getScore() const {

    return this->_score;

}


int Player::getWidth() const {

    return this->_width;

}


int Player::getHeight() const {

    return this->_height;

}

int Player::getLives() const {

    return this->_lives;

}


int Player::getWeaponType() const {

    return this->_weaponType;

}


bool Player::haveShield() {

    return this->_shieldPowerUp;

}

void Player::changeStateOfShield() {

    this->_shieldPowerUp = !this->_shieldPowerUp;

}


/**
 * @brief Player::resetStatistics - Function that resets player statistics
 */
void Player::resetStatistics() {

    this->_score = 0;
    this->_maximumLevel = 0;
    this->_timePLayed = 0;
    this->_usedMemory = 0;
    this->_lives = 3;

}



