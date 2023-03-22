/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Gabo
 *
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

