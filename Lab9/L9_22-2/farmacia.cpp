/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   farmacia.cpp
 * Author: cueva.r
 * 
 * Created on 14 de junio de 2023, 11:02 AM
 */
#include <iostream>
#include <fstream>
#include "farmacia.h"

using namespace std;

farmacia::farmacia() {
}

farmacia::farmacia(const farmacia& orig) {
}

farmacia::~farmacia() {
}
/*
41379,5,12/02/2023,50611,51642949,Miranda/Alfonso
30796,5,13/02/2023,50611,51642950,Miranda/Alfonso
 */

void farmacia::leerecetas(){
    int codmed,i;
            
    ifstream arch("recetas2.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir las recetas";
        exit(1);
    }   
    i=0;
    while(1){
        arch >> codmed;
        if(arch.eof()) break;
        arch.get();
        loferta[i].leeoferta(arch,codmed);
        i++;
    }
    
}
void farmacia::descuenta(){
    for(int i=0;loferta[i].existe();i++)
        loferta[i].aplicadescuento(); //este no es el polimorfico
}
void farmacia::imprimerecetas(){
    ofstream arch("RepReceta.txt",ios::out);
    if(!arch){
        cout << "No se pudo abrir el reporte";
        exit(1);
    }    
    for(int i=0;loferta[i].existe();i++)
        loferta[i].imprimeoferta(arch);
    
}