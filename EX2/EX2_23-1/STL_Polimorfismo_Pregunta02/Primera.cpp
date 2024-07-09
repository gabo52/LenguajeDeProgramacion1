/* 
 * File:   Primera.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:47 PM
 */

#include "Primera.hpp"

using namespace std;

Primera::Primera() {
    codacceso = nullptr;
}

Primera::Primera(const Primera& orig) {
}

Primera::~Primera() {
    if (codacceso != nullptr) delete codacceso;
}

void Primera::SetCodacceso(const char* codacceso) {
    if (this->codacceso != nullptr) delete this->codacceso;
    this->codacceso = new char[strlen(codacceso) + 1];
    strcpy(this->codacceso, codacceso);
}

void Primera::GetCodacceso(char* codacceso) const {
    if (this->codacceso == nullptr) codacceso[0] = 0;
    else strcpy(codacceso, this->codacceso);
}

void Primera::leerNota(std::ifstream &file) {
    this->CursoAlumno::leerNota(file);
    char buffer[20], curso[10];
    this->GetCodcur(curso);
    sprintf(buffer, "%d%s", this->GetCodigo(), curso);
    this->SetCodacceso(buffer);
}

void Primera::imprime(std::ofstream &file) {
    char curso[10];
    this->GetCodcur(curso);
    file << left << setfill(' ') << setw(15) << this->GetCodigo()
            << setw(15) << curso
            << setw(15) << this->GetCiclo()
            << setw(15) << this->GetNota()
            << setw(10) << this->GetVez()
            << setw(15) << this->GetCreditos()
            << this->codacceso << endl;
}

