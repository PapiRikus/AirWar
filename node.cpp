#include "node.h"

// Constructor por defecto

node::node(){
    this->data = NULL;
    this->next = NULL;
}
node::node(Enemy *dato)
{
    data = dato;
    next = NULL;
}

node::~node() {
}
