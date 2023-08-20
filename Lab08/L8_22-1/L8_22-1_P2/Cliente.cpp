/* 
 * File:   Cliente.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371 
 * Created on 9 de noviembre de 2022, 05:26 PM
 */

#include <cstring>

#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    dni = 0;
}


Cliente::~Cliente() {
    if(nombre)delete nombre;
}

void Cliente::SetNombre(char* cad) {
    if(nombre)delete nombre;
    if(cad){
        nombre = new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre = new char [2];
        nombre[0]=0;
    }
}

void Cliente::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator = (const Cliente &c){
    char cad[80];
    c.GetNombre(cad);
    SetNombre(cad);
    SetCategoria(c.GetCategoria());
    SetDni(c.GetDni());
}
