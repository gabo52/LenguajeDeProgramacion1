/* 
 * File:   Disponible.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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