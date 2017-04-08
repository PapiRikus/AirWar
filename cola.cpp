#include "cola.h"
/**
 * @brief cola::cola                this constructor create a referente to file torres.dat
 */
cola::cola(): fstream("torres.dat", ios::in | ios::out | ios::binary) {
    if(!good()) {
        open("torres.dat", ios::in | ios::out | ios::trunc | ios::binary);
    }
}
/**
 * @brief cola::~cola
 */
cola::~cola() {
   while(primero)
   {leer();}
}

/**
 * @brief cola::Add
 * @param v             this is a pointer to Enemy this pointer is used for create a new node.
 */
void cola::Add(Enemy *v) {
   node*nuevo;

   // Crear un nodo nuevo
   // Este será el último nodo, no debe tener siguiente
   nuevo = new node(v);
   //Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo
   if(ultimo) ultimo->next = nuevo;
   // Ahora, el último elemento de la cola es el nuevo nodo
   ultimo = nuevo;
   // Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!primero) primero = nuevo;
}

/**
 * @brief cola::leer
 * @return this method return data pointer. this pointer is a reference to enemy
 */
Enemy* cola::leer() {
    node *Nodo; // variable auxiliar para manipular nodo
    Enemy *v;

   // Nodo apunta al primer elemento
   Nodo = primero;
   if(!Nodo) return 0; //Si no hay nodos en la pila retornamos 0
   //Asignamos a primero la dirección del segundo nodo
   primero = Nodo->next;
   // Guardamos el valor de retorno
   v = Nodo->data;
   // Borrar el nodo
   delete Nodo;
   // Si la cola quedó vacía, ultimo debe ser NULL también
   if(!primero) ultimo = NULL;
   return Nodo->data;
}
