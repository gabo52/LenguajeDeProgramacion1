/* 
 * File:   Lista.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 05:03 PM
 */

#include "Lista.h"

Lista::Lista() {
    lini=nullptr;
    lfin=nullptr;
}


Lista::~Lista() {
    Nodo *p=lini,*sale=nullptr;
    while(p){
        sale = p;
        p=p->sig;
        delete sale;
    }
}


void Lista::insertar(Pedido *pedido){
    Nodo *p=lini,*nuevo,*rec=nullptr;
    nuevo = new class Nodo;
    nuevo->ped=pedido;
    while(p){
        if((p->ped->GetDni() < pedido->GetDni())|| 
            (( p->ped->GetDni() == pedido->GetDni() )  && (p->ped->GetFecha() > pedido->GetFecha())))break;
        rec = p;
        p = p->sig;
    }
    
    nuevo->sig=p;
    if(p){
        p->ant=nuevo;
    }
    
    if(rec==nullptr){
        if(p==nullptr)lfin=nuevo;
        lini=nuevo;
    }else{
        rec->sig=nuevo;
        nuevo->ant = rec;
        if(rec==lfin)lfin = nuevo;
    }
}

void Lista::imprimir(ofstream &arch){
    imprimeLista(lini,arch);
}

void Lista::imprimeLista(Nodo *lista,ofstream &arch){
    Nodo *p=lista;
    while(p){
        p->ped->imprime(arch);
        p=p->sig;
    }
}

void Lista::actualizaLista(int cod,int fec){
    Nodo *aux=lfin;
    int flag=1;
    while(aux&&flag){
        if(cod==aux->ped->GetDni()){
            if(aux->ped->GetFecha()<fec){
                aux->ped->actualizaFlete();
            }
            if(aux->ant){
                if(cod!=aux->ant->ped->GetDni())break;
            }
        }
        aux=aux->ant;
    }
}
