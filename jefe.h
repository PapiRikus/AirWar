#ifndef JEFE_H
#define JEFE_H

#include "Enemy.h"
class Jefe:public Enemy
{
public:
    Jefe();
    Jefe(int a,int b,int c,QString img);
    void Damage(int a);
    void movimientoLoco();
    void movimientoNormal(int speed);
    void move();
    bool mov;
    bool pared;
private:
    int nivel;
    QString img;

};


#endif // JEFE_H
