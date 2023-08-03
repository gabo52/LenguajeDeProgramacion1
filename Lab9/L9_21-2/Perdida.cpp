

/* 
 * File:   Perdida.cpp
 * Author: USER
 * 
 * Created on 21 de junio de 2023, 07:04 PM
 */

#include <iomanip>
#include <iostream>
#include "Perdida.h"
using namespace std;

Perdida::Perdida() {
}

Perdida::Perdida(const Perdida& orig) {
}

Perdida::~Perdida() {
}

void Perdida::SetPrecio(double precio) {
    this->precio = precio;
}

double Perdida::GetPrecio() const {
    return precio;
}

void Perdida::actualiza(int dias, int fecha, double precio){
    this->Perdida::SetPrecio(precio);
}

void Perdida::imprimir(ofstream &arch){
    arch << setw(20) << left << "Perdida:" << setw(10) << "Precio" << setw(8) << right << this->Perdida::GetPrecio() << endl;
}
