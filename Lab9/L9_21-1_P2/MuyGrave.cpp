/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MuyGrave.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:37 PM
 */

#include "MuyGrave.h"


//MuyGrave::MuyGrave(const MuyGrave& orig) {
//}

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

void MuyGrave::operator = (const MuyGrave &c){
    char cad[80];
    c.GetGravedad(cad);
    SetGravedad(cad);
    SetMeses(c.GetMeses());
    SetCodigo(c.GetCodigo());
    SetMulta(c.GetMulta());
    SetPuntos(c.GetPuntos());
}

void MuyGrave::lee (ifstream &arch){
    char cad[300],aux[]="Muy Grave",c;
    double multa,desc;
    int point,month;
    arch.getline(cad,300,',');
    arch.getline(cad,300,',');
    SetGravedad(cad);
    arch>>multa>>c>>point>>c>>month;
    SetMulta(multa);
    SetPuntos(point);
    SetMeses(month);
}


void MuyGrave::imprime(ofstream &arch){
    char cad[80];
    GetGravedad(cad);
    arch<<setw(20)<<left<<GetCodigo()<<setw(20)<<left<<cad<<setw(20)<<left<<
            GetMulta()<<setw(20)<<right<<GetMeses()<<setw(10)<<right<<GetPuntos()<<endl;
}

void MuyGrave::sumaDatos(int &puntos,int &meses,double &monto){
   monto+=GetMulta();
   meses+= GetMeses();
   puntos+=GetPuntos();
}

void MuyGrave::aplica(){
    return;
}
