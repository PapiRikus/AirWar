#include "listaenemigos.h"
#include "QDebug"
using namespace std;

// Constructor por defecto
/**
 * @brief listaEnemigos::listaEnemigos      this constructor create a reference to file alea.txt. this file save objects type enemy.
 */
listaEnemigos::listaEnemigos(): fstream("alea.txt", ios::in | ios::out | ios::binary) {

        if(!good()) {
            open("alea.txt", ios::in | ios::out | ios::trunc | ios::binary);
        }

    numeroNodos = 0;
    m_head = NULL;
}

// Insertar al inicio
/**
 * @brief listaEnemigos::add_head
 * @param data_         data_ is a pointer to Enemy whith this pointer the algorithm can create a new node
 */
void listaEnemigos::add_head(Enemy *data_)
{
    node *new_node = new node (data_);
    if(this->numeroNodos >0)
    {
 //eliminaremos el ultimo elemento para liberar la memoria
        if(this->numeroNodos>=5){
            //this->LiberarUltimoElemento();
        }
        this->posicion[4] = this->posicion[3];
        this->posicion[3] = this->posicion[2];
        this->posicion[2] = this->posicion[1];
        this->posicion[1] = this->posicion[0];
    }
    this->posicion[0] = this->numeroNodos;


    this->GuardarArchivo(*new_node->data);
    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;
    }
    this->numeroNodos++;
}
//retornar esta vacio
/**
 * @brief listaEnemigos::estavacio
 * @return this method return the value true if this list is void.
 */
bool listaEnemigos::estavacio(){
    if(this->numeroNodos == 0){
        return true;
    }else{
        return false;
    }
}

//libera el ultimo elemento de la cadena del string
/**
 * @brief listaEnemigos::getNumeroNodos
 * @return return the number of nodes
 */
int listaEnemigos::getNumeroNodos(){
    return numeroNodos;
}
/**
 * @brief listaEnemigos::LiberarUltimoElemento      this method delete de last node in this list
 */
void  listaEnemigos::LiberarUltimoElemento(){

        if (!this->m_head) {

            } else
        {
            node *temp = this->m_head;
           node *temp1 = temp->next;
           // qDebug()<<"sigo bien";
               while (temp->next!= NULL) {
                   //qDebug()<<"cout hola mundo";
                   temp1 = temp;
                  temp = temp->next;
                }
               temp->~node();
                temp1->next = NULL;
            }
}
/**
 * @brief listaEnemigos::add_end                    this method add a new node in the last position of this list
 * @param data_                                                      this param is used to create a new node
 */
void listaEnemigos::add_end(Enemy *data_)
{
    node *new_node = new node (data_);
    node *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    this->numeroNodos++;
}


//retorna el objeto
 Enemy* listaEnemigos::buscarporposicion(int pos){
    node *temporal = this->m_head;
         for (int var = 0; var < pos; ++var) {
                temporal = temporal->next;
         }




         int x = pos;
         //pos = pos+1;
         node *temp = this->m_head;
         if((pos==this->posicion[0])||(pos==this->posicion[1])||(pos == this->posicion[2])||(pos==this->posicion[3])||(pos==this->posicion[4])){
             for (int var = 0; var < 5; ++var) {
                 if(pos==this->posicion[var]){
                     return temp->data;
                 }
                 temp = temp->next;
             }
         }else{return temporal->data;}

 }

 //removeOne
  void listaEnemigos::removeone(Enemy * value){
      node *temp;
      bool valor = true;

      for (int var = 0; var < this->numeroNodos; ++var) {
          if(value == temp->data){
              this->eliminarrposi(var);
              break;
          }
          temp= temp->next;
      }//*/
  }

  void listaEnemigos::eliminarrposi(int pos){
  //    node *temp = this->m_head;//crea un nodo nuevo y le asigna la cabeza
    //  this->numeroNodos;// es la cantidad de nodos de la lista


pos = pos +1;
      node *temp = this->m_head;
      node *temp1= this->m_head;
        if (pos < 1 || pos > this->numeroNodos) {

          } else if (pos == 1) {

              this->m_head = this->m_head->next;
             //delete nodoAuxiliar;
            //qDebug()<<this->numeroNodos;
             --numeroNodos;
          }else{
               for (int i = 1; i <= pos; i++) {
                  if (i == pos) {
                      int x = i;

                 //     while(x<4){
                   //       posicion[x]=posicion[x+1];
                      //    i++;
                      //}
                     // posicion[4] = -1;
                      //node *nodoAuxiliar = temp1;
                      temp1->next = temp->next;

                      //delete nodoAuxiliar;
                    numeroNodos=numeroNodos-1;
                  }
                    temp1 =  temp;
                    temp = temp->next;

              }

          }

  }
  void listaEnemigos::SobrescribirArchivo(int n, Enemy &enemi){
      clear();
      seekg(n*sizeof(Enemy), ios::beg);
      write(reinterpret_cast<char *> (&enemi), sizeof(Enemy));
  }
  void listaEnemigos::GuardarArchivo(Enemy &enemi){
      clear();
      seekg(0, ios::end);
      write(reinterpret_cast<char *> (&enemi), sizeof(Enemy));
  }
   void listaEnemigos::RecuperarArchivo(int n,Enemy &enemi){
          clear();
          seekg(n*sizeof(Enemy), ios::beg);
          read(reinterpret_cast<char *> (&enemi), sizeof(Enemy));
   }
void listaEnemigos::BorrarArchivo(int n){
    char marca;
    marca = 'N';
     seekg(n*sizeof(Enemy), ios::beg);
     write(&marca, 1);
}

listaEnemigos::~listaEnemigos() {}
