

/* 
 * File:   Disponible.cpp
 * Author: USER
 * 
 * Created on 21 de junio de 2023, 07:02 PM
 */

#include <iomanip>
#include <iostream>
#include "Disponible.h"
using namespace std;

Disponible::Disponible() {
}

Disponible::Disponible(const Disponible& orig) {
}

Disponible::~Disponible() {
}

void Disponible::SetZona(int zona) {
    this->zona = zona;
}

int Disponible::GetZona() const {
    return zona;
}

void Disponible::cargadatos(char *codlib, char *tit, char *aut, int cant, double prec, int zone){
    SetCodigo(codlib);
    SetTitulo(tit); 
    SetAutor(aut);
    SetCantidad(cant);
    SetPrecio(prec);
    SetZona(zone); 
}

void Disponible::imprimir(ofstream &arch){
    arch << setw(20) << left << "Disponible" << setw(10) << "Zona" << setw(4) << right << GetZona() << endl;
}