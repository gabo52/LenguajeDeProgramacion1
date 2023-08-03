/* 
 * File:   Nodo.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 05:01 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"


class Nodo {
public:
    Nodo();
    virtual ~Nodo();
    friend class Lista;
private:
    Nodo *sig;
    Nodo *ant;
    Pedido *ped;
};

#endif /* NODO_H */

