/* 
 * File:   Pedido.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:49 AM
 */

#include "Pedido.h"

Pedido::Pedido() {
    codigo=0;
    total=0;
    cantidad=0;
}

Pedido::Pedido(const Pedido& orig) {
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


void Pedido::lee(ifstream &arch){
    int cod,cantSol,dni,dd,mm,aa;
    double monto;
    char c;
    arch>>cod>>c;
    if(arch.eof())return;
    arch>>cantSol>>c>>monto>>c>>dni>>c>>dd>>c>>mm>>c>>aa;
    SetCantidad(cantSol);
    SetCodigo(cod);
    SetDni(dni);
    SetFecha(dd+mm*100+aa*10000);
    SetTotal(monto);
}

