/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 4 de mayo de 2023, 08:23 PM
 */

#include <iostream>
#include <iomanip>
#include "MemoriaDinamica.h"
using namespace std;

int main(int argc, char** argv) {
    char **codigoMed, **medicos;
    double *tarifas;
    cargarMedicos(codigoMed,medicos,tarifas);
    reporteMedicos(codigoMed,medicos,tarifas);
    reporteDeIngresos(codigoMed,medicos,tarifas); 
    return 0;
}

