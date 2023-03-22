/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 07:17 PM
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "medicamento.h"
#include "NodoArbol.h"
class Arbol {
public:
    Arbol();
    virtual ~Arbol();
    void insertarArbol(medicamento *med);
    void imprimir(ofstream &arch);
private:
    void insertar(NodoArbol *&nodo,medicamento *med);
    void imprime(ofstream &arch,NodoArbol *nodo);
    NodoArbol *arbol;
};

#endif /* ARBOL_H */

