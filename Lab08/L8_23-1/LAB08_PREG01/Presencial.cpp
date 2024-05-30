#include "Presencial.hpp"

Presencial::Presencial() {
    recargar = 0.0;
    total = 0.0;
}

Presencial::~Presencial() {

}

double Presencial::getRecargar() const {
    return recargar;
}

void Presencial::setRecargar(double recargar) {
    this->recargar = recargar;
}

double Presencial::getTotal() const {
    return total;
}

void Presencial::setTotal(double total) {
    this->total = total;
}
