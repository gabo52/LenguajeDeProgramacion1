/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:40 PM
 */

#include "Procesa.h"




Procesa::Procesa() {
    cantidad = 0;
}

Procesa::~Procesa() {
}

void Procesa::leer(){
    ifstream arch;
    AbrirArchivo("RegistroDeFaltas.csv",arch);
    while(1){
        lregistro[cantidad].leeRegistro(arch);
        if(arch.eof())break;
        cantidad++;
    }
}



void Procesa::imprimir(){
    ofstream arch;
    arch.precision(2);
    arch<<fixed;
    AbrirArchivo("Reporte.txt",arch);
    for(int i=0;i<cantidad;i++){
        lregistro[i].imprimeReg(arch);
    }
}

void Procesa::aplicar(){
    for(int i=0;i<cantidad;i++){
        lregistro[i].aplicarReg();
    }
}

void Procesa::consolidar(){
    ifstream arch;
    ofstream archRep;
    AbrirArchivo("sancionados.csv",arch);
    AbrirArchivo("Consolidar.txt",archRep);
    int licencia;
    while(1){
        arch>>licencia;
        if(arch.eof())break;
        imprimeConsolidar(archRep,licencia);
    }
}

void imprimeLinea(ofstream &arch,int cantidad,char c){
    for(int i=0;i<cantidad;i++)arch<<c;
    arch<<endl;
}

void Procesa::imprimeConsolidar(ofstream &arch,int licencia){
    char nomb[80];
    int puntos=0,meses=0;
    double monto=0;
    for(int i=0;i<cantidad;i++){
        if(lregistro[i].GetLicencia()==licencia){
            lregistro[i].GetNombre(nomb);
            lregistro[i].sumaDatosInfraccion(puntos,meses,monto);
        }
    }
    arch<<"Conductor   :"<<left<<nomb<<endl;
    arch<<"Licencia No.:"<<left<<licencia<<endl;
    imprimeLinea(arch,50,'-');
    arch<<left<<setw(20)<<"Monto de Multas:"<<setw(10)<<right<<monto<<endl;
    arch<<left<<setw(20)<<"Puntos perdidos:"<<setw(10)<<right<<puntos<<endl;
    arch<<left<<setw(20)<<"Meses sancionados:"<<setw(10)<<right<<meses<<endl;
    arch<<endl;
}