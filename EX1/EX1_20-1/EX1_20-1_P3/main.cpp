/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 5 de octubre de 2022, 08:39 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesEx01_20201_Preg01.h"
#include "FuncionesEx01_20201_Preg02.h"
#include "FuncionesEx01_20201_Preg03.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cursos,**profesores;
    int *codProfesores;
    void *sesiones;
    leerDatos(cursos,codProfesores,profesores);
    imprimirDatos(cursos,codProfesores,profesores);
    leerSesiones(sesiones);
    imprimirSesiones(sesiones);
    reporteDeCargaHorariaDeProf(cursos,codProfesores,profesores,sesiones);
    return 0;
}

