/* 
 * File:   Pedido.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:01 PM
 */

#include "Pedido.h"

Pedido::Pedido() {
    total=0;
    orden=0;
}

Pedido::Pedido(const Pedido& orig) {
}


void Pedido::SetOrden(int orden) {
    this->orden = orden;
}

int Pedido::GetOrden() const {
    return orden;
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

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
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
    SetDni(c.GetDni());
    SetFecha(c.GetFecha());
    SetOrden(c.GetOrden());
    SetTotal(c.GetTotal());
}

bool Pedido::operator > (const Pedido &c){
    return GetFecha()<c.GetFecha();
}

void Pedido::leer(ifstream &arch){
    int cod,cant,dni,dd,mm,aa;
    double monto;
    char c;
    arch>>cod>>c;
    if(arch.eof())return;
    arch>>cant>>c>>monto>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    SetCantidad(cant);
    SetCodigo(cod);
    SetDni(dni);
    SetFecha(dd+mm*100+aa*10000);
    SetTotal(monto);
}

void Pedido::imprime(ofstream &arch){
    int dd,mm,aa,fecha=GetFecha();
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
    arch<<setw(15)<<right<<GetCodigo()<<setw(10)<<right<<GetCantidad()
            <<setw(10)<<right<<GetTotal();
    if(GetOrden()==0){
        arch<<setw(10)<<right<<"No"<<endl;
    }else arch<<setw(10)<<right<<"Si"<<endl;
}

