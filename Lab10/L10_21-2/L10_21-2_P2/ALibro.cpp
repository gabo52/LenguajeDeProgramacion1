/* 
 * File:   ALibro.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 09:41 PM
 */

#include <cstring>

#include "ALibro.h"
#include "NLibro.h"

ALibro::ALibro() {
    Raiz=nullptr;
}


ALibro::~ALibro() {
}

void ALibro::insertar(Libro &lib){
    insertarArbol(Raiz,lib);
}

void ALibro::insertarArbol(NLibro *&arbol,Libro &lib){
    if(arbol==nullptr){
        NLibro *nodo;
        nodo = new class NLibro;
        nodo->dlibro=lib;
        arbol=nodo;
        return;
    }
    if((arbol->dlibro>lib)>0){
        insertarArbol(arbol->der,lib);
    }else insertarArbol(arbol->izq,lib);
}

void ALibro::imprimir(ofstream &arch){
    imprimeArbol(Raiz,arch);
}

void ALibro::imprimeArbol(NLibro *NLibro,ofstream &arch){
    if(NLibro==nullptr)return;
    imprimeArbol(NLibro->der,arch);
    arch<<NLibro->dlibro;
    imprimeArbol(NLibro->izq,arch);
}

void ALibro::actualiza(char *cod){
    actualizaArbol(Raiz,cod);
}

void ALibro::actualizaArbol(NLibro *arbol,char *cod){
    if(arbol){
        char cad[80];
        int i;
        arbol->dlibro.GetCodigo(cad);
        i=strcmp(cad,cod);
        if(i==0){
            arbol->dlibro.actualiza();
        }else{
            if(i>0){
                actualizaArbol(arbol->der,cod);
            }else actualizaArbol(arbol->izq,cod);
        }
    }
}
