/* 
 * File:   NodoArbol.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

