/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 8 de septiembre de 2022, 08:16 PM
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

