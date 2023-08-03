/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 10:33 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Biblioteca.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Biblioteca biblioteca;
    biblioteca.leeLibros("Libros.csv");
    biblioteca.imprimeLibros("ReporteLibrosInicial.txt");
    biblioteca.leerUsuarios("Usuarios.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosInicial.txt");
    biblioteca.leerPrestamos("RegistroDePrestamos.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosFinal.txt");
    biblioteca.imprimeLibros("ReporteLibrosFinal.txt");
    biblioteca.imprimirSuspendidos("ReporteSuspendidos.txt",19,10,2021);
    return 0;
}

