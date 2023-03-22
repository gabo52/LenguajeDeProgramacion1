/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Gabo
 * 
 * Created on 28 de noviembre de 2022, 04:15 PM
 */

#include "Pedido.h"


void Pedido::SetSubTotal(double subTotal) {
    this->subTotal = subTotal;
}

double Pedido::GetSubTotal() const {
    return subTotal;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetCantidad(double cantidad) {
    this->cantidad = cantidad;
}

double Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

int Pedido::leerDatos(ifstream &arch){
    int cod,fec,dd,mm,aa,dni;
    double cant,sub;
    char c;
    arch>>cant>>c;
    if(arch.eof())return 0;
    arch>>dni>>c>>dd>>c>>mm>>c>>aa;
    SetCantidad(cant);
    SetFecha(dd+mm*100+aa*10000);
    SetSubTotal(0);   
    return dni;
}

void Pedido::imprimirDatos(ofstream &arch){
    imprimeFecha(arch,GetFecha());
    arch<<"     "<<setw(17)<<left<<GetCodigo();
    arch<<setw(15)<<left<<GetCantidad()<<left<<setw(10)<<left<<GetSubTotal()<<endl;
}

void Pedido::imprimeFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}

bool Pedido::operator <(const Pedido &c){
    return GetFecha() < c.GetFecha();
}