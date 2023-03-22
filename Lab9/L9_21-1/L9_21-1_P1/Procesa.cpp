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
