

/* 
 * File:   Conductor.cpp
 * Author: USER
 * 
 * Created on 20 de junio de 2023, 03:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Conductor.h"
using namespace std; 

Conductor::Conductor() {
}

Conductor::Conductor(const Conductor& orig) {
}

Conductor::~Conductor() {
}

void Conductor::SetNombre(char *cad){
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Conductor::GetNombre(char *cad) const {
    strcpy(cad,nombre); 
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}