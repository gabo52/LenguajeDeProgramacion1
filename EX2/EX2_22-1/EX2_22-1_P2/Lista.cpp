/* 
 * File:   Lista.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:11 PM
 */

#include "Lista.h"

Lista::Lista() {
    lini=nullptr;
    lfin=nullptr;
}

Lista::~Lista() {
    Nodo *p=lini,*sale;
    while(p){
        sale=p;
        p=p->sig;
        delete sale;
    }
}


void Lista::inserta(Pedido &pedido){
    Nodo *p=lini,*nuevo,*ant=nullptr;
    nuevo = new class Nodo;
    nuevo->ped=pedido;
    while(p){
        if(p->ped>pedido)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant==nullptr){
        if(p==nullptr)lfin=nuevo;
        lini=nuevo;
    }else{
        ant->sig=nuevo;
        if(ant==lfin)lfin=nuevo;
    }
}

void Lista::imprime(ofstream &arch){
    Nodo *p=lini;
    while(p){
        p->ped.imprime(arch);
        p=p->sig;
    }
}

void Lista::actualizaPrioridad(int prioridad,int cod){
    Nodo *p=lini;
    while(p){
        if(p->ped.GetCodigo()==cod){
            p->ped.SetOrden(prioridad);
        }
        p=p->sig;
    }
}

void Lista::reordenar(){
    Nodo *p=lini,*ant=nullptr,*sale;
    while(p){
        if(p->ped.GetOrden()==1){
            insertarAlInicio(p->ped);
            sale=p;
            if(ant)ant->sig=p->sig;
            p=ant;
            delete sale;
        }
        ant=p;
        p=p->sig;
    }
}

void Lista::insertarAlInicio(Pedido &pedido){
    Nodo *nuevo;
    nuevo = new class Nodo;
    nuevo->ped=pedido;
    if(lini==nullptr){
        lini=nuevo;
        lfin=nuevo;
        return;
    }
    nuevo->sig=lini;
    lini=nuevo;
}
