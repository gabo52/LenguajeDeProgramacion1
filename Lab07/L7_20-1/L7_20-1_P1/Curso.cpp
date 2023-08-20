/* 
 * File:   Curso.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 31 de octubre de 2022, 10:43 AM
 */

#include "Curso.h"
#include <cstring>
Curso::Curso() {
    ccurso = nullptr;
}

Curso::~Curso() {
    delete ccurso;
}

void Curso::SetCredito(double credito) {
    this->credito = credito;
}

double Curso::GetCredito() const {
    return credito;
}

void Curso::SetNota(int nota) {
    this->nota = nota;
}

int Curso::GetNota() const {
    return nota;
}

void Curso::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Curso::GetCiclo() const {
    return ciclo;
}

void Curso::SetCcurso(char* cad) {
    if(ccurso!=nullptr)delete ccurso;
    ccurso = new char [strlen(cad)+1];
    strcpy(ccurso,cad);
}

char* Curso::GetCcurso() const {
    char *aux;
    int longitud = strlen(ccurso);
    aux = new char [longitud+1];
    strcpy(aux,ccurso);
    return aux;
}

void Curso::copia(const Curso& c) {
    ccurso = c.GetCcurso();
    ciclo = c.GetCiclo();
    nota = c.GetNota();
    credito = c.GetCredito();
}

void Curso::asignar(const Curso& c) {
    copia(c);
}
//preguntar tipo
void Curso::operator=(const Curso& c) {
    asignar(c);
}

int Curso::compare(const Curso& c) {

    return (strcmp(ccurso,c.ccurso)==0) && (ciclo==c.GetCiclo()); 
}

int Curso::operator==(const Curso& c) {
    return compare(c);
}









