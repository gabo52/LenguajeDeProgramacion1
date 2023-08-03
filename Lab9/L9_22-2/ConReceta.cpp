/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConReceta.cpp
 * Author: cueva
 * 
 * Created on 5 de noviembre de 2022, 10:23 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "ConReceta.h"


using namespace std;

ConReceta::ConReceta() {
    codmed=0;
    especialidad=NULL;
}

ConReceta::ConReceta(const ConReceta& orig) {
}

ConReceta::~ConReceta() {
}

void ConReceta::SetEspecialidad(char* cad) {
    if(especialidad!=NULL) delete especialidad;
    especialidad = new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

void ConReceta::GetEspecialidad(char *cad) const {
    strcpy(cad,especialidad);
}

void ConReceta::leespecialidad(int codmedico){
    int codigo;
    char nombre[50],esp[50];
    ifstream arch("medicos.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir los medicos";
        exit(1);
    }   
    int i=0;
    while(1){
        arch >> codigo;
        if(arch.eof()) break;
        arch.get();
        arch.getline(nombre,50,',');
        arch.getline(esp,50);
        if(codigo==codmedico){
            codmed=codigo;
            SetEspecialidad(esp);
            break;
        }
        i++;
    }
}


void ConReceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int ConReceta::GetCodmed() const {
    return codmed;
}
void ConReceta::leemedicamento(ifstream&arch, int codmed){
    int coddoc,dni;
    char nomdoc[50],c;
    
    medicamento::leemedicamento(arch,codmed); //llama explicita
    arch >> coddoc >> c >> dni >> c;
    this->codmed = coddoc;
    arch.getline(nomdoc,50);
}

void ConReceta::aplicadescuento(){
    medicamento::aplicadescuento();
    this->SetTotal(this->GetTotal()*1.05);
}

void ConReceta::imprimemedicamento(ofstream &arch){
    medicamento::imprimemedicamento(arch);
    arch << setw(10) << codmed << endl;
}
