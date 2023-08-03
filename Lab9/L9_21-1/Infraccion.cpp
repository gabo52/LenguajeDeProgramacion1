

/* 
 * File:   Infraccion.cpp
 * Author: USER
 * 
 * Created on 20 de junio de 2023, 03:28 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Infraccion.h"
using namespace std; 

Infraccion::Infraccion() {
}

Infraccion::Infraccion(const Infraccion& orig) {
}

Infraccion::~Infraccion() {
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(char *cad) {
    if(gravedad != nullptr) delete gravedad;
    gravedad = new char[strlen(cad)+1];
    strcpy(gravedad,cad);
}

void Infraccion::GetGravedad(char *cad) const {
    strcpy(cad,gravedad); 
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

