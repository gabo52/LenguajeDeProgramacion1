/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Perdida.cpp
 * Author: Gabo
 * 
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
