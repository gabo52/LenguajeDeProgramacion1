/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 10 de octubre de 2022, 04:53 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "BibliotecaCargaLibros_Y_Usuarios.h"
#include "BibliotecaControlDePrestamos.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char **codLibro,*tipoUs,**nombreUs,***codLibPrest;
    int *cantLibros,*carneUs,**fechPrest;
    cargarLibros(codLibro,cantLibros);
    mostrarLibros(codLibro,cantLibros,"ReporteLibros1.txt");
    cargarUsuarios(carneUs,tipoUs,nombreUs);
    mostrarUsuarios(carneUs,tipoUs,nombreUs);
    
    cargarPrestamos(fechPrest,codLibPrest,carneUs);
    mostrarLibrosPrestados(fechPrest,codLibPrest,carneUs,tipoUs,"ReporteDePrestamos1.txt");
    procesarSolicitudes(carneUs,tipoUs,nombreUs,fechPrest,codLibPrest,codLibro,cantLibros);
    mostrarLibrosPrestados(fechPrest,codLibPrest,carneUs,tipoUs,"ReporteDePrestamos2.txt");    mostrarLibros(codLibro,cantLibros,"ReporteLibros2.txt");
    return 0;
}

