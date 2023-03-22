/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 03:09 PM
 */

#ifndef NPRODUCTOS_H
#define NPRODUCTOS_H
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"
#include "Producto.h"


class NProductos {
public:
    NProductos();
    virtual ~NProductos();
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    void GetPrioridad(int &prioridad,int &cod);
private:
    Producto *prod;
};

#endif /* NPRODUCTOS_H */

