/* 
 * File:   Persona.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:08 PM
 */

#include <cstring>

#include "Persona.h"

Persona::Persona() {
    codigo=0;
    distrito=nullptr;
    nombre=nullptr;
}

void Persona::SetDistrito(char* cad) {
    if(distrito)delete distrito;
    distrito = new char [strlen(cad)+1];
    strcpy(distrito,cad);
}

void Persona::GetDistrito(char* cad) const {
    if(distrito)strcpy(cad,distrito);
    else cad[0]=0;
}


Persona::~Persona() {
    if(distrito)delete distrito;
    if(nombre)delete nombre;
}


void Persona::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Persona::GetCodigo() const {
    return codigo;
}

void Persona::SetNombre(char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Persona::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void Persona::lee(ifstream &arch){
    char cad[80],c;
    int cod;
    arch.getline(cad,80,',');
    if(arch.eof())return;
    arch>>cod>>c;
    SetCodigo(cod);
    SetNombre(cad);
    arch.getline(cad,80,',');
    SetDistrito(cad);
}

