/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 08:40 PM
 */

#include <cstring>

#include "Conductor.h"

Conductor::Conductor() {
    nombre=nullptr;
}

Conductor::Conductor(const Conductor& orig) {
    *this=orig;
}

Conductor::~Conductor() {
    if(nombre)delete nombre;
}

void Conductor::SetNombre(char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Conductor::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

void Conductor::operator =(const Conductor &c){
    char cad[80];
    c.GetNombre(cad);
    SetNombre(cad);
    SetLicencia(c.GetLicencia());
}

void Conductor::leer(ifstream &arch){
    int cod;
    char cad[80],c;
    arch>>cod>>c;
    if(arch.eof())return;
    arch.getline(cad,80,'\n');
    SetLicencia(cod);
    SetNombre(cad);
}

void Conductor::imprimir(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(12)<<left<<GetLicencia()<<setw(40)<<left<<cad;
}

