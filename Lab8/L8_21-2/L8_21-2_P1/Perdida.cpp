/* 
 * File:   Perdida.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:36 PM
 */

#include "Perdida.h"


void Perdida::SetPrecio(double precio) {
    this->precio = precio;
}

double Perdida::GetPrecio() const {
    return precio;
}

void Perdida::operator = (const Perdida &c){
    SetPrecio(c.GetPrecio());
}

void Perdida::imprimePerdida(ofstream &arch){
    arch<<setw(20)<<left<<"Perdida:"<<setw(10)<<left<<"Precio"<<setw(8)
            <<right<<GetPrecio()<<endl;
}
