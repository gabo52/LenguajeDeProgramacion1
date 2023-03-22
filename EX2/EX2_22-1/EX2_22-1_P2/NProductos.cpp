/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 03:09 PM
 */

#include "NProductos.h"

NProductos::NProductos() {
    prod=nullptr;
}

NProductos::~NProductos() {
    delete &prod;
}

void NProductos::leer(ifstream &arch){
    int num;
    char c;
    arch>>num>>c;
    if(arch.eof())return;
    if(num==1){
        prod =  new class Categoria1;
    }else if(num==2){
        prod =  new class Categoria2;   
    }else{
        prod =  new class Categoria3; 
    }
    prod->leer(arch);
}

void NProductos::imprime(ofstream &arch){
    prod->imprime(arch);
}


void NProductos::GetPrioridad(int &prioridad,int &cod){
    cod=prod->GetCodprod();
    prioridad=prod->obtienePrioridad();
}