/* 
 * File:   CursoAlumno.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:45 PM
 */

#include "CursoAlumno.hpp"

CursoAlumno::CursoAlumno() {
    codigo = 0;
    ciclo = 0;
    nota = 0;
    vez = 1;
    codcur = nullptr;
    creditos = 0.0;
}

CursoAlumno::CursoAlumno(const CursoAlumno& orig) {
    codcur = nullptr;
    *this = orig;
}

CursoAlumno::~CursoAlumno() {
    if (codcur != nullptr) delete codcur;

}

void CursoAlumno::SetVez(int vez) {
    this->vez = vez;
}

int CursoAlumno::GetVez() const {
    return vez;
}

void CursoAlumno::SetNota(int nota) {
    this->nota = nota;
}

int CursoAlumno::GetNota() const {
    return nota;
}

void CursoAlumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double CursoAlumno::GetCreditos() const {
    return creditos;
}

void CursoAlumno::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int CursoAlumno::GetCiclo() const {
    return ciclo;
}

void CursoAlumno::SetCodcur(const char* codcur) {
    if (this->codcur != nullptr)delete this->codcur;
    this->codcur = new char[strlen(codcur) + 1];
    strcpy(this->codcur, codcur);
}

void CursoAlumno::GetCodcur(char *codcur) const {
    if (this->codcur == nullptr) codcur[0] = 0;
    else strcpy(codcur, this->codcur);
}

void CursoAlumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int CursoAlumno::GetCodigo() const {
    return codigo;
}


//202216453,MEC206,3,202102,8
//202119707,INF246,4,202302,17
//202119707,MEC289,3,202202,7
//202119958,INF246,4,202201,17

void CursoAlumno::leerNota(std::ifstream &file) {
    char c, buffer[10],acceso[20];
    file >> this->codigo >> c;
    file.getline(buffer, 10, ',');
    file >> this->creditos >> c >> this->ciclo >> c >> this->nota;
    this->SetCodcur(buffer);
}
