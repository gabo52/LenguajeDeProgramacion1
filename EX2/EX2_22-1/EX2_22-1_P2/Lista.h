/* 
 * File:   Lista.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:11 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"


class Lista {
public:
    Lista();
    void inserta(Pedido &ped);
    virtual ~Lista();
    void imprime(ofstream &arch);
    void actualizaPrioridad(int prioridad,int cod);
    void reordenar();
private:
    void insertarAlInicio(Pedido &ped);
    class  Nodo *lini;
    class Nodo *lfin;
};

#endif /* LISTA_H */

