/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:05 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
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

void Pedido::SetObs(char* cad) { 
    if(obs!=NULL) delete[]obs;
    obs = new char[strlen(cad)+1];
    strcpy(obs,cad);
}
void Pedido::GetObs(char *nom) const {
    strcpy(nom,obs);
}

//118050,8,79475585,16/12/2019
//codigoprod, cantidad, dni, fecha
int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    char *obs;
void Pedido::leepedido(ifstream &arch){
    int codigoP,cant,dniCli,dd,mm,aa,fechaP;
    double precioU;
    char car;
    
    arch>>codigoP;
    if(arch.eof()) return;
    cargaproducto(codigoP);
    arch.get();
    arch>>cant>>car>>dniCli>>car>>dd>>car>>mm>>car>>aa;
    fechaP=aa*10000+mm*100+dd;
    SetCodigo(codigoP);
    SetCantidad(cant);
    SetDni(dniCli);
    SetFecha(fechaP);
    precioU=GetPrecio();
    SetTotal(precioU*cant);
}

void Pedido::imprimePedido(ofstream &arch){
    int aa,mm,dd;
    aa=GetFecha()/10000;
    mm=(GetFecha()%10000)/100;
    dd=(GetFecha()%10000)%100;
    
    char cad[200],observacion[200];
    GetNombre(cad);
    GetObs(observacion);
    arch<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<
            setfill(' ')<<setw(10)<<GetCodigo()<<setw(5)<<' '<<left<<setw(50)<<cad<<
            right<<setw(10)<<GetCantidad()<<setprecision(2)<<fixed<<setw(10)<<GetPrecio()<<
            setprecision(2)<<fixed<<setw(10)<<GetTotal()<<"   "<<observacion<<endl;
}
