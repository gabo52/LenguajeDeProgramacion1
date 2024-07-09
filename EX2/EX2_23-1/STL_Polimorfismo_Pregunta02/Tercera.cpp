/* 
 * File:   Tercera.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:53 PM
 */

#include "Tercera.hpp"

using namespace std;

Tercera::Tercera() {
    porcentaje = 0.0;
}

Tercera::Tercera(const Tercera& orig) {
}

Tercera::~Tercera() {
}

void Tercera::SetPorcentaje(double porcentaje) {
    this->porcentaje = porcentaje;
}

double Tercera::GetPorcentaje() const {
    return porcentaje;
}

void Tercera::leerNota(std::ifstream &file) {
}

void Tercera::imprime(std::ofstream &file) {
    char curso[10];
    this->GetCodcur(curso);
    file << left << setfill(' ') << setw(15) << this->GetCodigo()
            << setw(15) << curso
            << setw(15) << this->GetCiclo()
            << setw(15) << this->GetNota()
            << setw(10) << this->GetVez()
            << setw(15) << this->GetCreditos() << endl;
};