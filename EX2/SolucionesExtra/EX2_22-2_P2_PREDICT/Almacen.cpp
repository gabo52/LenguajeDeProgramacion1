/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: Gabo
 * 
 * Created on 27 de noviembre de 2022, 06:10 PM
 */

#include "Almacen.h"



void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void Almacen::carga(){
    ifstream arch;
    AbrirArchivo("medicamentos.csv",arch);
    medicamento *med;
    int num;
    char c;
    while(1){
        arch>>num>>c;
        if(arch.eof())break;
        if(num==0){
            med = new class generico;
        }else{
            med = new class marca;
        }
        med->lee(arch);
        cola.encola(med);
    }
}

void Almacen::actualiza(){
    medicamento *med;
    while(!cola.empty()){
        cola.desencola(med);
        arbolito.inserta(med);
    }
}

void Almacen::imprime(){
    ofstream arch;
    AbrirArchivo("ReporteMedicamentos.txt",arch);
    arbolito.eliminar(36711);
    arbolito.imprimir(arch);
}

