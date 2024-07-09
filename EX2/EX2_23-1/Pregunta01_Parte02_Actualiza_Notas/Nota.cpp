/* 
 * File:   Nota.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:52 PM
 */

#include "Nota.hpp"

using namespace std;

Nota::Nota() {
    ciclo = 0;
    codigo_curso = nullptr;
    creditos = 0.0;
    calificacion = 0;
    vez = 0;
}

Nota::Nota(const Nota& orig) {
    codigo_curso=nullptr;
    *this=orig;
}

Nota::~Nota() {
    if (codigo_curso != nullptr) delete codigo_curso;
}

void Nota::SetVez(int vez) {
    this->vez = vez;
}

int Nota::GetVez() const {
    return vez;
}

void Nota::SetCalificacion(int calificacion) {
    this->calificacion = calificacion;
}

int Nota::GetCalificacion() const {
    return calificacion;
}

void Nota::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Nota::GetCreditos() const {
    return creditos;
}

void Nota::SetCodigo_curso(const char* codigo_curso) {
    if (this->codigo_curso != nullptr) delete this->codigo_curso;
    this->codigo_curso = new char[strlen(codigo_curso) + 1];
    strcpy(this->codigo_curso, codigo_curso);
}

void Nota::GetCodigo_curso(char *codigo_curso) const {
    if (this->codigo_curso == nullptr) codigo_curso[0] = 0;
    else strcpy(codigo_curso, this->codigo_curso);
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}

void Nota::imprimeNota(ofstream &file) {
    file << fixed << setprecision(2);
    file << left << setw(10) << this->ciclo
            << setw(10) << this->codigo_curso
            << setw(10) << this->creditos
            << setw(10) << this->calificacion
            << this->vez << endl;
}

Nota & Nota::operator=(const Nota &nota) {
    char buffer[10];
    nota.GetCodigo_curso(buffer);
    this->SetCodigo_curso(buffer);
    this->SetVez(nota.GetVez());
    this->SetCalificacion(nota.GetCalificacion());
    this->SetCiclo(nota.GetCiclo());
    this->SetCreditos(nota.GetCreditos());
    return *this;
}



//20201,202123402,MAT218,4.5,13,FIS248,4.5,11,FIS208,4.5,9,FIS229,6,6,MEC2T3,1,11
//20201,202115400,INF281,5,5,MEC206,4.5,15,FIS208,4.5,5

bool operator>>(std::ifstream &file, Nota &nota) {
    char buffer[10], c;
    double creditos;
    int calificacion;
    c = file.get();
    if (c != ',') return false;
    file.getline(buffer, 10, ',');
    file >> creditos >> c >> calificacion; //no leemos la coma para que nos sirva de pivote
    nota.SetCodigo_curso(buffer);
    nota.SetCreditos(creditos);
    nota.SetCalificacion(calificacion);
    return true;
}
