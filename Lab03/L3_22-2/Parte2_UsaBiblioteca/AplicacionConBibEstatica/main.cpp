/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196401
 */

#include <iostream>
#include <iomanip>
#include "funciones.hpp"
using namespace std;

int main(int argc, char** argv) {
    StMedico medico[50];
    StPaciente paciente[100];
//    StCita cita;
    //funciones de la 2da parte
    leerMedicos(medico);
    leerPacientes(paciente);
    leerCitas(medico,paciente);
    gastosPaciente(paciente);
    reporte(paciente);
    return 0;
}

