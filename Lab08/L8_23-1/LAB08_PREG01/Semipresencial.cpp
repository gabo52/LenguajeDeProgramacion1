#include "Semipresencial.hpp"

Semipresencial::Semipresencial() {
    this->descuento = 0.0;
    this->total = 0.0;
}

double Semipresencial::getDescuento() const {
    return descuento;
}

void Semipresencial::setDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::getTotal() const {
    return total;
}

void Semipresencial::setTotal(double total) {
    this->total = total;
}


