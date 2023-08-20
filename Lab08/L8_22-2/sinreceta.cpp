/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sinreceta.cpp
 * Author: cueva
 * 
 * Created on 11 de junio de 2023, 11:00 AM
 */
#include <cstring>
#include "sinreceta.h"
#include "medicamento.h"

using namespace std;


sinreceta::sinreceta() {
    dni=0;
    nombre=nullptr;
}

sinreceta::sinreceta(const sinreceta& orig) {
}

sinreceta::~sinreceta() {
}
void sinreceta::SetNombre(char* cad) {
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void sinreceta::GetNombre(char* cad) const {
    strcpy(cad,nombre);
}

void sinreceta::SetDni(int dni) {
    this->dni = dni;
}
int sinreceta::GetDni() const {
    return dni;
}

void sinreceta::leesinreceta(int codigo,int fecha,char *cad,int dni){
    leemedicamento(codigo);    
    SetFecha(fecha);
    SetNombre(cad);
    this->dni = dni;
}
