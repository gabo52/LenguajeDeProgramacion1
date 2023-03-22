/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.cpp
 * Author: Gabo
 * 
 * Created on 15 de noviembre de 2022, 06:39 PM
 */

#include "Registro.h"



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

void Registro::leeInfraccion(ifstream &arch,int cod){
    int codigo;
    char c,cad[300];
    pfalta->SetCodigo(cod);
    while(1){
        arch>>codigo>>c;
        if(codigo==cod){
            pfalta->lee(arch);
            return ;
        }
        if(arch.eof())break;
        arch.getline(cad,300,'\n');
    }
}

void Registro::leeConductores(ifstream &arch,int licencia){
    int lic;
    char nomb[80],c;
    while(1){
        arch>>lic>>c;
        if(arch.eof())break;
        arch.getline(nomb,80);
        if(lic==licencia){
            SetNombre(nomb);
            return;
        }
    }
}

void Registro::imprimeReg(ofstream &arch){
    char cad[80];
    GetNombre(cad);
    arch<<"Conductor: "<<cad<<endl;
    pfalta->imprime(arch);
}

void Registro::leeRegistro(ifstream &arch){    
    ifstream archInfrac,archConductor;
    AbrirArchivo("Infracciones.csv",archInfrac);
    AbrirArchivo("Conductores.csv",archConductor);
    int dni,infrac,dd,mm,aa;
    char c,cad[80];
    arch>>dni>>c>>infrac>>c>>dd>>c>>mm>>c>>aa>>c;
    if(arch.eof())return;
    arch.getline(cad,80,'\n');
    if(infrac/100==2){
        pfalta = new  class Leve;
    }else if (infrac/100==1){
        pfalta = new  class Grave;
    }else{
        pfalta = new  class MuyGrave;
    }
    leeInfraccion(archInfrac,infrac);
    leeConductores(archConductor,dni);
    SetFecha(dd+mm*100+aa*10000);
    SetLicencia(dni);
    SetPlaca(cad);
}

