/* 
 * File:   Antiguo.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:44 PM
 */

#include <cstring>

#include "Antiguo.h"

Antiguo::Antiguo(){
    exmanejo=0;
}



void Antiguo::SetEstado(int estado) {
    this->estado = estado;
}

int Antiguo::GetEstado() const {
    return estado;
}

void Antiguo::SetExmanejo(double exmanejo) {
    this->exmanejo = exmanejo;
}

double Antiguo::GetExmanejo() const {
    return exmanejo;
}

void Antiguo::leer(ifstream &arch,int licencia){
    int lic,cod,cant=0;
    double monto;
    char desc[80],c,cad[]="Muy Grave";
    while(1){
        arch>>lic>>c;
        if(arch.eof())break;
        if(lic==licencia){
            arch>>cod>>c;
            arch.getline(desc,80,',');
            arch>>monto;
            SetExmanejo(GetExmanejo()+500);
            SetExmedico(GetExmedico()+100);
            SetTramite(GetTramite()+100);
            SetMulta(GetMulta()+monto);
            if(strcmp(cad,desc)==0){
                cant++;
            }
        }else arch.getline(desc,80,'\n');
    }
    if(cant>=5)SetEstado(0);
    else SetEstado(1);
}

void Antiguo::imprimir(ofstream &arch){
    char cad[80];
    if(GetEstado()==0){
        arch<<setw(21)<<right<<"   No puede renovar"<<endl;
        return;
    }else arch<<setw(21)<<left<<"            -";
    arch.precision(0);
    arch<<setw(10)<<right<<GetMulta()<<setw(10)<<right<<GetTramite()
            <<setw(10)<<right<<GetExmedico()<<setw(20)<<right<<GetExmanejo();
    arch.precision(2);
    arch<<setw(15)<<right<<GetExmanejo()+GetExmedico()+GetMulta()+GetTramite()<<endl;
    arch.precision(0);
}
