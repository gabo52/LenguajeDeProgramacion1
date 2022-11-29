/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 06:08 PM
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz=nullptr;
}

Arbol::~Arbol() {
}

void Arbol::inserta(medicamento *&med){
    insertaArbol(raiz,med);
}

void Arbol::insertaArbol(NArbol *&nodo,medicamento *&med){
    if(nodo==nullptr){
        nodo=new class NArbol;
        nodo->med=med;
        return;
    }
    if(nodo->med->GetCodigo()<med->GetCodigo()){
        insertaArbol(nodo->der,med);
    }else insertaArbol(nodo->izq,med);
}

void Arbol::imprimir(ofstream &arch){
    imprimeArbol(raiz,arch);
}

void Arbol::imprimeArbol(NArbol *&nodo,ofstream &arch){
    if(nodo==nullptr)return;
    imprimeArbol(nodo->izq,arch);
    nodo->med->imprime(arch);
    imprimeArbol(nodo->der,arch);
}



void Arbol::eliminar(int codigo){
    //eliminarNodo(36711,raiz);
    eliminarNodosMayores(codigo,raiz);
}

void Arbol::eliminarNodosMayores(int codigo,NArbol *&nodo){
    if(nodo==nullptr)return;
    int cod=nodo->med->GetCodigo();
    if(nodo->der){
        if(nodo->der->med->GetCodigo()>=codigo)
            eliminarNodosMayores(codigo,nodo->der);
        if(nodo==nullptr)return;
    }
    if(nodo->med->GetCodigo()>=codigo){
        NArbol *aux=nodo;
        eliminarNodo(cod,nodo);
        if(nodo==nullptr)return;
        cod=nodo->med->GetCodigo();
        if(nodo->med->GetCodigo()>=codigo)eliminarNodosMayores(codigo,nodo);
        if(nodo==nullptr)return;
    }
    if(nodo->izq){
        if(nodo->izq->med->GetCodigo()>=codigo)
            eliminarNodosMayores(codigo,nodo->izq);
    }
//    if(nodo->med->GetCodigo()>=codigo){
//        NArbol *aux=nodo;
//        eliminarNodo(codigo,nodo);
//        if(nodo==nullptr)return;
//        eliminarNodosMayores(codigo,nodo->izq);
//    }else{
//        eliminarNodosMayores(codigo,nodo->der);
//    }
}

void Arbol::eliminarNodo(int codigo,NArbol *&nodo){
    if (nodo){
            //CD: se ha encontrado el nodo que se desea eliminar
            if (nodo->med->GetCodigo()==codigo){
                    cout<<"Llegue";
                    NArbol *nodo_a_eliminar;
                    if (!nodo->der){
                            nodo_a_eliminar=nodo;
                            nodo=nodo->izq;
                            delete nodo_a_eliminar;
                    }
                    else if (!nodo->izq){
                            nodo_a_eliminar=nodo;
                            nodo=nodo->der;
                            delete nodo_a_eliminar;
                    }
                    else eliminar_auxiliar(nodo,nodo->der);
            }
            //CR1: el nodo que se quiere eliminar es menor que la raÃ­z del Ã¡rbol pasado como parÃ¡metro
            else if (nodo->med->GetCodigo()<codigo)
                    eliminarNodo(codigo, nodo->izq);
            //CR2: el nodo que se quiere eliminar es mayor que la raÃ­z del Ã¡rbol pasado como parÃ¡metro
            else    eliminarNodo(codigo, nodo->der);
    }
}

void Arbol::eliminar_auxiliar(class NArbol *&nodo, class NArbol *&nodoDer){
        if(nodoDer->izq){
            eliminar_auxiliar(nodo,nodoDer->izq);
        }else{
            nodo->med=nodoDer->med;
            NArbol *nodo_a_eliminar=nodoDer;
            nodoDer=nodoDer->der;
            //delete nodo_a_eliminar;
        }
//	if (!es_arbol_vacio((*arbol_derecha)->hijo_izq))
//		eliminar_auxiliar(tad, &(*arbol_derecha)->hijo_izq);
//	else{
//		(*tad)->elemento=(*arbol_derecha)->elemento;
//		ArbolBinarioBusqueda nodo_a_eliminar=*arbol_derecha;
//		*arbol_derecha=(*arbol_derecha)->hijo_der;
//		free(nodo_a_eliminar);
//	}
}



