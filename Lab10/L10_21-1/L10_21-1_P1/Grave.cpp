/* 
 * File:   Grave.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:37 PM
 */

#include "Grave.h"



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

void Grave::leer(ifstream &arch){
    int cod,punto;
    char cad[250],c;
    double mul,desc;
    while(1){
        arch>>cod>>c;
        if(arch.eof())break;
        if(cod==GetCodigo()){
            arch.getline(cad,250,',');
            arch.getline(cad,250,',');
            arch>>mul>>c>>desc>>c>>punto;
            SetDescuento(desc);
            SetGravedad(cad);
            SetMulta(mul);
            SetPuntos(punto);
            return;
        }else arch.getline(cad,250,'\n');
    }
}

void Grave::imprimir(ofstream &arch){
    char cad[40];
    GetGravedad(cad);
    arch<<setw(12)<<left<<cad<<setw(10)<<right<<GetMulta()<<setw(10)<<right<<GetDescuento()
            <<setw(10)<<right<<GetPuntos()<<setw(10)<<right<<0<<endl;
}
