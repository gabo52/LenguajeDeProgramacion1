/* 
 * File:   FaltaCond.cpp
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 10:23 PM
 */

#include "FaltaCond.h"
#include <cstring>

FaltaCond::FaltaCond() {
    placa = nullptr;
    gravedad = nullptr;
}



FaltaCond::~FaltaCond() {
    delete placa;
    delete gravedad;
}

void FaltaCond::SetGravedad(char* grav) {
    if(gravedad)delete gravedad;
    gravedad = new char [strlen(grav)+1];
    strcpy(gravedad,grav);
}

char* FaltaCond::GetGravedad() const {
    char *aux=nullptr;
    if(gravedad!=nullptr){
        aux = new char [strlen(gravedad)+1];
        strcpy(aux,gravedad);
    }
    return aux;
}

void FaltaCond::SetMulta(double multa) {
    this->multa = multa;
}

double FaltaCond::GetMulta() const {
    return multa;
}

void FaltaCond::SetCodInf(int codInf) {
    this->codInf = codInf;
}

int FaltaCond::GetCodInf() const {
    return codInf;
}

void FaltaCond::SetFecha(int fecha) {
    this->fecha = fecha;
}

int FaltaCond::GetFecha() const {
    return fecha;
}

void FaltaCond::SetPlaca(char* plac) {
    if(placa)delete placa;
    placa = new char [strlen(plac)+1];
    strcpy(placa,plac);
}

char* FaltaCond::GetPlaca() const {
    char *aux;
    aux = new char [strlen(placa)+1];
    strcpy(aux,placa);
    return aux;
}

void FaltaCond::copia(const FaltaCond &c){
    codInf = c.GetCodInf();
    fecha = c.GetFecha();
    gravedad = c.GetGravedad();
    multa = c.GetMulta();
    placa = c.GetPlaca();
}

