/* 
 * File:   Nodo.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:10 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"
#include "Lista.h"

class Nodo {
public:
    Nodo();
    friend class Lista;
private:
    Pedido ped;
    Nodo *sig;
};

#endif /* NODO_H */

