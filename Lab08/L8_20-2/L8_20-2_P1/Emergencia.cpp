/* 
 * File:   Emergencia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:47 AM
 */

#include "Emergencia.h"
#include <cstring>
Emergencia::Emergencia() {
    nombreRef = nullptr;
    
}


Emergencia::~Emergencia() {
    if(nombreRef)delete nombreRef;
}

void Emergencia::SetNombreRef(char* cad) {
    if(nombreRef)delete nombreRef;
    if(cad){
        nombreRef=new char [strlen(cad)+1];
        strcpy(nombreRef,cad);
    }else{
        nombreRef=new char [2];
        strcpy(nombreRef,"0");
    }
}

void Emergencia::GetNombreRef(char *cad) const {
    if(nombreRef)strcpy(cad,nombreRef);
    else strcpy(cad,"0");
}

void Emergencia::SetTelefonoRef(int telefonoRef) {
    this->telefonoRef = telefonoRef;
}

int Emergencia::GetTelefonoRef() const {
    return telefonoRef;
}

void Emergencia::operator=(const Emergencia& c) {
    SetDni(c.GetDni());
    SetTelefonoRef(c.GetTelefonoRef());
    char cad[200];
    c.GetCodMed(cad);
    SetCodMed(cad);
    c.GetNombre(cad);
    SetNombre(cad);
    c.GetNombreRef(cad);
    SetNombreRef(cad);
}


