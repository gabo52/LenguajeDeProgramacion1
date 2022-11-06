/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 20 de octubre de 2022, 10:17 PM
 */

#include <iostream>
#include <iomanip>
#include "PriorityQueu.h"
#include "ColaEnteros.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *cola;
    ifstream arch;
    ofstream archRep;
    AbrirArchivo("Datos.txt",arch);
    AbrirArchivo("Reporte.txt",archRep);
    crearCola(cola,arch,obtienePrioridadEnteros,leeRegistroEnteros);
    prueba(cola,imprimeRegEnteros,archRep);
    return 0;
}

