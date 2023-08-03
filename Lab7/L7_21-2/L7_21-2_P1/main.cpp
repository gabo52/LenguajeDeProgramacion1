/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 7 de junio de 2023, 10:16 AM
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"
#include "Libro.h"
#include "LibroPrestado.h"
#include "Sobrecargas.h"
#include "Usuario.h"

using namespace std;

int main(int argc, char** argv) {
    int fecha = 20210910; 
    Libro lib[50]; 
    Usuario lUsu[50];
    LibroPrestado lPrest[200]; 
    
    cargarUsuarios(lUsu);
    cargarLibros(lib);
    cargarActualizarPrestamos(lPrest, lib, lUsu); 
    determinarDeudas(fecha, lUsu); 
    imprimirUsuarios(lUsu); 
    imprimirLibros(lib); 
    return 0;
}

