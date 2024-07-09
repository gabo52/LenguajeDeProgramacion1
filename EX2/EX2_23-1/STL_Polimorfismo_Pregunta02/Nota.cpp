/* 
 * File:   Nota.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:53 PM
 */

#include "Nota.hpp"
#include "Segunda.hpp"
#include "Tercera.hpp"

Nota::Nota() {
    pnota = nullptr;

}

Nota::Nota(const Nota& orig) {
    pnota = nullptr;
    *this = orig;
}

Nota::~Nota() {
}

void Nota::leernota(std::ifstream &file) {
    this->pnota = new Primera();
    this->pnota->leerNota(file);
}

int Nota::GetCodigoAlumno() {
    return this->pnota->GetCodigo();
}

void Nota::GetCodcurAlumno(char *codcur) {
    this->pnota->GetCodcur(codcur);
}

int Nota::GetCicloAlumno() {
    return this->pnota->GetCiclo();
}

void Nota::SetVez(int vez) {
    if (vez == 2) {// ahora tengo que hacer que apunte a 2da
        Segunda * aux = new Segunda;
        char buffer[10];
        this->pnota->GetCodcur(buffer);
        aux->SetCiclo(this->pnota->GetCiclo());
        aux->SetCodcur(buffer);
        aux->SetCodigo(this->pnota->GetCodigo());
        aux->SetNota(this->pnota->GetNota());
        aux->SetVez(vez);
        if (this->pnota->GetCreditos() <= 3.0) {
            aux->SetCreditos(this->pnota->GetCreditos() + 1);
        } else {
            aux->SetCreditos(this->pnota->GetCreditos() + 1.5);
        }
        delete this->pnota;
        this->pnota = aux;
    }
    if (vez == 3) {// ahora tengo que hacer que apunte a 3ra
        Tercera * aux = new Tercera;
        char buffer[10];
        this->pnota->GetCodcur(buffer);
        aux->SetCiclo(this->pnota->GetCiclo());
        aux->SetCodcur(buffer);
        aux->SetCodigo(this->pnota->GetCodigo());
        aux->SetNota(this->pnota->GetNota());
        aux->SetVez(vez);
        aux->SetCreditos(this->pnota->GetCreditos());
        if (this->pnota->GetCreditos() <= 3.0) {
            aux->SetCreditos(this->pnota->GetCreditos() * 1.5);
            aux->SetPorcentaje(0.5);
        } else {
            aux->SetCreditos(this->pnota->GetCreditos() * 2);
            aux->SetPorcentaje(1.0);
        }
        delete this->pnota;
        this->pnota = aux;
    }
}

void Nota::imprime(std::ofstream &file) {
    this->pnota->imprime(file);
}
