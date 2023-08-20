/* 
 * File:   Prestamo.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:31 PM
 */

#include "Prestamo.h"

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

void Prestamo::operator = (const Prestamo &c){
    SetDias(c.GetDias());
    SetFecha(c.GetFecha());
}

void Prestamo::imprimePrestamo(ofstream &arch){
        arch<<setw(20)<<left<<"PrestamoDias:"<<GetDias()<<endl;
}