/* 
 * File:   Arbol.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 07:17 PM
 */

#include "Arbol.h"
#include "medico.h"

Arbol::Arbol() {
    arbol=nullptr;
}


Arbol::~Arbol() {
    //por implementar
}


void Arbol::insertar(NodoArbol *&nodo,medicamento *med){
    if(nodo==nullptr){
        nodo = new class NodoArbol;
        nodo->dato=med;
        return;
    }
    if(med>nodo->dato){
        insertar(nodo->der,med);
    }else insertar(nodo->izq,med);
}

void Arbol::insertarArbol(medicamento *med){
    if(arbol==nullptr){
        arbol = new class NodoArbol;
        arbol->dato=med;
        return;
    }
    insertar(arbol,med);
}


void Arbol::imprimir(ofstream &arch){
    imprime(arch,arbol);
}
void Arbol::imprime(ofstream &arch,NodoArbol *nodo){
    if(nodo==nullptr)return;
    imprime(arch,nodo->izq);
    //arch<<((*nodo).dato);
    nodo->dato->imprime(arch);
    imprime(arch,nodo->der);
}


