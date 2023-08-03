/* 
 * File:   Urgencia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:20 PM
 */

#include <cstring>

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

void Urgencia::leer(ifstream &arch){
    int dni,edad;
    char cad[100],c;
    double porc,urg;
    arch>>dni>>c;
    arch.getline(cad,100,',');
    SetNombre(cad);
    arch>>edad>>c;
    arch.getline(cad,100,',');
    SetCodMed(cad);
    arch>>porc>>c>>urg;
    arch.get();
    SetDni(dni);
    SetEdad(edad);
    SetPorcSeguro(porc);
    SetPorcUrgencia(urg);
}



int Urgencia::prioridad(){
    return 200+GetEdad();
}

void Urgencia::observacion(char *cad){
    if(GetEdad()<=18){
        strcpy(cad,"Debe venir con su apoderado");
        return;
    }else cad[0]=0;
    if(GetEdad()>65){
        strcpy(cad,"Persona de Riesgo");
    }else cad[0]=0;
}

void Urgencia::imprimir(ofstream &arch){
    char cad[100];
    GetNombre(cad);
    arch<<setw(15)<<left<<GetDni()<<setw(50)<<left<<cad<<setw(8)<<left<<GetEdad();
    
    observacion(cad);
    arch<<setw(50)<<left<<cad<<endl;
}