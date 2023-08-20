

/* 
 * File:   Leve.cpp
 * Author: USER
 * 
 * Created on 20 de junio de 2023, 03:33 PM
 */

#include "Leve.h"

Leve::Leve() {
}

Leve::Leve(const Leve& orig) {
}

Leve::~Leve() {
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

