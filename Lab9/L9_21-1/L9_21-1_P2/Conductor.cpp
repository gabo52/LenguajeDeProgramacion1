/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:23 PM
 */

#include <cstring>

#include "Conductor.h"

Conductor::Conductor() {
    nombre = nullptr;
    licencia=0;
}


Conductor::~Conductor() {
    if(nombre)delete nombre;
}

void Conductor::SetNombre(const char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Conductor::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

