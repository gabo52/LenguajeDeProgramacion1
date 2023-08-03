/* 
 * File:   Persona.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 09:45 PM
 */

#include <cstring>

#include "Persona.h"

Persona::Persona() {
    distrito=nullptr;
    nombre=nullptr;
    codigo = 0;
}


Persona::~Persona() {
    delete distrito;
    delete nombre;
}

void Persona::SetDistrito(char* cad) {
    if(distrito)delete distrito;
    if(cad){
        distrito =  new char [strlen(cad)+1];
        strcpy(distrito,cad);
    }else{
        distrito =  new char [2];
        strcpy(distrito,"0");
    }
}

void Persona::GetDistrito(char *cad) const {
    if(distrito)strcpy(cad,distrito);
    else strcpy(cad,"0");
}

void Persona::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Persona::GetCodigo() const {
    return codigo;
}

void Persona::SetNombre(char* cad) {
    if(nombre)delete nombre;
    if(cad){
        nombre =  new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre =  new char [2];
        strcpy(nombre,"0");
    }
}

void Persona::GetNombre(char *cad) const {
    if(nombre)strcpy(cad,nombre);
    else strcpy(cad,"0");
}


void Persona::operator = (const Persona &c) {
    SetCodigo(c.GetCodigo());
    char cadena[200];
    c.GetDistrito(cadena);
    SetDistrito(cadena);
    c.GetNombre(cadena);
    SetNombre(cadena);
}
