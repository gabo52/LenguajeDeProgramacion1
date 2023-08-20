/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conreceta.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:07 PM
 */

#include "conreceta.h"
#include <cstring>
conreceta::conreceta() {
    especialidad=nullptr;
}



conreceta::~conreceta() {
    if(especialidad)delete especialidad;
}

void conreceta::SetEspecialidad(char* cad) {
    if(especialidad)delete especialidad;
    especialidad = new char [strlen(cad)+1];
    strcpy(especialidad,cad);
}

void conreceta::GetEspecialidad(char* cad) const {
    if(especialidad)strcpy(cad,especialidad);
    else cad[0]=0;
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}

void conreceta::asignar(int medicamento,char *nombMedicamento,int cant,double precio,
            int fecha,int codmed,char *esp,int dni,char *nombPac){
    SetCantidad(cant);
    SetCodigo(medicamento);
    SetCodmed(codmed);
    SetEspecialidad(esp);
    SetFecha(fecha);
    SetNombreMedicamento(nombMedicamento);
    SetPrecio(precio);
}

void conreceta::imprime(ofstream &arch){
    char cad[80];
    GetNombreMedicamento(cad);
    arch<<setw(12)<<left<<GetCodigo()<<setw(50)<<left<<cad<<setw(10)<<left<<GetCantidad();
    GetEspecialidad(cad);
    arch<<setw(18)<<left<<GetCodmed()<<left<<cad<<endl;
}

