/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 6 de noviembre de 2022, 11:36 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
#include "FuncionesAuxiliares.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Miembro miembros;
    leemiembro(miembros);
    imprimeReportes(miembros);
    return 0;
}

