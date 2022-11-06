/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 * Codigo: 20203371
 * Created on 24 de octubre de 2022, 08:06 AM
 */

#include <iostream>
#include <iomanip>
#include "PriorityQueu.h"
#include "ColaPacientes.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *cola;
    ifstream arch;
    ofstream archRep;
    AbrirArchivo("Pacientes.csv",arch);
    AbrirArchivo("Reporte.txt",archRep);
    crearCola(cola,arch,obtienePrioridadPaciente,leeRegistroPaciente);
    prueba(cola,imprimeRegPacientes,archRep);   
    return 0;
}

