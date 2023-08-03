/* 
 * File:   Categoria1.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:06 PM
 */

#include "Categoria1.h"


void Categoria1::SetMinimo(int minimo) {
    this->minimo = minimo;
}

int Categoria1::GetMinimo() const {
    return minimo;
}

void Categoria1::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria1::GetPrioridad() const {
    return prioridad;
}

void Categoria1::leer(ifstream &arch){
    int prio,min,cod,stock;
    char cad[80],c;
    arch>>prio>>c>>min>>c>>cod>>c;
    arch.getline(cad,80,',');
    arch>>stock;
    SetCodprod(cod);
    SetMinimo(min);
    SetNombre(cad);
    SetPrioridad(prio);
    SetStock(stock);
    
}

void Categoria1::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(10)<<left<<GetCodprod()<<setw(50)<<left<<cad<<setw(10)<<left<<GetStock();
    
    arch<<setw(10)<<left<<GetPrioridad()<<setw(10)<<left<<GetMinimo()<<endl;
}

int Categoria1::obtienePrioridad(){
    return GetPrioridad();
}

