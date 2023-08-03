/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conreceta.cpp
 * Author: cueva
 * 
 * Created on 11 de junio de 2023, 10:44 AM
 */
#include <cstring>
#include "conreceta.h"

using namespace std;

conreceta::conreceta() {
    codmed=0;
    especialidad=nullptr;
}

conreceta::conreceta(const conreceta& orig) {
}

conreceta::~conreceta() {
}

void conreceta::SetEspecialidad(char* cad) {
    if(especialidad!=nullptr) delete especialidad;
    especialidad = new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

void conreceta::GetEspecialidad(char* cad) const {
    strcpy(cad,especialidad);
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}

void conreceta::leeconreceta(int codmed, char*esp, int cant, int codigo, int fecha){
    this->codmed = codmed;
    this->SetEspecialidad(esp);
    this->SetCantidad(cant);
    this->SetFecha(fecha);
    this->leemedicamento(codigo);
    
}