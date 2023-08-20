/* 
 * File:   main.cpp
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 */

#include <iostream>
#include <iomanip>
#include "funcionesAuxiliares.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    crearCargarLibrosBin();
    verificarLibrosBin();
    
    crearCargarPrestamosUsuariosBin();
    verificarPrestamosBin();    
    verificarUsuariosBin();
    
    //actualizarLibrosBin();
    //imprimeReporteLibrosBin();
    return 0;
}

