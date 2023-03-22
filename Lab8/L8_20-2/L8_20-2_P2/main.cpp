/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
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

