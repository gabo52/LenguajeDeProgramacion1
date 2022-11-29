/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 05:58 PM
 */

#include <cstring>

#include "medicamento.h"

medicamento::medicamento() {
    nombre=nullptr;
}


medicamento::~medicamento() {
    if(nombre)delete nombre;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetStock(int stock) {
    this->stock = stock;
}

int medicamento::GetStock() const {
    return stock;
}

void medicamento::SetNombre(char* cad) {
    if(nombre)delete nombre;
    nombre=new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void medicamento::GetNombre(char* cad) const {
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

