/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:24 PM
 */

#include <cstring>

#include "Infraccion.h"

Infraccion::Infraccion() {
    codigo=0;
    gravedad=nullptr;
}


Infraccion::~Infraccion() {
    if(gravedad)delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(char* cad) {
    if(gravedad)delete gravedad;
    gravedad = new char [strlen(cad)+1];
    strcpy(gravedad,cad);
}

void Infraccion::GetGravedad(char* cad) const {
    if(gravedad)strcpy(cad,gravedad);
    else cad[0]=0;
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}


