/* 
 * File:   medico.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 06:48 PM
 */

#include <cstring>

#include "medico.h"

medico::medico() {
    codigo=0;
    especialidad=nullptr;
    nombre=nullptr;
}


medico::~medico() {
    if(especialidad)delete especialidad;
    if(nombre)delete nombre;
}

void medico::SetEspecialidad(char* cad) {
    if(especialidad)delete especialidad;
    especialidad = new char [strlen(cad)+1];
    strcpy(especialidad,cad);
}

void medico::GetEspecialidad(char* cad) const {
    if(especialidad)strcpy(cad,especialidad);
    else cad[0]=0;
}

void medico::SetNombre(char* cad) {
    if(nombre)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void medico::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

void medico::leer(ifstream &arch){
    int codmed;
    char cad[200],c;
    arch>>codmed>>c;
    if(arch.eof())return;
    arch.getline(cad,200,',');
    SetCodigo(codmed);
    SetNombre(cad);
    arch.getline(cad,200,'\n');
    SetEspecialidad(cad);
}

