/* 
 * File:   Alumno.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:12 PM
 */

#include <cstring>

#include "Alumno.h"

Alumno::Alumno() {
    especialidad=nullptr;
    facultad= nullptr;
}


Alumno::~Alumno() {
    if(facultad)delete facultad;
    if(especialidad)delete especialidad;
}

void Alumno::SetFacultad(char* cad) {
    if(facultad)delete facultad;
    facultad = new char [strlen(cad)+1];
    strcpy(facultad,cad);
}

void Alumno::GetFacultad(char *cad) const {
    if(facultad)strcpy(cad,facultad);
    else cad[0]=0;
}

void Alumno::SetEspecialidad(char* cad) {
    if(especialidad)delete especialidad;
    especialidad = new char [strlen(cad)+1];
    strcpy(especialidad,cad);
}

void Alumno::GetEspecialidad(char* cad) const {
    if(especialidad)strcpy(cad,especialidad);
    else cad[0]=0;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::leer(ifstream &arch){
    lee(arch);
    int esc;
    char cad[100],c;
    arch>>esc>>c;
    arch.getline(cad,100,',');
    SetFacultad(cad);
    arch.getline(cad,100,'\n');
    SetEspecialidad(cad);
    SetEscala(esc);
}

void Alumno::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(15)<<left<<GetCodigo()<<setw(40)<<left<<cad;
    GetDistrito(cad);
    arch<<setw(40)<<left<<cad<<setw(15)<<left<<GetEscala();
    
    GetEspecialidad(cad);
    arch<<setw(40)<<left<<cad;
    GetFacultad(cad);
    arch<<setw(40)<<left<<cad;
    arch<<endl;
}
