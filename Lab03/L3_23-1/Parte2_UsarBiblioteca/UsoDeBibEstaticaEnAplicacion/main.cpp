/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#include <iostream>
#include <iomanip>
#include "funciones.hpp"
using namespace std;

int main(int argc, char** argv) {
    struct StCurso arregloCurso[20];
    struct StAlumno arregloAlumno[200];
    leerCursos(arregloCurso);
    leerAlumnos(arregloAlumno);
    leerMatricula(arregloCurso,arregloAlumno);
    calcularIngresosYCostos(arregloCurso,arregloAlumno);
    realizarReporte(arregloCurso,arregloAlumno);
    return 0;
}

