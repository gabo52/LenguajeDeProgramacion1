/* 
 * File:   ColaSol.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:40 PM
 */

#include <cstring>

#include "ColaSol.h"

ColaSol::ColaSol() {
    inicola=nullptr;
    fincola=nullptr;
    n=0;
}

void ColaSol::encola(char *codLib,int carne){
    NodoCola *nuevo=new NodoCola;
    nuevo->sig=nullptr;
    nuevo->SetCarne(carne);
    nuevo->SetLibsol(codLib);
    n++;
    if(inicola==nullptr){
        inicola=nuevo;
        fincola=nuevo;
        return;
    }
    fincola->sig=nuevo;
    fincola=nuevo;
}

void ColaSol::desencola(char *codLib,int &carne){
    NodoCola *aux;
    if(inicola==nullptr){
        carne=0;
        return;
    }
    n--;
    aux=inicola;
    strcpy(codLib,inicola->libsol);
    carne=inicola->carne;
    if(inicola==fincola){
        inicola=nullptr;
        fincola=nullptr;
    }else inicola=inicola->sig;
    delete aux;
}

bool ColaSol::notEmpty(){
    return n!=0;
}

int ColaSol::size(){
    return n;
}

