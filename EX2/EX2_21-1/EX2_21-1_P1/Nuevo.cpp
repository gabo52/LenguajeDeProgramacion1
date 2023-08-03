/* 
 * File:   Nuevo.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:45 PM
 */

#include <cstring>

#include "Nuevo.h"

Nuevo::Nuevo(){
    exreglas=0;
}

void Nuevo::SetExreglas(double exreglas) {
    this->exreglas = exreglas;
}

double Nuevo::GetExreglas() const {
    return exreglas;
}

void Nuevo::leer(ifstream &arch,int licencia){
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
            SetExreglas(GetExreglas()+150);
            SetExmedico(GetExmedico()+100);
            SetTramite(GetTramite()+200);
            if(strcmp(cad,desc)==0){
                SetMulta(GetMulta()+monto);
            }
        }else arch.getline(desc,80,'\n');
    }
}

void Nuevo::imprimir(ofstream &arch){
    char cad[80];
    arch<<setw(21)<<left<<"            -";
    arch.precision(0);
    arch<<setw(10)<<right<<GetMulta()<<setw(10)<<right<<GetTramite()
            <<setw(10)<<right<<GetExmedico()<<setw(20)<<right<<GetExreglas();
    arch.precision(2);
    arch<<setw(15)<<right<<GetExreglas()+GetExmedico()+GetMulta()+GetTramite()<<endl;
    arch.precision(0);
}

