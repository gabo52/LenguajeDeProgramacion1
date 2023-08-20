/* 
 * File:   Infraccion.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:38 PM
 */
#include <cstring>
#include "Infraccion.h"

Infraccion::Infraccion() {
    codigo=0;   
    gravedad=nullptr;
}

Infraccion::~Infraccion() {
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(char* cad) {
    if(gravedad)delete gravedad;
    if(cad){
        gravedad = new char [strlen(cad)+1];
        strcpy(gravedad,cad);
    }else{
        gravedad = new char[2];
        strcpy(gravedad,"0");
    }
}

void Infraccion::GetGravedad(char *cad) const {
    if(gravedad)strcpy(cad,gravedad);
    else strcpy(cad,"0");
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::operator = (const Infraccion &c){
    SetCodigo(c.GetCodigo());
    SetMulta(c.GetMulta());
    char cad[100];
    c.GetGravedad(cad);
    SetGravedad(cad);
}



