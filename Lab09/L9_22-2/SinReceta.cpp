/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinReceta.cpp
 * Author: cueva
 * 
 * Created on 5 de noviembre de 2022, 10:23 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "SinReceta.h"

using namespace std;

SinReceta::SinReceta() {
    dni=0;
    nombre=nullptr;
}

SinReceta::SinReceta(const SinReceta& orig) {
}

SinReceta::~SinReceta() {
}

void SinReceta::SetNombrepac(char* cad) {
    if(nombre!=NULL) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void SinReceta::GetNombrepac(char *cad) const {
    strcpy(cad,nombre);
}

void SinReceta::SetDni(int dni) {
    this->dni = dni;
}

int SinReceta::GetDni() const {
    return dni;
}
/*
41379,5,12/02/2023,50611,51642949,Miranda/Alfonso
30796,5,13/02/2023,50611,51642950,Miranda/Alfonso
 */ 
void SinReceta::leemedicamento(ifstream&arch, int codmed){
    int coddoc,dni;
    char nomdoc[50],c;
    
    medicamento::leemedicamento(arch,codmed); //llama explicita
    arch >> coddoc >> c >> dni >> c;
    arch.getline(nomdoc,50);
    this->SetDni(dni);
    this->SetNombrepac(nomdoc);
    
}

void SinReceta::aplicadescuento(){
    medicamento::aplicadescuento();
    this->SetTotal(this->GetTotal()*0.9);
}

void SinReceta::imprimemedicamento(ofstream &arch){
    medicamento::imprimemedicamento(arch);
    arch << setw(10) << dni << setw(40) << nombre <<endl;
    
}

