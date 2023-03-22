/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medico.cpp
 * Author: Gabo
 * 
 * Created on 3 de noviembre de 2022, 09:34 PM
 */

#include "Medico.h"

Medico::Medico() {
    codigo = 0;
    especialidad = nullptr;
    nombre = nullptr;
}


Medico::~Medico() {
    delete especialidad;
    delete nombre;
}

void Medico::SetEspecialidad(const char* cad) {
    if(especialidad)delete especialidad;
    if(cad){
        especialidad = new char [strlen(cad)+1];
        strcpy(especialidad,cad);
    }else{
        especialidad = new char [2];
        strcpy(especialidad,"0");
    }
}

void Medico::GetEspecialidad(char *cad) const {
    if(especialidad)strcpy(cad,especialidad);
    else strcpy(cad,"0");
}

void Medico::SetTarifaxconsulta(double tarifaxconsulta) {
    this->tarifaxconsulta = tarifaxconsulta;
}

double Medico::GetTarifaxconsulta() const {
    return tarifaxconsulta;
}

void Medico::SetNombre(const char* cad) {
    if(nombre)delete nombre;
    if(cad){
        nombre = new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre = new char [2];
        strcpy(nombre,"0");
    }
}

void Medico::GetNombre(char *cad) const {
    if(nombre)strcpy(cad,nombre);
    else strcpy(cad,"0");
}

void Medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medico::GetCodigo() const {
    return codigo;
}

void Medico::operator = (const Medico &c){
    char cadena[200];
    SetCodigo(c.GetCodigo());
    SetTarifaxconsulta(c.GetTarifaxconsulta());
    c.GetEspecialidad(cadena);
    SetEspecialidad(cadena);
    c.GetNombre(cadena);
    SetNombre(cadena);
}

