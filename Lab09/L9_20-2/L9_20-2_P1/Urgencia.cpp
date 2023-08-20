/* 
 * File:   Urgencia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de noviembre de 2022, 11:32 AM
 */

#include "Urgencia.h"


void Urgencia::SetPorcUrgencia(double porcUrgencia) {
    this->porcUrgencia = porcUrgencia;
}

double Urgencia::GetPorcUrgencia() const {
    return porcUrgencia;
}

void Urgencia::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Urgencia::GetPorcSeguro() const {
    return porcSeguro;
}

void Urgencia::operator = (const Urgencia &c){
    char cad[80];
    SetPorcSeguro(c.GetPorcSeguro());
    SetPorcUrgencia(c.GetPorcUrgencia());
    c.GetCodMed(cad);
    SetCodMed(cad);
    SetDni(c.GetDni());
    c.GetNombre(cad);
    SetNombre(cad);
}

void Urgencia::leePaciente(ifstream &arch){
    int dni;
    char nomb[80],carac,c,codMed[10];
    double tarif,desc;
    arch>>dni>>c;
    if(arch.eof())return;
    arch.getline(nomb,80,',');
    arch.getline(codMed,10,',');
    arch>>tarif>>c>>desc;
    arch.get();
    SetCodMed(codMed);
    SetDni(dni);
    SetNombre(nomb);
    SetPorcSeguro(tarif);
    SetPorcUrgencia(desc);
}

void Urgencia::imprime(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<setw(15)<<left<<GetDni()<<setw(50)<<left<<cad;
    GetCodMed(cad);
    arch<<setw(15)<<left<<cad;;
    arch<<setw(10)<<right<<GetPorcSeguro()<<setw(10)<<right<<GetPorcUrgencia()<<endl;          
}

int Urgencia::seguro(){
    return 1;
}
int Urgencia::prioridad(){
    return 2;
}

