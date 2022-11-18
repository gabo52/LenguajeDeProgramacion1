/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Leve.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:30 PM
 */

#include "Leve.h"

//Leve::Leve(const Leve& orig) {
//    *this = orig;
//}

void Leve::operator = (const Leve &c){
    char cad[80];
    c.GetGravedad(cad);
    SetGravedad(cad);
    SetDescuento(c.GetDescuento());
    SetCodigo(c.GetCodigo());
    SetMulta(c.GetMulta());
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

void Leve::lee(ifstream &arch){
    char cad[300],aux[]="Leve",c;
    double multa,desc;
    arch.getline(cad,300,',');
    arch.getline(cad,300,',');
    SetGravedad(cad);
    arch>>multa>>c>>desc;
    SetDescuento(desc);
    SetMulta(multa);
}


void Leve::imprime(ofstream &arch){
    char cad[80];
    GetGravedad(cad);
    arch<<setw(20)<<left<<GetCodigo()<<setw(20)<<left<<cad<<setw(20)<<left<<
            GetMulta()<<setw(20)<<right<<GetDescuento()<<endl;
}

void Leve::aplica(){
    SetMulta(GetMulta()*(1-GetDescuento()));
}

void Leve::sumaDatos(int &puntos,int &meses,double &monto){
    monto+=GetMulta();
}
