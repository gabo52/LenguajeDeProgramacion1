/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.cpp
 * Author: Gabo
 * 
 * Created on 3 de noviembre de 2022, 09:33 PM
 */

#include "Paciente.h"

Paciente::Paciente() {
    dni=0;
    nombre=nullptr;
    numCitas=0;
    totalGastado=0;
}

Paciente::~Paciente() {
    delete nombre;
}

void Paciente::SetTotalGastado(double totalGastado) {
    this->totalGastado = totalGastado;
}

double Paciente::GetTotalGastado() const {
    return totalGastado;
}

void Paciente::SetNumCitas(int numCitas) {
    this->numCitas = numCitas;
}

int Paciente::GetNumCitas() const {
    return numCitas;
}


void Paciente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Paciente::GetTelefono() const {
    return telefono;
}

void Paciente::SetNombre(char* cad) {
    if(nombre)delete nombre;
    if(cad){
        nombre = new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre = new char [2];
        strcpy(nombre,"0");
    }
}

void Paciente::GetNombre(char *cad) const {
    if(nombre)strcpy(cad,nombre);
    else strcpy(cad,"0");
}

void Paciente::SetDni(int dni) {
    this->dni = dni;
}

int Paciente::GetDni() const {
    return dni;
}

void Paciente::operator = (const Paciente &c){
    char cadena[200];
    c.GetNombre(cadena);
    SetNombre(cadena);
    SetDni(c.GetDni());
    SetNumCitas(c.GetNumCitas());
    SetTelefono(c.GetTelefono());
    SetTotalGastado(c.GetTotalGastado());
}

void Paciente::imprimeCitas (ofstream &arch){
    arch.precision(2);
    arch<<fixed;
    for(int i=0;i<GetNumCitas();i++){
        citas[i].imprimeCita(arch);
    }
}

void Paciente::operator += (const Cita &c){
    citas[numCitas]=c;
    numCitas++;
}

void Paciente::operator ++(){
    double suma=0;
    for(int i=0;i<numCitas;i++){
        suma+=citas[i].getTarifaPorConsulta();
    }
    totalGastado=suma;
}

