/* 
 * File:   Segunda.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:52 PM
 */

#include "Segunda.hpp"

using namespace std;

Segunda::Segunda() {
}

Segunda::Segunda(const Segunda& orig) {
}

Segunda::~Segunda() {
}

void Segunda::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Segunda::GetCreditos() const {
    return creditos;
}

void Segunda::leerNota(std::ifstream &file) {
}

void Segunda::imprime(std::ofstream &file) {
    char curso[10];
    this->GetCodcur(curso);
    file << left << setfill(' ') << setw(15) << this->GetCodigo()
            << setw(15) << curso
            << setw(15) << this->GetCiclo()
            << setw(15) << this->GetNota()
            << setw(10) << this->GetVez()
            << setw(15) << this->GetCreditos() << endl;
}
