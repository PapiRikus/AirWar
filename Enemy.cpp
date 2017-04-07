#include "Enemy.h"

/**
 * @brief Enemy::Enemy - Constructor of the class
 * @param pType - The type of enemy
 * @param pPosX - The position on the X axis
 * @param pPosY - The position on the Y axis
 */
Enemy::Enemy(int pType, int pPosX, int pPosY): QObject(), QGraphicsPixmapItem() {

    //The type of the Enemy is establishes
    this->_type = pType;

    //If the enemy is a Jet
    if(1 == this->_type) {
        //The width of the player is defined
        this->_width = 88;
        //The height of the player is defined
        this->_height = 97;
        //The score value of this enemy is defined
        this->_scoreValue = 50;
        //High movility
        this->_speedX = this->_speedY = 15;
        //Low damage
        this->_damage = 20; // -- ??? --
        //Low life points
        this->_lifePoints = 1;
        //The respective image to this type of Enemy is defined
        this->setPixmap(QPixmap(":/images/enemy1.png"));
    }

    //If the enemy is a Bomber
    else if(2 == this->_type) {
        //The width of the player is defined
        this->_width = 150;
        //The height of the player is defined
        this->_height = 100;
        //The score value of this enemy is defined
        this->_scoreValue = 100;
        //Average movility
        this->_speedX = this->_speedY = 10;
        //High damage
        this->_damage = 40; // -- ??? --
        //Average life points
        this->_lifePoints = 2;
        //The respective image to this type of Enemy is defined
        this->setPixmap(QPixmap(":/images/enemy2.png"));
    }

    //If the enemy is a Tower
    else if(3 == this->_type) {
        this->_width = 70;
        //The height of the player is defined
        this->_height = 70;
        //The score value of this enemy is defined
        this->_scoreValue = 100;
        //Average movility
        this->_speedX = this->_speedY = 2;
        //High damage
        this->_damage = 40; // -- ??? --
        //Average life points
        this->_lifePoints = 2;
        //The respective image to this type of Enemy is defined
        this->setPixmap(QPixmap(":/images/alien33.png"));
    }

    //If the enemy is a Jet Kamimkaze
    else if(4 == this->_type) {
        //The width of the player is defined
        this->_width = 100;
        //The height of the player is defined
        this->_height = 100;
        //The score value of this enemy is defined
        this->_scoreValue = 150;
        //Average movility
        this->_speedX =1;
        this->_speedY = 5;
        //Low damage
        this->_damage = 20; // -- ??? --
        //Low life points
        this->_lifePoints = 1;
        //The respective image to this type of Enemy is defined
        this->setPixmap(QPixmap(":/images/alien22.png"));
    }

    srand(time(NULL));

    //Choose a random number to know if the enemy will have a power up
    if(2 == (1 + rand() % 3)) {
        //The enemy carry a power up
        this->_powerUp = true;
    }
    else {
        //The enemy don't carry a power up
        this->_powerUp = false;
    }

    //The position in the screen is establishes
    this->setPos(pPosX, pPosY);

}


/**
 * @brief Enemy::move - Function that moves the enemy down on the screen
 */
void Enemy::move() {

    this->setPos(this->x(), this->y() + this->_speedY);

}


/**
 * @brief Enemy::decreaseLifePoints - Function that decreases the life points  of the Enemy
 * @param pDamage - The amount of damage received
 */
void Enemy::decreaseLifePoints(int pDamage) {

    this->_lifePoints -= pDamage;

}


/**
 * @brief Enemy::isCarryPowerUp - Function that checks if the Enemy carry a power up
 */
bool Enemy::isCarryPowerUp() const {

    return this->_powerUp;

}


/**
 * @brief Enemy::moveToPlayerPosition - Function that moves the player to the current position of the player
 * @param pPlayerPosX - The current X axis position of the player
 */
void Enemy::moveToPlayerPosition(int pPlayerPosX){

    //
    if(this->x() > pPlayerPosX){
        //
        if(this->x() != pPlayerPosX){
            //
            this->setPos(this->x() - this->getSpeedX() * 2, this->y() + this->getSpeedY());
        }
    }
    if (this->x()==pPlayerPosX){
        this->setPos(this->x(), this->y() + this->getSpeedY());

    }
    //
    if((this->x()) < pPlayerPosX){
        //
        if(this->x() != pPlayerPosX){
            //
            this->setPos(this->x() + this->getSpeedX() * 2, this->y() + this->getSpeedY());
        }
    }

}


int Enemy::getType() const {

    return this->_type;

}

void Enemy::setType(int pType) {

    this->_type = pType;

}


int Enemy::getWidth() const {

    return this->_width;

}

void Enemy::setWidth(int pWidth) {

    this->_width = pWidth;

}


int Enemy::getHeight() const {

    return this->_height;

}

void Enemy::setHeight(int pHeight) {

    this->_height = pHeight;

}


int Enemy::getScoreValue() const {

    return this->_scoreValue;

}

void Enemy::setScoreValue(int pValue) {

    this->_scoreValue = pValue;

}


int Enemy::getSpeedX() const {

    return this->_speedX;

}

void Enemy::setSpeedX(int pSpeed) {

    this->_speedX = pSpeed;

}


int Enemy::getSpeedY() const {

    return this->_speedY;

}

void Enemy::setSpeedY(int pSpeedY) {

    this->_speedY = pSpeedY;

}


int Enemy::getDamage() const {

    return this->_damage;

}

void Enemy::setDamage(int pDamage) {

    this->_damage = pDamage;

}


int Enemy::getLifePoints() const {

    return this->_lifePoints;

}

void Enemy::setLifePoints(int pLifePoints) {

    this->_lifePoints = pLifePoints;

}





bool Enemy::getPared() const{

    return this->pared;

}

void Enemy::setPared(bool pared) {

    this->pared = pared;

}

bool Enemy::getSeguir() const{

    return this->seguir;

}

void Enemy::setSeguir(bool pared) {

    this->seguir = pared;

}
