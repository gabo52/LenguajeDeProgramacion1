/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 3 de noviembre de 2022, 09:30 PM
 */

#include <iostream>
#include <iomanip>

#include "FuncionesLecturaEscritura.h"
#include "Medico.h"
#include "Cita.h"
#include "Paciente.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archCit,archMed,archPac;
    AbrirArchivo("ConsultasLab3.txt",archCit);
    AbrirArchivo("MedicosLab3.txt",archMed);
    AbrirArchivo("PacientesLab3.txt",archPac);
    ofstream archRep;
    AbrirArchivo("Rep.txt",archRep);
    Cita cita[100];
    Medico med[100];
    Paciente pac[100];
    archCit>>cita[0];
    for(int i=0;i<20;i++){
        archMed>>med[i];
    }
    
    bool i=cita[0]<=med;
    archPac>>pac[0];
    pac[0]+=cita[0];
    
    cout<<i<<endl;
    archRep<<pac[0];
    return 0;
}

