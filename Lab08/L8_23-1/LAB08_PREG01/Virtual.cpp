//
// Created by errant on 28/05/24.
//

#include "Virtual.hpp"

Virtual::Virtual() {

}

Virtual::~Virtual() {

}
void Virtual::getLicencia(char *licencia) const {
    if(this->licencia == nullptr) licencia[0] = 0;
    else strcpy(licencia,this->licencia);s
}

void Virtual::setLicencia(char *licencia) {
    Virtual::licencia = licencia;
}

double Virtual::getTotal() const {
    return total;
}

void Virtual::setTotal(double total) {
    Virtual::total = total;
}
