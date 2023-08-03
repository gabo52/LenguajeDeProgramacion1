/* 
 * File:   Producto.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de noviembre de 2022, 05:31 PM
 */

#include "Producto.h"
#include <cstring>
Producto::Producto() {
    nombre = nullptr;
    codprod=0;
    stock=0;
}


Producto::~Producto() {
    if(nombre)delete nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(char* cad) {
    if(nombre)delete nombre;
    if(cad){
        nombre = new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre = new char [2];
        nombre[0]=0;
    }
}

void Producto::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::operator = (const Producto &c){
    char cad[150];
    c.GetNombre(cad);
    SetNombre(cad);
    SetCodprod(c.GetCodprod());
    SetPrecio(c.GetPrecio());
    SetStock(c.GetStock());
}
