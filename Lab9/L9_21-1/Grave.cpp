

/* 
 * File:   Grave.cpp
 * Author: USER
 * 
 * Created on 20 de junio de 2023, 03:33 PM
 */

#include "Grave.h"

Grave::Grave() {
}

Grave::Grave(const Grave& orig) {
}

Grave::~Grave() {
}

void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

