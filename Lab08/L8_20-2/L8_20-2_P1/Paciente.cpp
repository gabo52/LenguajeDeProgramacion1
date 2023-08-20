/* 
 * File:   Paciente.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:36 AM
 */

#include <cstring>

#include "Paciente.h"

Paciente::Paciente() {
    codMed=nullptr;
    dni=0;
    nombre = nullptr;
}


Paciente::~Paciente() {
    if(codMed)delete codMed;
    if(nombre)delete nombre;
}

void Paciente::SetCodMed(char* cad) {
    if(codMed)delete codMed;
    if(cad){
        codMed=new char [strlen(cad)+1];
        strcpy(codMed,cad);
    }else{
        codMed=new char [2];
        strcpy(codMed,"0");
    }
}

void Paciente::GetCodMed(char *cad) const {
    if(codMed)strcpy(cad,codMed);
    else strcpy(cad,"0");
}

void Paciente::SetNombre(char* cad) {
    if(nombre)delete nombre;
    if(cad){
        nombre=new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre=new char [2];
        strcpy(nombre,"0");
    }
}

void Paciente::GetNombre(char *cad) const {
    if(nombre)strcpy(cad,nombre);
    else strcpy(cad,"0");
}

void Paciente::SetDni(int dni) {
    this->dni = dni;
}

int Paciente::GetDni() const {
    return dni;
}

