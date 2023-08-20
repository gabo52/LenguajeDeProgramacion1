/* 
 * File:   Cliente.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:44 AM
 */

#include <cstring>

#include "Cliente.h"


void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

Cliente::Cliente() {
    nombre=nullptr;
    dni=0;
    totalped=0;
    cantped=0;
}

Cliente::Cliente(const Cliente& orig) {
    
}

Cliente::~Cliente() {
    if(nombre)delete nombre;
}

void Cliente::SetTotalped(double totalped) {
    this->totalped = totalped;
}

double Cliente::GetTotalped() const {
    return totalped;
}

void Cliente::SetCantped(int cantped) {
    this->cantped = cantped;
}

int Cliente::GetCantped() const {
    return cantped;
}

void Cliente::SetNombre(const char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
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

