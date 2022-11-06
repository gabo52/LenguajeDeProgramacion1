/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 2 de noviembre de 2022, 11:36 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
#include "Libro.h"
#include "LibroPrestado.h"
#include "Usuario.h"
#include <fstream>
#include "FuncionesAuxiliares.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Usuario usuarios[300];
    Libro libros[300];
    int n=0;
    leerUsuarios(usuarios);
    leerLibros(libros);
    cargarLibrosPrestados(usuarios,libros);
//    //funcionFecha
    imprimirLibros(libros);
    imprimirUsuarios(usuarios);
    return 0;
}

