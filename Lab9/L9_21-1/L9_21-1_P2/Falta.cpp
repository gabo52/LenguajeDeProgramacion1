/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:26 PM
 */

#include <cstring>

#include "Falta.h"

Falta::Falta() {
    placa=nullptr;
}


Falta::~Falta() {
    if(placa)delete placa;
}

void Falta::SetPlaca(char* cad) {
    if(placa)delete placa;
    placa = new char [strlen(cad)+1];
    strcpy(placa,cad);
}

void Falta::GetPlaca(char* cad) const {
    if(placa)strcpy(cad,placa);
    else cad[0]=0;
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}




