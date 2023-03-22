/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 06:08 PM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "NArbol.h"


class Arbol {
public:
    Arbol();
    virtual ~Arbol();
    void inserta(medicamento *&med);
    void imprimir(ofstream &arch);
    void eliminar(int codigo);
    void eliminarNodosMayores(int codigo,class NArbol *&raiz);
private:
    void insertaArbol(class NArbol *&nodo,medicamento *&med);
    void imprimeArbol(class NArbol *&nodo,ofstream &arch);
    void eliminarNodo(int codigo,class NArbol *&nodo);
    void eliminar_auxiliar(class NArbol *&nodo, class NArbol *&nodoDer);
    class NArbol *raiz;
};

#endif /* ARBOL_H */

