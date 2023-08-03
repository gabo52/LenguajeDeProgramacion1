/* 
 * File:   Ambulatorio.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de noviembre de 2022, 11:32 AM
 */

#include "Ambulatorio.h"


void Ambulatorio::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Ambulatorio::GetPorcSeguro() const {
    return porcSeguro;
}

void Ambulatorio::leePaciente(ifstream &arch){
    int dni;
    char nomb[80],carac,c,codMed[10];
    double tarif;
    arch>>dni>>c;
    if(arch.eof())return;
    arch.getline(nomb,80,',');
    arch.getline(codMed,10,',');
    arch>>tarif;
    arch.get();
    SetCodMed(codMed);
    SetDni(dni);
    SetNombre(nomb);
    SetPorcSeguro(tarif);
}

void Ambulatorio::operator = (const Ambulatorio &c){
    char cad[80];
    c.GetCodMed(cad);
    SetCodMed(cad);
    SetDni(c.GetDni());
    c.GetNombre(cad);
    SetNombre(cad);
    SetPorcSeguro(c.GetPorcSeguro());
}
void Ambulatorio::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(15)<<left<<GetDni()<<setw(50)<<left<<cad;
    GetCodMed(cad);
    arch<<setw(15)<<left<<cad;;
    arch<<setw(10)<<right<<GetPorcSeguro()<<endl;          
}

int Ambulatorio::seguro(){
    return 1;
}
int Ambulatorio::prioridad(){
    return 1;
}

