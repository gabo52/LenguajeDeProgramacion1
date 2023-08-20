/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tienda.h
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:05 AM
 */
#include "Pedido.h"
#include "Cliente.h"
#ifndef TIENDA_H
#define TIENDA_H

class Tienda {
private:
    Pedido lpedidos[10000];
    Cliente lclientes[10000];
public:
    Tienda();
    Tienda(const Tienda& orig);
    virtual ~Tienda();
    void carga ();
    void muestra();
    void actualiza(int );

};

#endif /* TIENDA_H */

