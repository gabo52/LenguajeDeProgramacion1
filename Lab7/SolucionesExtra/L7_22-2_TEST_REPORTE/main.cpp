/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 3 de noviembre de 2022, 10:51 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "Medico.h"
#include "Paciente.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Medico medicos[200];
    Paciente pacientes[200];
    Cita citas[300];
    cargaMedicos(medicos);
    cargaPacientes(pacientes);
    cargaCitas(pacientes,medicos);
    imprimeReporte(pacientes);
    return 0;
}

