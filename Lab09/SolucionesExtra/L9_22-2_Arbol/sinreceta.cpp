/* 
 * File:   sinreceta.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371 
 * Created on 17 de noviembre de 2022, 06:57 PM
 */

#include "sinreceta.h"
#include <cstring>
sinreceta::sinreceta() {
    nombre=nullptr;
}


sinreceta::~sinreceta(){
    if(nombre)delete nombre;
}

void sinreceta::SetNombre(char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void sinreceta::GetNombre(char *cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int sinreceta::GetDni() const {
    return dni;
}

void sinreceta::asigna(int cod,char *nombreMed,int cant,double prec,
    int fech,int codmed,char *esp,int dni,char *nombrePac){
    SetCantidad(cant);
    SetCodigo(cod);
    SetDni(dni);
    SetFecha(fech);
    SetNombre(nombrePac);
    SetNombreMedicamento(nombreMed);
    SetPrecio(prec);
}

void sinreceta::imprime(ofstream &arch){
    char cad[200];
    GetNombreMedicamento(cad);
    arch<<setw(10)<<left<<GetCodigo()<<setw(50)<<left<<cad<<setw(10)<<left<<
            GetCantidad();
    GetNombre(cad);
    arch<<setw(15)<<left<<GetDni()<<left<<cad<<endl;
}

