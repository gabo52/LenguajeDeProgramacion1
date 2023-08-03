/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 04:15 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "sobrecarga.h"
#include "Estructura.h"
using namespace std;

int buscarConductor(const struct ConductorSt *conductores, int n, int licencia){
    int i; 
    for(i=0;i<n;i++){
        if(conductores[i].licencia == licencia) return i;
    }
    return -1; 
}

int main(int argc, char** argv) {
    int l, p = 0, i = 0, j = 0, k = 0, posicion;
    
    struct ConductorSt conductores[700]; 
    struct InfraccionEstabSt infracciones[700]; 
    struct InfraccionSt infracciones2[700]; 
    
    ifstream archConductores("Conductores.txt", ios::in);
    if(!archConductores){
        cout << "El archivo Conductores.txt no existe"; 
        exit(1);
    }
    
    ifstream archInfracciones("Infracciones.txt", ios::in);
    if(!archInfracciones){
        cout << "El archivo Infracciones.txt no existe"; 
        exit(1);
    }
    
    ifstream archRegistro("RegistroDeFallas.txt", ios::in);
    if(!archRegistro){
        cout << "El archivo RegistroDeFallas.txt no existe"; 
        exit(1);
    }
    
    ofstream archReporte("Reporte.txt", ios::out);
    if(!archReporte){
        cout << "El archivo Reporte.txt no existe"; 
        exit(1);
    }
    
    ofstream archReporteFinal("ReporteFinal.txt", ios::out);
    if(!archReporteFinal){
        cout << "El archivo ReporteFinal.txt no existe"; 
        exit(1);
    }
    
    while(archConductores >> conductores[i]) i++; 
    
    while(archRegistro >> infracciones2[k]){
        posicion = buscarConductor(conductores, i, infracciones2[k].licencia);
        conductores[posicion] + infracciones2[k];
        k++;
    }
    
    while(archInfracciones >> infracciones[j]) j++; 
    
    for(l=0;l<i;l++){
        for(p=0;p<j;p++) conductores[l] + infracciones[p]; 
    }
    
    for(l=0;l<i;l++) conductores[l]++;
    for(l=0;l<i;l++) archReporte << conductores[l]; 
    for(l=0;l<i;l++) conductores[l] * 20200710; 
    for(l=0;l<i;l++) archReporteFinal << conductores[l]; 
    
    return 0;
}

