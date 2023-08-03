/* 
 * File:   MuyGrave.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:50 PM
 */

#include "MuyGrave.h"
#include "Conductor.h"

MuyGrave::MuyGrave() {
    meses=0;
    puntos=0;
}

MuyGrave::~MuyGrave() {
}

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

void MuyGrave::operator = (const MuyGrave &c){
    SetCodigo(c.GetCodigo());
    SetFecha(c.GetFecha());
    char cad[100];
    c.GetGravedad(cad);
    SetGravedad(cad);
    SetMulta(c.GetMulta());
    c.GetPlaca(cad);
    SetPlaca(cad);
    SetPuntos(c.GetPuntos());
    SetMeses(c.GetMeses());
}

void MuyGrave::imprime(ofstream &arch){
    char placa[20];
    GetPlaca(placa);
    arch<<setw(15)<<" ";
    imprimeFecha(arch,GetFecha());
    arch<<setw(16)<<" "<<placa<<endl;
}


