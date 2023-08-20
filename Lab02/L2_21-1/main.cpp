/* 
 * File:   main.cpp
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
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

