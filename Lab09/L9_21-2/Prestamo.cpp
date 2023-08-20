

/* 
 * File:   Prestamo.cpp
 * Author: USER
 * 
 * Created on 21 de junio de 2023, 07:03 PM
 */

#include <iomanip>
#include <iostream>
#include "Prestamo.h"
using namespace std;

Prestamo::Prestamo() {
}

Prestamo::Prestamo(const Prestamo& orig) {
}

Prestamo::~Prestamo() {
}

void Prestamo::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Prestamo::GetFecha() const {
    return fecha;
}

void Prestamo::SetDias(int dias) {
    this->dias = dias;
}

int Prestamo::GetDias() const {
    return dias;
}

void Prestamo::actualiza(int dias, int fecha, double precio){
    this->Prestamo::SetDias(dias);
    this->Prestamo::SetFecha(fecha); 
}

void Prestamo::imprimir(ofstream &arch){
    arch << setw(20) << left << "PrestamoDias: " << GetDias() << endl;
}

