/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de septiembre de 2022, 02:36 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "BibManejoDinamicoDeMemoria.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char **conductor,***placa;
    int *licencia,**falta;
    double **multa;
    cargaConductores(licencia,conductor);
    reporteConductores(licencia,conductor);
    cargaFaltas(licencia,placa,falta);
    reporteFaltas(licencia,conductor,placa,falta);
    resumenFaltas(licencia,falta,multa);
    reporteMultas(licencia,conductor,multa);
    return 0;
}

