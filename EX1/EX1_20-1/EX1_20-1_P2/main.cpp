/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

