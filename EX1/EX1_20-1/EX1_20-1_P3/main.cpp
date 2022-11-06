/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
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

