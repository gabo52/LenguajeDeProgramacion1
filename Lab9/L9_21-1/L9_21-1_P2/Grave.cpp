/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grave.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:33 PM
 */

#include "Grave.h"


//Grave::Grave(const Grave& orig) {
//    *this = orig;
//}

void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

void Grave::operator = (const Grave &c){
    char cad[80];
    c.GetGravedad(cad);
    SetGravedad(cad);
    SetDescuento(c.GetDescuento());
    SetCodigo(c.GetCodigo());
    SetMulta(c.GetMulta());
    SetPuntos(c.GetPuntos());
}

void Grave::lee(ifstream &arch){
    char cad[300],aux[]="Grave",c;
    double multa,desc;
    int point;
    arch.getline(cad,300,',');
    arch.getline(cad,300,',');
    SetGravedad(cad);
    arch>>multa>>c>>desc>>c>>point;
    SetDescuento(desc);
    SetMulta(multa);
    SetPuntos(point);
}


void Grave::imprime(ofstream &arch){
    char cad[80];
    GetGravedad(cad);
    arch<<setw(20)<<left<<GetCodigo()<<setw(20)<<left<<cad<<setw(20)<<left<<
            GetMulta()<<setw(20)<<right<<GetDescuento()<<setw(10)<<right<<GetPuntos()<<endl;
}

void Grave::aplica(){
    SetMulta(GetMulta()*(1-GetDescuento()));
}

void Grave::sumaDatos(int &puntos,int &meses,double &monto){
    monto+=GetMulta();
    puntos+=GetPuntos();
}


