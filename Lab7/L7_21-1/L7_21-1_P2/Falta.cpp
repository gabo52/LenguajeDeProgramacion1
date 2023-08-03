/* 
 * File:   Falta.cpp
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 10:24 PM
 */

#include "Falta.h"
#include <cstring>

Falta::Falta() {
    placa = nullptr;
}



Falta::~Falta() {
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetCodInf(int codInf) {
    this->codInf = codInf;
}

int Falta::GetCodInf() const {
    return codInf;
}

void Falta::SetPlaca(char* plac) {
    if(placa!=nullptr)delete placa;
    placa = new char [strlen(plac)+1];
    strcpy(placa,plac);
}

char* Falta::GetPlaca() const {
    char *aux;
    aux = new char [strlen(placa)+1];
    strcpy(aux,placa);
    return aux;
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}

void Falta::copia(const Falta &c){
    codInf = c.GetCodInf();
    fecha = c.GetFecha();
    licencia = c.GetLicencia();
    placa = c.GetPlaca();
}

