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
    this->codigo = codigo;
}

double Escala::getPrecio() const {
    return precio;
}

void Escala::setPrecio(double precio) {
    this->precio = precio;
}

