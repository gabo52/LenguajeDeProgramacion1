/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   generico.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 06:01 PM
 */

#include <cstring>

#include "generico.h"

generico::generico() {
    pais=nullptr;
}


generico::~generico() {
    if(pais)delete pais;
}

void generico::SetPais(char* cad) {
    if(pais)delete pais;
    pais=new char [strlen(cad)+1];
    strcpy(pais,cad);
}

void generico::GetPais(char* cad) const {
    if(pais)strcpy(cad,pais);
    else cad[0]=0;
}


void generico::operator = (const generico &c){
    char cad[80];
    SetCodigo(c.GetCodigo());
    c.GetNombre(cad);
    SetNombre(cad);
    c.GetPais(cad);
    SetPais(cad);
    SetPrecio(c.GetPrecio());
    SetStock(c.GetStock());
}

void generico::lee(ifstream &arch){
    int cod,stok,lote;
    double prec;
    char cad[100],c;
    
    arch>>cod>>c;
    arch.getline(cad,80,',');
    arch>>stok>>c>>prec>>c;
    SetCodigo(cod);
    SetNombre(cad);
    SetPrecio(prec); 
    SetStock(stok);
    
    arch.getline(cad,80,'\n');
    SetPais(cad);

}


void generico::imprime(ofstream &arch){
    char cad[100];
    GetNombre(cad);
    arch<<setw(10)<<left<<GetCodigo();
    arch<<setw(40)<<left<<cad<<setw(10)<<right<<GetStock()<<setw(10)<<right
            <<GetPrecio()<<"   ";
    GetPais(cad);
    arch<<left<<cad<<endl;
}

void generico::copia(medicamento *&med){
    med = new class generico;
}

void generico::copiar(generico &c){
    c = *this;
}

