/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de septiembre de 2022, 10:33 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include "funcionesAuxiliares.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    crearCargarConductorFaltasCometidasBin();
    verificarConductoresBin();
    verificarFaltasCometidasBin();
    crearCargarListadoInfracciones();
    verificarListadoInfracciones();
    completarConductoresFaltasCometidasBin();
    verificarConductoresBin();
    verificarFaltasCometidasBin();
    actualizarConductoresFaltasCometidasBin();
    verificarConductoresBin();
    verificarFaltasCometidasBin();
    return 0;
}

