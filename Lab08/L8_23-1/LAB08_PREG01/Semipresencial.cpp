//
// Created by errant on 28/05/24.
//

#include "Semipresencial.hpp"

Semipresencial::Semipresencial() {
    this->descuento = 0.0;
    this->total = 0.0;
}

double Semipresencial::getDescuento() const {
    return descuento;
}

void Semipresencial::setDescuento(double descuento) {
    Semipresencial::descuento = descuento;
}

double Semipresencial::getTotal1() const {
    return total;
}

void Semipresencial::setTotal1(double total) {
    Semipresencial::total = total;
}


