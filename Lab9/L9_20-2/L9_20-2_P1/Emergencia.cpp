/* 
 * File:   Emergencia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de noviembre de 2022, 11:33 AM
 */

#include <cstring>

#include "Emergencia.h"

Emergencia::Emergencia() {
    nombreRef=nullptr;
}


Emergencia::~Emergencia() {
    if(nombreRef)delete nombreRef;
}

void Emergencia::SetNombreRef(const char* cad) {
    if(nombreRef)delete nombreRef;
    nombreRef = new char [strlen(cad)+1];
    strcpy(nombreRef,cad);
}

void Emergencia::GetNombreRef(char*cad) const {
    if(nombreRef)strcpy(cad,nombreRef);
    else cad[0]=0;
}

void Emergencia::SetTelefonoRef(int telefonoRef) {
    this->telefonoRef = telefonoRef;
}

int Emergencia::GetTelefonoRef() const {
    return telefonoRef;
}
void Emergencia::operator = (const Emergencia &c){
    char cad[80];
    SetTelefonoRef(c.GetTelefonoRef());
    c.GetNombreRef(cad);
    SetNombreRef(cad);
    c.GetCodMed(cad);
    SetCodMed(cad);
    SetDni(c.GetDni());
    c.GetNombre(cad);
    SetNombre(cad);
}


void Emergencia::leePaciente(ifstream &arch){
    int dni,telef;
    char nomb[80],nombEmer[80],carac,c,codMed[10];
    arch>>dni>>c;
    if(arch.eof())return;
    arch.getline(nomb,80,',');
    arch.getline(codMed,10,',');
    arch.getline(nombEmer,80,',');
    arch>>telef;
    arch.get();
    SetCodMed(codMed);
    SetDni(dni);
    SetNombre(nomb);
    SetNombreRef(nombEmer);
    SetTelefonoRef(telef);
}

void Emergencia::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(15)<<left<<GetDni()<<setw(50)<<left<<cad;
    GetCodMed(cad);
    arch<<setw(15)<<left<<cad;
    GetNombreRef(cad);
    arch<<setw(30)<<right<<cad<<setw(15)<<right<<GetTelefonoRef()<<endl;    
}

int Emergencia::seguro(){
    return 0;
}
int Emergencia::prioridad(){
    return 3;
}


