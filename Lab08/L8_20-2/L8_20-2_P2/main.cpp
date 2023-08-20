/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 11:38 AM
 */

#include <cstdlib>
#include "ListaDePacientes.h"
#include "FuncionesAuxiliares.h"
#include "AtencionCitas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    AtencionCitas citas;
    citas.leePacientes("AtencionDeCitas.csv");
    citas.imprimePacientes("ReporteDeCitas.txt");
    return 0;
}

