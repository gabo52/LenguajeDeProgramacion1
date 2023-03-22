/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   marca.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 06:03 PM
 */

#include <cstring>

#include "marca.h"

marca::marca() {
    laboratorio=nullptr;
}


marca::~marca() {
    if(laboratorio)delete laboratorio;
}

void marca::SetLaboratorio(char* cad) {
    if(laboratorio)delete laboratorio;
    laboratorio=new char [strlen(cad)+1];
    strcpy(laboratorio,cad);
}

void marca::GetLaboratorio(char* cad) const {
    if(laboratorio)strcpy(cad,laboratorio);
    else cad[0]=0;
}

void marca::SetLote(int lote) {
    this->lote = lote;
}

int marca::GetLote() const {
    return lote;
}

void marca::operator = (const marca &c){
    char cad[80];
    SetCodigo(c.GetCodigo());
    c.GetLaboratorio(cad);
    SetLaboratorio(cad);
    SetLote(c.GetLote());
    c.GetNombre(cad);
    SetNombre(cad);
    SetPrecio(c.GetPrecio());
    SetStock(c.GetStock());
}

void marca::lee(ifstream &arch){
    int cod,stock,lote;
    double precio;
    char cad[100],c;
    
    arch>>cod>>c;
    arch.getline(cad,80,',');
    arch>>stock>>c>>precio>>c;
    SetCodigo(cod);
    SetNombre(cad);
    SetPrecio(precio); 
    SetStock(stock);

    arch.getline(cad,80,',');
    SetLaboratorio(cad);
    arch>>lote;
    SetLote(lote);
}


void marca::imprime(ofstream &arch){
    char cad[100];
    GetNombre(cad);
    arch<<setw(10)<<left<<GetCodigo();
    arch<<setw(40)<<left<<cad<<setw(10)<<right<<GetStock()<<setw(10)<<right
            <<GetPrecio()<<"   ";
    GetLaboratorio(cad);
    arch<<setw(30)<<left<<cad<<left<<GetLote()<<endl;
}

void marca::copia(medicamento *&med){
    med = new class marca;
    //copiar(med);
}

void marca::copiar(marca &c){
    c = *this;
}
