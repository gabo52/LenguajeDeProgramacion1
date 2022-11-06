/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 3 de octubre de 2022, 06:36 PM
 */

#include <cstdlib>
#include "FuncionesEx01_20201_Preg02.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *sesiones;
    leerSesiones(sesiones);
    imprimirSesiones(sesiones);
    return 0;
}

