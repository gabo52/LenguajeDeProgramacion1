/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   farmacia.cpp
 * Author: cueva
 * 
 * Created on 11 de junio de 2023, 11:20 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include "farmacia.h"

using namespace std;

farmacia::farmacia() {
}

farmacia::farmacia(const farmacia& orig) {
}

farmacia::~farmacia() {
}

void farmacia::buscaespecialidad(int codmed,char*cad){
    for(int i=0;lmedico[i].GetCodigo();i++){
        if(codmed==lmedico[i].GetCodigo()){
            lmedico[i].GetEspecialidad(cad);
            break;
        } 
    }    
}

/*
12/02/2023,51642949,Miranda/Alfonso,50611,41379,5,30796,5,86158,23,47697,22,53846,17,31883,19,47697,30
20/08/2022,61061535,Solis/Maria,15092,61039,28,72969,30,22232,21,57269,12,57269,15,37007,19,57036,5,81695,11
18/03/2023,54815159,Patino/Delicia,60184 ,17804,5,75565,26,36711,16,46000,33,12388,17
 */

void farmacia::cargamedicamento(ifstream &arch,int codmed,int dni,char *nombre,int fecha){
    int med,cant,i;
    char c,espe[50];
    
    while(arch.get()!='\n'){
        arch >> med >> c  >> cant;
        if((med/10000)%2==0){
            for(i=0;lconreceta[i].GetCodigo();i++);     //inserto al final del arreglo 
            buscaespecialidad(codmed,espe);
            // forma optima
            lconreceta[i].leeconreceta(codmed,espe,cant,med,fecha);
        }
        else{ //aqui lo hago de otra forma funciona pero es mas desordenada
            for(i=0;lsinreceta[i].GetCodigo();i++);
            lsinreceta[i].leesinreceta(med,fecha,nombre,dni);
            lsinreceta[i].SetCantidad(cant);
        }
    }
}

void farmacia::leerecetas(){
    int i,aa,dd,mm,fecha,dni,codmed;
    char c,nombre[100];
    ifstream arch("recetas.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir las Recetas";
        exit(1);
    }   
    i=0;
    while(1){
        arch >> dd; 
        if(arch.eof())break;
        arch >> c >> mm >> c >> aa >> c;
        fecha = aa*10000 + mm*100 + dd;
        arch >> dni >> c;
        arch.getline(nombre,100,',');
        arch >> codmed;
        cargamedicamento(arch,codmed,dni,nombre,fecha);
    }
}

void farmacia::cargamedicos(){
    int i;
    ifstream arch("medicos.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir las medicos";
        exit(1);
    }   
    i=0;
    while(1){
       lmedico[i].leemedico(arch);
       if(arch.eof())break;
       i++;
    }    
} 


void farmacia::imprimirrecetas(){
    int i;
    char cad[50];
    ofstream arch("reprecetas.txt",ios::out);
    if(!arch){
        cout << "No se pudo abrir las recetas";
        exit(1);
    }     
    for(i=0;lsinreceta[i].GetDni();i++){
        lsinreceta[i].medicamento::GetNombre(cad);
        arch <<left<<setw(10)<< lsinreceta[i].GetCodigo() <<setw(40)<< cad;
        arch << setw(10)<< lsinreceta[i].GetCantidad() <<setw(15)<< lsinreceta[i].GetDni();
        lsinreceta[i].GetNombre(cad);
        arch <<setw(30)<< cad <<setw(10)<< lsinreceta[i].GetPrecio()<<endl; 
    }
    for(i=0;lconreceta[i].GetCodigo();i++){
        lconreceta[i].GetNombre(cad);
        arch <<left<<setw(10)<< lconreceta[i].GetCodigo() <<setw(40)<< cad;
        arch << setw(10)<< lconreceta[i].GetCantidad() <<setw(15)<<lconreceta[i].GetCodmed();
        lconreceta[i].GetEspecialidad(cad);
        arch <<setw(30)<< cad <<setw(10)<< lconreceta[i].GetPrecio()<<endl; 
    }
    
}