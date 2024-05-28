//
// Created by errant on 28/05/24.
//

#include "Escala.hpp"

Escala::~Escala() {

}

Escala::Escala(){
    codigo = 0;
    precio = 0.0;
}

int Escala::getCodigo() const {
    return codigo;
}

void Escala::setCodigo(int codigo) {
    Escala::codigo = codigo;
}

double Escala::getPrecio() const {
    return precio;
}

void Escala::setPrecio(double precio) {
    Escala::precio = precio;
}

