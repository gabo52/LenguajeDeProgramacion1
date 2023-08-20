/* 
 * File:   Leve.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:42 PM
 */

#include "Leve.h"

Leve::Leve() {
    descuento=0;
}

Leve::~Leve() {
    
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

void Leve::operator = (const Leve &c){
    SetCodigo(c.GetCodigo());
    SetDescuento(c.GetDescuento());
    SetFecha(c.GetFecha());
    char cad[100];
    c.GetGravedad(cad);
    SetGravedad(cad);
    SetMulta(c.GetMulta());
    c.GetPlaca(cad);
    SetPlaca(cad);
}


void Leve::imprime(ofstream &arch){
    char placa[20];
    GetPlaca(placa);
    arch<<setw(15)<<" ";
    imprimeFecha(arch,GetFecha());
    arch<<setw(16)<<" "<<placa<<endl;
}

