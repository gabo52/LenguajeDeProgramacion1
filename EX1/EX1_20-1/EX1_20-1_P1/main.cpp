/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 3 de octubre de 2022, 05:43 PM
 */

#include <cstdlib>
#include "FuncionesEx01_20201_Preg01.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cursos,**profesores;
    int *codProfesores;
    leerDatos(cursos,codProfesores,profesores);
    imprimirDatos(cursos,codProfesores,profesores);
    return 0;
}

