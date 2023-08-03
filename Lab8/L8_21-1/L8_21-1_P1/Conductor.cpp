/* 
 * File:   Conductor.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:33 PM
 */

#include <cstring>

#include "Conductor.h"

Conductor::Conductor() {
    licencia=0;
    nombre=nullptr;
}

Conductor::~Conductor() {
    if(nombre)delete nombre;
}

void Conductor::SetNombre(char* cad) {
    if(nombre)delete nombre;
    if(cad){
        nombre = new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre = new char[2];
        strcpy(nombre,"0");
    }
}

void Conductor::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else strcpy(cad,"0");
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

void Conductor::operator = (const Conductor &c){
    SetLicencia(c.GetLicencia());
    char cad[200];
    c.GetNombre(cad);
    SetNombre(cad);
}
