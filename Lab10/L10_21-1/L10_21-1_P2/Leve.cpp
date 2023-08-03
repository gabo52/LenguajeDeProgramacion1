/* 
 * File:   Leve.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:36 PM
 */

#include "Leve.h"



void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

void Leve::leer(ifstream &arch){
    int cod;
    char cad[250],c;
    double mul,desc;
    while(1){
        arch>>cod>>c;
        if(arch.eof())break;
        if(cod==GetCodigo()){
            arch.getline(cad,250,',');
            arch.getline(cad,250,',');
            arch>>mul>>c>>desc;
            SetDescuento(desc);
            SetGravedad(cad);
            SetMulta(mul);
            return;
        }else arch.getline(cad,250,'\n');
    }
}

void Leve::imprimir(ofstream &arch){
    char cad[40];
    GetGravedad(cad);
    arch<<setw(12)<<left<<cad<<setw(10)<<right<<GetMulta()<<setw(10)<<right<<GetDescuento()
            <<setw(10)<<right<<0<<setw(10)<<right<<0<<endl;
    
}

