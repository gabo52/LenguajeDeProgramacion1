/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.cpp
 * Author: cueva
 * 
 * Created on 11 de junio de 2023, 10:38 AM
 */
#include <cstring>
#include <iostream>
#include "medicamento.h"

using namespace std;

medicamento::medicamento() {
    codigo = 0;
    nombre = nullptr;
    cantidad = 0;
    precio = 0;
    fecha = 0;
}

medicamento::medicamento(const medicamento& orig) {
}

medicamento::~medicamento() {
}

void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
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
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void medicamento::GetNombre(char* cad) const {
    strcpy(cad,nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

/*
30007,DICLOFENACO SODICO 1MG GTS 5 ML,0.85
53084,MINOCICLINA 100MG 10T,0.85
68730,MELOXICAM 7.5 MG C/14,0.85
*/
void medicamento::leemedicamento(int codmed){
    int codigo;
    char nommed[100],c;
    double precio;
    
    ifstream arch("medicamentos.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir las medicamentos";
        exit(1);
    }   
    while(1){
        arch >> codigo;
        if(arch.eof()) break;
        arch.get();
        arch.getline(nommed,100,',');
        arch >> precio;
        if(codigo==codmed){    
            this->codigo = codmed;
            SetNombre(nommed);
            this->precio = precio;
            break;
        }
    }
}
