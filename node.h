#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <QObject>
#include "Enemy.h"
class node
{
    public:
        node();
        node(Enemy *);
        ~node();

        node *next;
        Enemy *data;

};
#endif // NODE_H
