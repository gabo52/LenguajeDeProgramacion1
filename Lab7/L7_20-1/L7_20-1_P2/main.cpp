/* 
 * File:   main.cpp
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 1 de noviembre de 2022, 11:08 AM
 */

#include <iostream>
#include <iomanip>
#include "Acurso.h"
#include "Alumno.h"
#include "Curso.h"
#include "funcionesAuxiliares.h"
#include "funcionesP2.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Alumno alumnos[200];
    int nAlum=0,nacursos=0;
    Acurso acursos[200];
    leerAlumnos(alumnos,nAlum);
    completarDatosAlumnos(alumnos,nAlum);
    actualizarAlumnos(alumnos,nAlum);
    imprimirAlumnos(alumnos,nAlum);
    return 0;
}

