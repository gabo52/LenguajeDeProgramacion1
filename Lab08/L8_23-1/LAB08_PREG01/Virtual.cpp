#include "Virtual.hpp"

Virtual::Virtual() {

}

Virtual::~Virtual() {

}

void Virtual::getLicencia(char *licencia) const {
    if (this->licencia == nullptr) licencia[0] = 0;
    else strcpy(licencia, this->licencia);
}

void Virtual::setLicencia(char *licencia) {
    if (this->licencia != nullptr) delete this->licencia;
    this->licencia = new char[strlen(licencia) + 1];
    strcpy(this->licencia, licencia);
}

double Virtual::getTotal() const {
    return total;
}

void Virtual::setTotal(double total) {
    Virtual::total = total;
}
