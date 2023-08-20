/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cita.cpp
 * Author: Gabo
 * 
 * Created on 3 de noviembre de 2022, 09:32 PM
 */
#include <iomanip>
#include <iostream>
#include "Cita.h"
#include "Medico.h"
using namespace std;

Cita::Cita() {
    codMed=0;
    especialidad=nullptr;
}

Cita::~Cita() {
    eliminar();
}


void Cita::eliminar(){
    if(especialidad)delete especialidad;
}

void Cita::setEspecialidad(char* cad) {
    if(especialidad)delete especialidad;
    if(cad){
        especialidad = new char [strlen(cad)+1];
        strcpy(especialidad,cad);
    }else{
        especialidad = new char [2];
        strcpy(especialidad,"0");
    }
}

void Cita::getEspecialidad(char *cad) const {
    if(especialidad)strcpy(cad,especialidad);
    else strcpy(cad,"0");
}

void Cita::setTarifaPorConsulta(double tarifaPorConsulta) {
    this->tarifaPorConsulta = tarifaPorConsulta;
}

double Cita::getTarifaPorConsulta() const {
    return tarifaPorConsulta;
}

void Cita::setFecha(int fecha) {
    this->fecha = fecha;
}

int Cita::getFecha() const {
    return fecha;
}

void Cita::setCodMed(int codMed) {
    this->codMed = codMed;
}

int Cita::getCodMed() const {
    return codMed;
}

void Cita::operator = (const Cita &c){
    codMed = c.getCodMed();
    char cadena[100];
    c.getEspecialidad(cadena);
    setEspecialidad(cadena);
    setFecha(c.getFecha());
    setTarifaPorConsulta(c.getTarifaPorConsulta());
}


void Cita::imprimeCita(ofstream &arch){
    int fecha=getFecha();
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd
            <<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<setfill(' ');
    char cadena[200];
    getEspecialidad(cadena);
    arch<<setw(26)<<right<<getCodMed()<<setw(25)<<right<<cadena<<setw(10)<<right
            <<getTarifaPorConsulta();
}

bool Cita::operator <=(Medico *arr){
    for(int i=0;arr[i].GetCodigo();i++){
        if(getCodMed()==arr[i].GetCodigo()){
            char cadena[200];
            arr[i].GetEspecialidad(cadena);
            setEspecialidad(cadena);
            setTarifaPorConsulta(arr[i].GetTarifaxconsulta());
            return true;
        }
    }
    return false;
}
