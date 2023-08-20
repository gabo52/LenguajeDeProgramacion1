/* 
 * File:   Infraccion.cpp
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 10:25 PM
 */

#include "Infraccion.h"
#include <cstring>
Infraccion::Infraccion() {
    descripcion = nullptr;
    gravedad = nullptr;
}


Infraccion::~Infraccion() {
    delete descripcion;
    delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(char* gravedad) {
    this->gravedad = gravedad;
}

char* Infraccion::GetGravedad() const {
    return gravedad;
}

void Infraccion::SetDescripcion(char* desc) {
    if(descripcion)delete descripcion;
    descripcion = new char [strlen(desc)+1];
    strcpy(descripcion,desc);
}

char* Infraccion::GetDescripcion() const {
    char *aux;
    aux = new char [strlen(descripcion)+1];
    strcpy(aux,descripcion);
    return aux;
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}


void Infraccion::copia(const Infraccion &c){
    codigo = c.GetCodigo();
    descripcion = c.GetDescripcion();
    gravedad = c.GetGravedad();
    multa = c.GetMulta();
}

