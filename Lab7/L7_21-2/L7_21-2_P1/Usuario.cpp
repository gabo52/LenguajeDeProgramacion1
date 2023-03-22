/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: Gabo
 * 
 * Created on 2 de noviembre de 2022, 11:39 PM
 */

#include "Usuario.h"
#include <cstring>
#include "FuncionesFecha.h"
#include "FuncionesLecturaEscritura.h"
Usuario::Usuario() {
    carne=0;
    nombre = nullptr;
    numLibPrest=0;
    condicion=0;
}

Usuario::~Usuario() {
    delete nombre;
}

void Usuario::SetCondicion(int condicion) {
    this->condicion = condicion;
}

int Usuario::GetCondicion() const {
    return condicion;
}

void Usuario::SetNumLibPrest(int numLibPrest) {
    this->numLibPrest = numLibPrest;
}

int Usuario::GetNumLibPrest() const {
    return numLibPrest;
}


void Usuario::SetNombre(char* cad) {
    if(nombre)delete nombre;
    if(cad!=nullptr){
        nombre = new char [strlen(cad)+1];
    }else nombre = nullptr;
}

void Usuario::GetNombre(char *cad) const {
    if(cad!=nullptr) strcpy(nombre,cad);
    else strcpy(cad,"0");
   
}

void Usuario::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Usuario::GetTipo() const {
    return tipo;
}

void Usuario::SetCarne(int carne) {
    this->carne = carne;
}

int Usuario::GetCarne() const {
    return carne;
}

void Usuario::copia(const Usuario &c){
    char cadena[200];
    carne = c.GetCarne();
    condicion = c.GetCondicion();
    c.GetNombre(cadena);
    SetNombre(cadena);
    carne = c.GetCarne();
    numLibPrest = c.GetNumLibPrest();
    tipo = c.GetTipo();
}

void Usuario::operator += (const LibroPrestado &prest){
    libPrest[GetNumLibPrest()].copia(prest);
    SetNumLibPrest(GetNumLibPrest()+1);
}

void Usuario::operator * (int fecha){
    int aux,n;
    char tip=GetTipo();
    for(int i=0;i<GetNumLibPrest();i++){
        aux=libPrest[i].GetFechaDeRetiro();
        n=numeroDeDias(fecha,aux);
        if(tip=='A'){
            if(n>7){
                SetCondicion(1);
                return;
            }
        }else if(tip=='E'){
            if(n>10){
                SetCondicion(1);
                return;
            }
        }else{
            if(n>15){
                SetCondicion(1);
                return;
            }
        }
    }
}

void Usuario::imprimeLibros (ofstream &arch){
    for(int i=0;i<GetNumLibPrest();i++){
        arch<<libPrest[i];
    }
}

