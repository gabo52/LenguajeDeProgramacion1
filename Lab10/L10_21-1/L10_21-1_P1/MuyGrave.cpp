/* 
 * File:   MuyGrave.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:38 PM
 */

#include "MuyGrave.h"

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

void MuyGrave::leer(ifstream &arch){
    int cod,punto,mes;
    char cad[250],c;
    double mul;
    while(1){
        arch>>cod>>c;
        if(arch.eof())break;
        if(cod==GetCodigo()){
            arch.getline(cad,250,',');
            arch.getline(cad,250,',');
            arch>>mul>>c>>punto>>c>>mes;
            SetMeses(mes);
            SetGravedad(cad);
            SetMulta(mul);
            SetPuntos(punto);
            return;
        }else arch.getline(cad,250,'\n');
    }
}

void MuyGrave::imprimir(ofstream &arch){
    char cad[40];
    GetGravedad(cad);
    arch<<setw(12)<<left<<cad<<setw(10)<<right<<GetMulta()<<setw(10)<<right<<0.0
            <<setw(10)<<right<<GetPuntos()<<setw(10)<<right<<GetMeses()<<endl;
}

