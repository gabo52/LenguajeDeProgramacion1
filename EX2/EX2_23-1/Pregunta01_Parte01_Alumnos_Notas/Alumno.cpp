/* 
 * File:   Alumno.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:48 PM
 */

#include "Alumno.hpp"

using namespace std;

Alumno::Alumno() {
    codigo_alumno = 0;
    nombre = nullptr;
    promedio = 0.0;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if(nombre != nullptr) delete nombre;
}

void Alumno::SetPromedio(double promedio) {
    this->promedio = promedio;
}

double Alumno::GetPromedio() const {
    return promedio;
}

void Alumno::SetNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Alumno::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Alumno::SetCodigo_alumno(int codigo_alumno) {
    this->codigo_alumno = codigo_alumno;
}

int Alumno::GetCodigo_alumno() const {
    return codigo_alumno;
}

void Alumno::imprimeAlumno (ofstream &file){
    file << setfill(' ') << left;
    file << "CODIGO: " <<  setw(10) << this->codigo_alumno
             << "ALUMNO: " << this->nombre << endl;
    file << setw(100) << setfill('-') << "-" << endl << setfill(' ');
}

// Operador sobrecargado
//202111260,GORDILLO CASTRO RONAL
//202111397,ZEVALLOS PRADO RICARDO
void operator>>(ifstream &file, Alumno &alumno){
    int codigo_alumno;
    char *nombre,buffer[50], c;
    file >> codigo_alumno >> c;
    file.getline(buffer,50);
    nombre = new char[strlen(buffer) + 1];
    strcpy(nombre,buffer);
    alumno.SetCodigo_alumno(codigo_alumno);
    alumno.SetNombre(nombre);
}