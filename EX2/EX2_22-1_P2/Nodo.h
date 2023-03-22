/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Gabo
 *
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

