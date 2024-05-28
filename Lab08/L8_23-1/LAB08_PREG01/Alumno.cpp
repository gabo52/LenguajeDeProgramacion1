#include "Utils.hpp"
#include "Alumno.hpp"

int Alumno::getCodigo() const {
    return codigo;
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Alumno::getNombre(char *nombre) const {
    if(this->nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre,this->nombre);
}

void Alumno::setNombre(const char *nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Alumno::getEscala() const {
    return escala;
}

void Alumno::setEscala(int escala) {
    this->escala = escala;
}

double Alumno::getTotal() const {
    return total;
}

void Alumno::setTotal(double total) {
    this->total = total;
}
