/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 15 de septiembre de 2022, 09:29 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Estructuras.h"
#include "FuncBiblioteca.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Medico medicos[100];
    strcpy(medicos[0].codigo,"X");
    Paciente pacientes[100];
    pacientes[0].DNI=0;
    Medicinas medicinas[100];
    medicinas[0].codigo=0;
    Consulta citas[200];
    citas[0].cantMedicamentos=0;
    cargarArchivos(medicos,pacientes,medicinas,citas);
    imprimirArchivos(medicos,pacientes);
    return 0;
}

