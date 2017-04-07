#include "Bullet.h"

/**
 * @brief Bullet::Bullet - Constructor of the class
 * @param pPosX - The position on the X axis
 * @param pPosY - The position on the Y axis
 * @param pWidth - The width of the bullet
 * @param pHeight - The height of the bullet
 */
Bullet::Bullet(int pType, int pPosX, int pPosY): QObject(), QGraphicsPixmapItem() {

    //The type of the Bullet is establishes
    this->_type = pType;

    //If the Bullet is a Bullet from the Enemy
    if(0 == this->_type) {
        //The respective image to this type of Bullet is defined
        this->setPixmap(QPixmap(":/images/enemyBullet.png"));
        //The damage that this type of Bullet causes is defined
        this->_damage = 1;
        //The speed to move the bullet is defined
        this->_speedX = this->_speedY = 25;
    }

    //If the Bullet is a normal Bullet of the player
    if(1 == this->_type) {
        //The respective image to this type of Bullet is defined
        this->setPixmap(QPixmap(":/images/bullet.png"));
        //The damage that this type of Bullet causes is defined
        this->_damage = 1;
        //The speed to move the bullet is defined
        this->_speedX = this->_speedY = -20;
    }

    //If the Bullet is a Rocket
    if(2 == this->_type) {
        //The respective image to this type of Bullet is defined
        this->setPixmap(QPixmap(":/images/rocket.png"));
        //The damage that this type of Bullet causes is defined
        this->_damage = 2;
        //The speed to move the bullet is defined
        this->_speedX = this->_speedY = -20;

    }

    //If the Bullet is a Bullet from the Tower
    if(3 == this->_type) {
        //The respective image to this type of Bullet is defined
        this->setPixmap(QPixmap(":/images/enemyBullet.png"));
        //The damage that this type of Bullet causes is defined
        this->_damage = 1;
        //The speed to move the bullet is defined
        this->_speedX =10;
        this->_speedY = 10;

    }

    //The position in the screen of the bullet is establishes
    this->setPos(pPosX, pPosY);

}


/**
 * @brief Bullet::move - Function that moves the bullet through the screen
 */
void Bullet::move() {

    if (this->type()!=3){
        this->setPos(this->x(), this->y() + this->_speedY);
    }
}


/**
 * @brief Bullet::moveToPlayer - Function that moves the bullet throug the screen towards the player position
 * @param pPosPlayerX - The position on the X axis of the player
 */
void Bullet::moveToPlayer(int x, int pPosPlayerY) {
        if((this->x())>x){
            if(this->x()!=x){
                this->setPos(this->x()-this->getSpeedX()*2,this->y()+this->_speedY);
            }
        }
        if((this->x())<x){
            if(this->x()!=x){
                this->setPos(this->x()+this->getSpeedX()*2,this->y()+this->_speedY);
            }
        }
}


int Bullet::getType() const {

    return this->_type;

}

void Bullet::setType(int pType) {

    this->_type = pType;

}


int Bullet::getDamage() const {

    return this->_damage;

}

void Bullet::setDamage(int pDamage) {

    this->_damage = pDamage;

}


int Bullet::getSpeedX() const {

    return this->_speedY;

}

void Bullet::setSpeedX(int pSpeed) {

    this->_speedY = pSpeed;

}


int Bullet::getSpeedY() const {

    return this->_speedY;

}

void Bullet::setSpeedY(int pSpeedY) {

    this->_speedY = pSpeedY;

}
bool Bullet::getSeguir() const {

    return this->seguir;

}

void Bullet::setSeguir(bool pSpeedY) {

    this->seguir = pSpeedY;

}
