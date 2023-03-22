/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Disponible.cpp
 * Author: Gabo
 * 
 * Created on 10 de noviembre de 2022, 07:30 PM
 */

#include "Disponible.h"


void Disponible::SetZona(int zona) {
    this->zona = zona;
}

int Disponible::GetZona() const {
    return zona;
}

void Disponible::operator = (const Disponible &c){
    SetZona(c.GetZona());
}

void Disponible::imprimeDisponible(ofstream &arch){
    arch<<setw(20)<<left<<"Disponible"<<setw(10)<<left<<"Zona"<<setw(4)<<right
            <<GetZona()<<endl;
}