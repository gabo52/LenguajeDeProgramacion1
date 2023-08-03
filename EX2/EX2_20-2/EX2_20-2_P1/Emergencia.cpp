/* 
 * File:   Emergencia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:20 PM
 */

#include <cstring>

#include "Emergencia.h"

Emergencia::Emergencia() {
    nombreRef=nullptr;
}


Emergencia::~Emergencia() {
    if(nombreRef)delete nombreRef;
}

void Emergencia::SetNombreRef(char* cad) {
    if(nombreRef)delete nombreRef;
    nombreRef = new char[strlen(cad)+1];
    strcpy(nombreRef,cad);
}

void Emergencia::GetNombreRef(char* cad) const {
    if(nombreRef)strcpy(cad,nombreRef);
    else cad[0]=0;
}

void Emergencia::SetTelefonoRef(int telefonoRef) {
    this->telefonoRef = telefonoRef;
}

int Emergencia::GetTelefonoRef() const {
    return telefonoRef;
}

void Emergencia::leer(ifstream &arch){
    int dni,telef,edad;
    char cad[100],c;
    double porc,urg;
    arch>>dni>>c;
    arch.getline(cad,100,',');
    SetNombre(cad); 
    arch>>edad>>c;
    arch.getline(cad,100,',');
    SetCodMed(cad);
    arch.getline(cad,100,',');
    SetNombreRef(cad);
    arch>>telef;
    arch.get();
    SetDni(dni);
    SetEdad(edad);
    SetTelefonoRef(telef);
}


int Emergencia::prioridad(){
    return 300+GetEdad();
}

void Emergencia::observacion(char *cad){
    if(GetEdad()>65){
        strcpy(cad,"Persona de Riesgo");
    }else cad[0]=0;
}

void Emergencia::imprimir(ofstream &arch){
    char cad[100];
    GetNombre(cad);
    arch<<setw(15)<<left<<GetDni()<<setw(50)<<left<<cad<<setw(8)<<left<<GetEdad();
    
    observacion(cad);
    arch<<setw(50)<<left<<cad;
    
    GetNombreRef(cad);
    arch<<setw(25)<<left<<cad<<left<<GetTelefonoRef()<<endl;
}

