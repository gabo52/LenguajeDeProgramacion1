/* 
 * File:   NPaciente.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:35 PM
 */

#include <cstring>

#include "NPaciente.h"

NPaciente::NPaciente() {
    pac=nullptr;
}


NPaciente::~NPaciente() {
    delete &pac;
}

void NPaciente::leer(ifstream &arch){
    char tipo,c;
    arch>>tipo>>c;
    if(arch.eof())return;
    if(tipo=='A'){
        pac = new class Ambulatorio;
    }else if(tipo=='E'){
        pac = new class Emergencia;
    }else pac = new class Urgencia;
    pac->leer(arch);
}


int NPaciente::activo(){
    return pac!=nullptr;
}

int NPaciente::prioridad(){
    if(pac){
        return pac->prioridad();
    }else return 0;
}

void NPaciente::imprimir(ofstream &arch){
    pac->imprimir(arch);
}

bool NPaciente::operator < (const NPaciente &c){
    return pac->prioridad()>c.pac->prioridad();
}

bool NPaciente::operator == (const NPaciente &c){
    return (pac->GetDni())==(c.pac->GetDni());
}

void NPaciente::setNull(){
    pac=nullptr;
}

void NPaciente::actualizaObservaciones(int &pacR,int &pacM){
    char cad[100];
    pac->observacion(cad);
    if(strcmp(cad,"Persona de Riesgo")==0)pacR++;
    if(strcmp(cad,"Debe venir con su apoderado")==0)pacM++;
}
