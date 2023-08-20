/* 
 * File:   Paciente.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de noviembre de 2022, 11:31 AM
 */

#include <cstddef>
#include <cstring>
#include "Paciente.h"

Paciente::Paciente() {
    codMed=nullptr;
    dni=0;
    nombre=nullptr;
}



Paciente::~Paciente() {
    if(codMed)delete codMed;
    if(nombre)delete nombre;
}

void Paciente::SetCodMed(char* cad) {
    if(codMed)delete codMed;
    codMed = new char [strlen(cad)+1];
    strcpy(codMed,cad);
}

void Paciente::GetCodMed(char* cad) const {
    if(codMed)strcpy(cad,codMed);
    else cad[0]=0;
}

void Paciente::SetNombre(char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Paciente::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void Paciente::SetDni(int dni) {
    this->dni = dni;
}

int Paciente::GetDni() const {
    return dni;
}





