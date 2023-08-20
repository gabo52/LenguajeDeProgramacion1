/* 
 * File:   Pedido.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:43 AM
 */
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Pedido.h"

Pedido::Pedido() {
    codigo = 0;
    nombre = nullptr;
    cantidad= 0;
}



Pedido::~Pedido() {
    eliminar();
    
}

void Pedido::eliminar(){
    delete nombre;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetPrecio(double precio) {
    this->precio = precio;
}

double Pedido::GetPrecio() const {
    return precio;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(const char* cad) {
    if(nombre)delete nombre;
    if(cad!=nullptr){
        nombre = new char [strlen(cad)+1];
        strcpy(nombre,cad);
    }else{
        nombre = new char [2];
        strcpy(nombre,"0");
    }
}

void Pedido::GetNombre(char *cad) const {
    if(nombre==nullptr)strcpy(cad,"0");
    else strcpy(cad,nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}


void Pedido::operator = (const Pedido &c){
    cantidad = c.GetCantidad();
    codigo = c.GetCodigo();
    dni = c.GetDni();
    fecha = c.GetFecha();
    char cadena[50];
    c.GetNombre(cadena);
    SetNombre(cadena);
    precio = c.GetPrecio();
}

void Pedido::imprimepedido(ofstream &arch){
    int fecha = GetFecha();
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
    char cadena[80];
    GetNombre(cadena);
    arch<<setw(12)<<right<<GetCodigo()<<"   "<<setw(50)<<left<<cadena<<
            setw(8)<<right<<GetCantidad()<<setw(8)<<right<<GetPrecio()<<endl;
}
