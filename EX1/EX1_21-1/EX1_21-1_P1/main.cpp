/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de octubre de 2022, 04:40 PM
 */

#include <iostream>
#include <iomanip>
#include "BibCargaConductores.h"
#include "BibCargaFaltas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **conductor,***placa;
    int *licencia,***falta,***fecha;
    cargarConductores(licencia,conductor,placa);
    reporteConductores(licencia,conductor,placa);
    cargaFaltas(licencia,placa,falta,fecha);
    reporteFaltas(licencia,conductor,placa,falta,fecha);
    return 0;
}

