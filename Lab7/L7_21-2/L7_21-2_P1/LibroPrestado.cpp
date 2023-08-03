

/* 
 * File:   LibroPrestado.cpp
 * Author: USER
 * 
 * Created on 7 de junio de 2023, 10:20 AM
 */
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include "Libro.h"
#include "LibroPrestado.h"
using namespace std; 

LibroPrestado::LibroPrestado() {
    carne = 0;
    tipo = 'X'; 
    codigoLib = nullptr; 
    fechaDeRetiro = 0;
    deuda = 0; 
}

LibroPrestado::LibroPrestado(const LibroPrestado& orig) {
}

LibroPrestado::~LibroPrestado() {
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

void LibroPrestado::SetCodigoLib(char* cad) {
    if(codigoLib != nullptr) delete codigoLib;
    codigoLib = new char[strlen(cad)+1];
    strcpy(this->codigoLib,cad);
}

char* LibroPrestado::GetCodigoLib() const {
    char *aux;
    int longitud = strlen(codigoLib);
    aux = new char[longitud+1];
    strcpy(aux,codigoLib);
    return aux;
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
    carne = c.GetCarne();
    tipo = c.GetTipo();
    codigoLib = c.GetCodigoLib();
    fechaDeRetiro = c.GetFechaDeRetiro();
    deuda = c.GetDeuda(); 
}



