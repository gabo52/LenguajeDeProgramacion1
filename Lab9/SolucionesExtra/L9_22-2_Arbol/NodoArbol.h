/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoArbol.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 07:54 PM
 */

#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "medicamento.h"


class NodoArbol {
public:
    NodoArbol();
    virtual ~NodoArbol();
    friend  class Arbol;
private:
    NodoArbol *der;
    NodoArbol *izq;
    medicamento *dato;
};

#endif /* NODOARBOL_H */

