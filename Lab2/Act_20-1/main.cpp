/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de septiembre de 2022, 03:16 PM
 */

#include <iomanip>
#include <iostream>
#include "funcionesAux.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    crearCargarAlumnosBin();
    cout<<"0";
    crearCargarConsolidadosBin();
    imprimeRepConsolidadoBin();
    return 0;
}

