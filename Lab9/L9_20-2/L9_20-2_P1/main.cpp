/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 11:30 AM
 */

#include <iostream>
#include <iomanip>
#include "Paciente.h"
#include "Ambulatorio.h"
#include "Emergencia.h"
#include "Urgencia.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch;
    arch.open("AtencionDeCitas.csv",ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo AtencionDeCitas.csv";
        exit(1);
    }
    
    ofstream archRep;
    archRep.open("Prueba.txt",ios::out);
    if(!archRep){
        cout<<"Error, no se pudo abrir el archivoPrueba.txt";
        exit(1);
    }
    
    Paciente *pac;
    char tipo,c;
    while(1){
        arch>>tipo>>c;
        if(arch.eof())break;
        if(tipo=='A'){
            pac = new Ambulatorio;
        }else if(tipo=='E'){
            pac = new Emergencia;
        }else pac = new Urgencia;
        pac->leePaciente(arch);
        pac->imprime(archRep);
    }
    
    return 0;
}

