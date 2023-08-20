/* 
 * File:   Urgencia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:44 AM
 */

#include "Urgencia.h"

Urgencia::Urgencia() {
    
}


Urgencia::~Urgencia() {
}

void Urgencia::SetPorcUrgencia(double porcUrgencia) {
    this->porcUrgencia = porcUrgencia;
}

double Urgencia::GetPorcUrgencia() const {
    return porcUrgencia;
}

void Urgencia::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Urgencia::GetPorcSeguro() const {
    return porcSeguro;
}

void Urgencia::operator=(const Urgencia& c) {
    SetPorcSeguro(c.GetPorcSeguro());
    SetPorcUrgencia(c.GetPorcUrgencia());
    SetDni(c.GetDni());
    char cad[200];
    c.GetCodMed(cad);
    SetCodMed(cad);
    c.GetNombre(cad);
    SetNombre(cad);
}

