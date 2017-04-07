#ifndef LISTAENEMIGOS_H
#define LISTAENEMIGOS_H
#include "node.h"
#include <QObject>
#include <fstream>
#include <iostream>
#include <string>
#include "Enemy.h"
#include <stdlib.h>
#include <fstream>

#include "node.h"

using namespace std;

class listaEnemigos: public fstream
{
    public:
        listaEnemigos();
        ~listaEnemigos();
        bool estavacio();
        Enemy* buscarporposicion(int);
        void removeone(Enemy *);
        void eliminarrposi(int);
        void add_head(Enemy*);

        void GuardarArchivo(Enemy &enemi);
        void RecuperarArchivo(int n,Enemy &enemi);
        void BorrarArchivo(int n);
        void LiberarUltimoElemento();
        void SobrescribirArchivo(int n, Enemy &enemi);



        void add_end(Enemy*);
        void add_sort(Enemy);
        void concat(listaEnemigos);
        void del_all();
        void del_by_data(Enemy);
        void del_by_position(int);
        void fill_by_user(int);
        void fill_random(int);
        void intersection(listaEnemigos);
        void invert();
        void load_file(string);
        void print();
        void save_file(string);
        void search(Enemy);
        void sort();
        int getNumeroNodos();

    private:
         int posicion[5];
        node *m_head;
        int numeroNodos;
};
#endif // LISTAENEMIGOS_H
