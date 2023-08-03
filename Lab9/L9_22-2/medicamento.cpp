/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.cpp
 * Author: cueva
 * 
 * Created on 5 de noviembre de 2022, 11:16 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "medicamento.h"

using namespace std;

medicamento::medicamento() {
    
    codigo=0;
    nombre=NULL;
    cantidad=0;
    precio=0;
    fecha=0;
    total=0;
}

medicamento::medicamento(const medicamento& orig) {
}

medicamento::~medicamento() {
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
}

void medicamento::SetNombre(char* cad) {
    if(nombre!=NULL) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void medicamento::GetNombre(char *cad) const {
    strcpy(cad,nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

void medicamento::SetTotal(double total) {
    this->total = total;
}

double medicamento::GetTotal() const {
    return total;
}


void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}
/*
41379,5,12/02/2023,50611,51642949,Miranda/Alfonso
30796,5,13/02/2023,50611,51642950,Miranda/Alfonso
 */ 
void medicamento::leemedicamento(ifstream&arch, int codmed){
    int cant,dd,mm,aa,codigo;
    char c,nombre[50];
    double precio;
    
    arch >> cant >> c >>dd >> c >> mm >> c >> aa >> c;
    this->codigo = codmed;
    this->fecha = aa*10000+mm*100+dd;
    this->cantidad = cant;
    /*
    30007,DICLOFENACO SODICO 1MG GTS 5 ML,0.85
    53084,MINOCICLINA 100MG 10T,0.85
     */
    
    ifstream march("medicamentos.csv",ios::in);
    if(!march){
        cout << "No se pudo abrir los medicamentos";
        exit(1);
    } 
    while(1){
        march >> codigo;
        if(march.eof()) break;
        march.get();
        march.getline(nombre,50,',');
        march >> precio;
        if (codigo==codmed){
            this->SetNombre(nombre);
            this->SetPrecio(precio);
            break;
        }
    }
    
}
void medicamento::aplicadescuento(){
    total = (cantidad*precio)*0.9;
}

void medicamento::imprimemedicamento(ofstream &arch){
    arch << setprecision(2)<<fixed; 
    arch << setw(10) << fecha << setw(10) << codigo << setw(40) << nombre;
    arch << setw(10) << cantidad << setw(10) << precio << setw(10) << total;
}