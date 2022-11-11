/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:05 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Producto.h"

Producto::Producto() {
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
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

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::SetNombre(char* cad) { 
    if(nombre!=NULL) delete[]nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}
void Producto::GetNombre(char *nom) const {
    strcpy(nom,nombre);
}

//459032,GELATINA DANY LIMON 125GR,5.38,24
//codigo, nombre, precio, stock;
void Producto::cargaproducto(int codigo){
    ifstream arch("productos3.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo productos3.csv";
        exit(1);
    }
    int doc,stockP;
    double precu;
    char cad[100],car;
    while(1){
        arch >> doc;
        if(arch.eof())break;
        arch.get();
        arch.getline(cad,100,',');
        arch>>precu>>car>>stockP;
        if(codigo==doc){
            SetCodprod(doc);
            SetNombre(cad);
            SetPrecio(precu);
            SetStock(stockP);
            break;
        }
    }
}