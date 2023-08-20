/* 
 * File:   Pedido.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de noviembre de 2022, 05:35 PM
 */

#include "Pedido.h"
#include <cstring>

Pedido::Pedido() {
    codigo=0;
    cantidad=0;
    obs = nullptr;
}


Pedido::~Pedido() {
    if(obs)delete obs;
}

void Pedido::SetObs(char* cad) {
    if(obs)delete obs;
    if(cad){
        obs = new char [strlen(cad)+1];
        strcpy(obs,cad);
    }else{
        obs = new char [2];
        obs[0]=0;
    }
}

void Pedido::GetObs(char* cad) const {
    if(obs)strcpy(cad,obs);
    else cad[0]=0;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}


void Pedido::operator = (const Pedido &c){
    SetCantidad(c.GetCantidad());
    SetCodigo(c.GetCodigo());
    SetCodprod(c.GetCodprod());
    SetFecha(c.GetFecha());
    SetPrecio(c.GetPrecio());
    SetStock(c.GetStock());
    SetTotal(c.GetTotal());
    char cad[180];
    c.GetNombre(cad);
    SetNombre(cad);
    c.GetObs(cad);
    SetObs(cad);
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}

void Pedido::imprime(ofstream &arch){
    imprimeFecha(GetFecha(),arch);
    arch<<"  "<<setw(10)<<left<<GetCodigo();
    
    char cad[100];
    GetNombre(cad);
    arch<<setw(50)<<left<<cad<<setw(5)<<right<<GetCantidad()<<setw(10)<<right
            <<GetPrecio()<<setw(10)<<right<<GetTotal()<<"   ";
    if(obs)arch<<left<<obs;
    arch<<endl;
}

