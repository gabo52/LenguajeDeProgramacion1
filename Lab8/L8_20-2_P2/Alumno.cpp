/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Gabo
 * 
 * Created on 6 de noviembre de 2022, 09:46 PM
 */

#include <cstring>
#include "Alumno.h"

Alumno::Alumno() {
    escala = 0;
    especialidad = nullptr;
    facultad = nullptr;
}


Alumno::~Alumno() {
    if(especialidad)delete especialidad;
    if(facultad)delete facultad;
}

void Alumno::SetFacultad(char* cad) {
    if(facultad)delete facultad;
    if(cad){
        facultad =  new char [strlen(cad)+1];
        strcpy(facultad,cad);
    }else{
        facultad =  new char [2];
        strcpy(facultad,"0");
    }
}

void Alumno::GetFacultad(char *cad) const {
    if(facultad)strcpy(cad,facultad);
    else strcpy(cad,"0");
}

void Alumno::SetEspecialidad(char* cad) {
       if(especialidad)delete especialidad;
    if(cad){
        especialidad =  new char [strlen(cad)+1];
        strcpy(especialidad,cad);
    }else{
        especialidad =  new char [2];
        strcpy(especialidad,"0");
    }
}

void Alumno::GetEspecialidad(char *cad) const {
    if(especialidad)strcpy(cad,especialidad);
    else strcpy(cad,"0");
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::operator = (const Alumno &c){
    SetEscala(c.GetEscala());
    char cadena[200];
    c.GetEspecialidad(cadena);
    SetEspecialidad(cadena);
    c.GetFacultad(cadena);
    SetFacultad(cadena);
    c.GetNombre(cadena);
    SetNombre(cadena);
    SetCodigo(c.GetCodigo());
}

