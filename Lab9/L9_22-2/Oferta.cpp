/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oferta.cpp
 * Author: cueva.r
 * 
 * Created on 14 de junio de 2023, 10:58 AM
 */

#include "Oferta.h"
#include "ConReceta.h"
#include "SinReceta.h"

Oferta::Oferta() {
    poferta=nullptr;
}

Oferta::Oferta(const Oferta& orig) {
}

Oferta::~Oferta() {
}

void Oferta::leeoferta(ifstream &arch, int codmed){
    
    if((codmed/10000)%2==0){
        //con receta
        poferta = new ConReceta;
    }
    else{
        poferta = new SinReceta;
        //sin receta
    }
    poferta->leemedicamento(arch,codmed);
}
int Oferta::existe(){
    if(poferta==nullptr) return 0;
    return 1;
}

void Oferta::aplicadescuento(){
    poferta->aplicadescuento(); //este es el polimorfico
    
}

void Oferta::imprimeoferta(ofstream&arch){
    poferta->imprimemedicamento(arch);
    
}