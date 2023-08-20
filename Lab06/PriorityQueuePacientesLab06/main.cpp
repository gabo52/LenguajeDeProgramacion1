/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

