#include "jefe.h"
//#include "Enemy.h"

Jefe::Jefe():Enemy(0,0,0){

}
Jefe::Jefe(int PosT,int posX,int posY,QString img):Enemy(PosT,posX,posY)
{
    this->img=img;
    this->setLifePoints(1);
    _width=100;
    _height=50;
   // this->setSpeed(15);
    this->setSpeedX(-10);
   // this->setSeguir(true);
    this->setPixmap(QPixmap(":/images/alienboss.png"));

}
void Jefe::movimientoNormal(int speed){
    this->_speedX=speed;

}
void Jefe::move(){
    float x=rand()%10;
    //qDebug("pasa por move de jefe");
    //if (this->pared==true){
      //  _speed=_speed*(-1);
       // this->pared=false;

    //}

    if (x<4){

        this->setPos(this->x()+this->_speedX,this->y()+this->_speedX);
    }
    else{
        this->setPos(this->x(),0);

   }
}
