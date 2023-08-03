/* 
 * File:   Arbol.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

