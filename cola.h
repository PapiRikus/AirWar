#ifndef COLA_H
#define COLA_H
#include "node.h"
#include "Enemy.h"
#include <fstream>
using namespace std;
class cola: public fstream
{
public:
    cola();
    ~cola();
    Enemy* leer();
    Enemy* getprimero();
    void eliminarprimero();
    void Add(Enemy *);
private:
      node *primero, *ultimo;
};

#endif // COLA_H
