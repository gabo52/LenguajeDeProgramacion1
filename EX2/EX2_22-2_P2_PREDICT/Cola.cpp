/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 07:18 PM
 */

#include "Cola.h"

Cola::Cola() {
    ini=nullptr;
    fin=nullptr;
}


Cola::~Cola() {
    
}

void Cola::encola(medicamento *&med){
    NCola *nuevo;
    nuevo = new class NCola;
    nuevo->med=med;
    nuevo->sig=nullptr;
    if(ini==nullptr){
        ini = nuevo;
        fin=nuevo;
        return;
    }
    fin->sig=nuevo;
    fin=nuevo;
}

void Cola::desencola(medicamento *&med){
    if(ini==nullptr){
        med=nullptr;
        return;
    }
    NCola *aux=ini;
    med=aux->med;
    if(ini==fin){
        fin=nullptr;
        ini=nullptr;
    }else ini=ini->sig;
    delete aux;
}

bool Cola::empty(){
    return ini==nullptr;
}

