/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 18 de septiembre de 2022, 10:06 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesActividad04.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **nombres,***cursos;
    int *codigos;
    leerAlumnos(codigos,nombres,cursos);
    imprimirAlumnos(codigos,nombres);
    cout<<"Llegue2";
    leerCursos(codigos,cursos);
    imprimirReporte(codigos,nombres,cursos);
    return 0;
}

