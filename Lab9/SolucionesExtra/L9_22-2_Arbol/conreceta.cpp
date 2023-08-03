/* 
 * File:   conreceta.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 06:54 PM
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

void conreceta::asigna(int cod,char *nombreMed,int cant,double prec,
    int fech,int codmed,char *esp,int dni,char *nombrePac){
    SetCantidad(cant);
    SetCodigo(cod);
    SetCodmed(codmed);
    SetEspecialidad(esp);
    SetFecha(fech);
    SetNombreMedicamento(nombreMed);
    SetPrecio(prec);
}

void conreceta::imprime(ofstream &arch){
    char cad[200];
    GetNombreMedicamento(cad);
    arch<<setw(10)<<left<<GetCodigo()<<setw(50)<<left<<cad<<setw(10)<<left<<
            GetCantidad();
    GetEspecialidad(cad);
    arch<<setw(15)<<left<<GetCodmed()<<left<<cad<<endl;
}

