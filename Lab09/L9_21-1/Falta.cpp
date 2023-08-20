

/* 
 * File:   Falta.cpp
 * Author: USER
 * 
 * Created on 20 de junio de 2023, 03:31 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Falta.h"
using namespace std;

Falta::Falta() {
}

Falta::Falta(const Falta& orig) {
}

Falta::~Falta() {
}

void Falta::SetPlaca(char *cad) {
    if(placa != nullptr) delete placa;
    placa = new char[strlen(cad)+1];
    strcpy(placa,cad);
}

void Falta::GetPlaca(char *cad) const {
    strcpy(cad,placa);
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

