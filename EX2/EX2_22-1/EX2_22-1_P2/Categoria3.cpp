/* 
 * File:   Categoria3.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:09 PM
 */

#include "Categoria3.h"

void Categoria3::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria3::GetDescuento() const {
    return descuento;
}

void Categoria3::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria3::GetPrioridad() const {
    return prioridad;
}

void Categoria3:: leer(ifstream &arch){
    int prio,cod,stock;
    double desc;
    char cad[80],c;
    arch>>prio>>c>>desc>>c>>cod>>c;
    arch.getline(cad,80,',');
    arch>>stock;
    SetCodprod(cod);
    SetNombre(cad);
    SetPrioridad(prio);
    SetStock(stock);
}

void Categoria3::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(10)<<left<<GetCodprod()<<setw(50)<<left<<cad<<setw(10)<<left<<GetStock();
    
    arch<<setw(10)<<left<<GetPrioridad()<<setw(10)<<left<<GetDescuento()<<endl;
}

int Categoria3::obtienePrioridad(){
    return GetPrioridad();
}




