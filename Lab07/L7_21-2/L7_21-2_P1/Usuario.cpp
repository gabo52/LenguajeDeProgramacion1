
/* 
 * File:   Usuario.cpp
 * Author: USER
 * 
 * Created on 7 de junio de 2023, 10:17 AM
 */

#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include "Libro.h"
#include "Usuario.h"
#include "LibroPrestado.h"
using namespace std; 

Usuario::Usuario() {
    carne = 0;
    nombre = nullptr; 
    condicion = 1; 
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

void Usuario::SetCondicion(int condicion) {
    this->condicion = condicion;
}

int Usuario::GetCondicion() const {
    return condicion;
}

void Usuario::SetLibPrest(LibroPrestado *arr) {
    for(int i=0;libPrest[i].GetCarne();i++) libPrest[i].copia(arr[i]);
}

LibroPrestado* Usuario::GetLibPrest() const{
    LibroPrestado *lib;
    lib = new LibroPrestado[100]{};
    for(int i=0;libPrest[i].GetCarne();i++) lib[i].copia(libPrest[i]);
    return lib;
}

void Usuario::SetNombre(char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(this->nombre,cad);
}

char* Usuario::GetNombre() const {
    char *aux;
    int longitud = strlen(nombre);
    aux = new char[longitud+1];
    strcpy(aux,nombre);
    return aux;
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
    int i; 
    carne = c.GetCarne();
    tipo = c.GetTipo();
    condicion = c.GetCondicion();
    for(i=0;libPrest[i].GetCarne();i++) libPrest[i].copia(c.libPrest[i]); 
    
}

void Usuario::operator += (const LibroPrestado &c){
    int i, num = 0; 
    for(i=0;libPrest[i].GetCarne();i++) num++;    
    libPrest[num].copia(c); 
}

void Usuario::operator * (int fecha){
    int i, librosDeudas = 0, max = 0; 
    
    if(tipo == 'A') max = 7; 
    if(tipo == 'D') max = 15; 
    if(tipo == 'E') max = 10; 
    
    for(i=0;libPrest[i].GetCarne();i++){
        if(fabs((fecha - libPrest[i].GetFechaDeRetiro())) > max){
            libPrest[i].SetDeuda(1); 
            condicion = 0; 
        }
    }
}