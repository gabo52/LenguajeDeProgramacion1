
/* 
 * File:   Paciente.cpp
 * Author: USER
 * 
 * Created on 8 de junio de 2023, 03:39 PM
 */

#include <cstring>
#include "Paciente.h"

Paciente::Paciente() {
}

Paciente::Paciente(const Paciente& orig) {
}

Paciente::~Paciente() {
}

void Paciente::SetEstado(char estado) {
    this->estado = estado;
}

char Paciente::GetEstado() const {
    return estado;
}

void Paciente::SetPrima(double prima) {
    this->prima = prima;
}

double Paciente::GetPrima() const {
    return prima;
}

void Paciente::SetNombre(char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(this->nombre,cad);
}

void Paciente::GetNombre(char *cad) const {
    strcpy(cad,nombre); 
}

void Paciente::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Paciente::GetCodigo() const {
    return codigo;
}

void Paciente::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Paciente::GetFecha() const {
    return fecha;
}

int Paciente::copia(const Paciente &p){
    codigo = p.GetCodigo();
    estado = p.GetEstado();
    fecha = p.GetFecha();
    nombre = p.GetNombre();   
    prima = p.GetPrima();
}


