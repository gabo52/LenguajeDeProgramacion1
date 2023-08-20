

/* 
 * File:   Biblioteca.cpp
 * Author: USER
 * 
 * Created on 21 de junio de 2023, 07:04 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Biblioteca.h"
#include "Copia.h"
#include "FuncionesFecha.h"
using namespace std;

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::GeneraCopias(){
    char codlib[10], tit[200], aut[200], c;
    int anho, cant, i, j, n = 0, zone;
    double prec; 
    
    ifstream arch("Libros2.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo Libros2.csv";
        exit(1);
    } 
    
    i=0;
    while(1){
        arch.getline(codlib,10,',');
        if(arch.eof()) break; 
        arch.getline(tit,200,',');
        arch.getline(aut,200,',');
        arch >> anho >> c >> cant >> c >> prec >> c >> zone;
        arch.get(); 
        
        j = 0; 
        for(i=n;j<cant;i++){
            llibros[i].copiar(codlib, tit, aut, cant, prec, j+1, zone);
            j++;  
        }
        n = n + cant;
    }
}

void Biblioteca::ActualizaLibros(){
    for(int i=0;llibros[i].existe();i++) llibros[i].actualizar(); //este no es el polimorfico 
}

void Biblioteca::ImprimeCopias(){
    ofstream arch("RepCopias.txt",ios::out);
    if(!arch){
        cout << "No se pudo abrir el reporte";
        exit(1);
    }    
    for(int i=0;llibros[i].existe();i++) llibros[i].imprimelibros(arch);
    
}


