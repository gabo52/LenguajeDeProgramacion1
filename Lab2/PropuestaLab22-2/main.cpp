/* 
 * File:   main.cpp
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 */

#include <iostream>
#include <iomanip>
#include "funcionesAux.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    crearCargarMedicosBin();
    verificarMedicosBin();
    crearCargarMedicinasBin();
    verificarMedicinasBin();
    crearCargarPacientesBin();
//    verificarPacientesBin();
    crearReporteMedicos();
    return 0;
}

