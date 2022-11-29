/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 08:47 PM
 */

#include "Nodo.h"
#include "Procesa.h"

Nodo::Nodo() {
    pcosto=nullptr;
}

Nodo::Nodo(const Nodo &orig){
    this->pcosto=orig.pcosto;
    this->chofer=orig.chofer;
}

Nodo::~Nodo() {
    delete &pcosto;
}

void Nodo::leer(ifstream &arch){
    chofer.leer(arch);
    if(arch.eof())return;
    int cod=chofer.GetLicencia();
    cod/=10000000;
    if(cod>=5){
        pcosto = new class Nuevo;
    }else pcosto = new class Antiguo;
    ifstream arch2;
    AbrirArchivo("RegistroConsolidado.csv",arch2);
    pcosto->leer(arch2,chofer.GetLicencia());
}

void Nodo::imprime(ofstream &arch){
    chofer.imprimir(arch);
    pcosto->imprimir(arch);
}

bool Nodo::operator < (const Nodo &c){
    return chofer.GetLicencia()<c.chofer.GetLicencia();
}

int Nodo::licencia(){
    return chofer.GetLicencia();
}

bool Nodo::activo(){
    return pcosto->activo();
}
