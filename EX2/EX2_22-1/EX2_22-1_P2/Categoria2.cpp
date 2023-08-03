/* 
 * File:   Categoria2.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 03:07 PM
 */

#include "Categoria2.h"

void Categoria2::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria2::GetDescuento() const {
    return descuento;
}

void Categoria2::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria2::GetPrioridad() const {
    return prioridad;
}

void Categoria2:: leer(ifstream &arch){
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

void Categoria2::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(10)<<left<<GetCodprod()<<setw(50)<<left<<cad<<setw(10)<<left<<GetStock();
    
    arch<<setw(10)<<left<<GetPrioridad()<<setw(10)<<left<<GetDescuento()<<endl;
}

int Categoria2::obtienePrioridad(){
    return GetPrioridad();
}
