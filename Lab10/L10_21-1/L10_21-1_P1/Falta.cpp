/* 
 * File:   Falta.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371 
 * Created on 23 de noviembre de 2022, 06:34 PM
 */

#include <cstring>

#include "Falta.h"

Falta::Falta() {
    licencia=0;
    placa=nullptr;
}

Falta::~Falta() {
    if(placa)delete placa;
}

void Falta::SetPlaca(char* cad) {
    if(placa)delete placa;
    placa = new char [strlen(cad)+1];
    strcpy(placa,cad);
}

void Falta::GetPlaca(char* cad) const {
    if(placa)strcpy(cad,placa);
    else cad[0]=0;
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}

void Falta::operator = (const Falta &c){
    char cad[80];
    SetFecha(c.GetFecha());
    SetLicencia(c.GetLicencia());
    c.GetPlaca(cad);
    SetPlaca(cad);
}

void Falta::leer(ifstream &arch){
    int lic,dd,mm,aa;
    char c,plac[20];
    arch>>lic>>c;
    if(arch.eof())return;
    arch.getline(plac,20,',');
    arch>>dd>>c>>mm>>c>>aa>>c;
    SetFecha(dd+mm*100+aa*10000);
    SetLicencia(lic);
    SetPlaca(plac);
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(4)
            <<right<<aa<<"/"<<setw(2)<<right<<mm<<"/"<<setw(2)<<right<<dd<<setfill(' ');
    
}

void operator << (ofstream &arch,const Falta &F){
    imprimeFecha(F.GetFecha(),arch);
    char cad[40];
    F.GetPlaca(cad);
    arch<<"  "<<setw(12)<<left<<F.GetLicencia()<<setw(15)<<left<<cad;
}
