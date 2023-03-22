/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LibroPrestado.cpp
 * Author: Gabo
 * 
 * Created on 2 de noviembre de 2022, 11:41 PM
 */

#include "LibroPrestado.h"
#include <cstring>
LibroPrestado::LibroPrestado() {
    carne=0;
    codigoLib = nullptr;
    deuda =0;
    
}

LibroPrestado::~LibroPrestado() {
    delete codigoLib;
}

void LibroPrestado::SetDeuda(int deuda) {
    this->deuda = deuda;
}

int LibroPrestado::GetDeuda() const {
    return deuda;
}

void LibroPrestado::SetFechaDeRetiro(int fechaDeRetiro) {
    this->fechaDeRetiro = fechaDeRetiro;
}

int LibroPrestado::GetFechaDeRetiro() const {
    return fechaDeRetiro;
}

void LibroPrestado::SetCodigoLib(const char* cad) {
    if(codigoLib)delete codigoLib;
    if(cad==nullptr){
        codigoLib = nullptr;
    }else{
        codigoLib = new char [strlen(cad)+1];
        strcpy(codigoLib,cad);
    }
}

void LibroPrestado::GetCodigoLib(char* cad) const {
    if(codigoLib==nullptr)strcpy(cad,"0");
    else{
        strcpy(cad,codigoLib);
    }
}

void LibroPrestado::SetTipo(char tipo) {
    this->tipo = tipo;
}

char LibroPrestado::GetTipo() const {
    return tipo;
}

void LibroPrestado::SetCarne(int carne) {
    this->carne = carne;
}

int LibroPrestado::GetCarne() const {
    return carne;
}

void LibroPrestado::copia(const LibroPrestado &c){
    SetCarne(c.GetCarne());
    char cadena[200];
    c.GetCodigoLib(cadena);
    SetCodigoLib(cadena);
    SetDeuda(c.GetDeuda());
    SetFechaDeRetiro(c.GetFechaDeRetiro());
    SetTipo(c.GetTipo());
}

