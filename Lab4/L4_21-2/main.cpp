/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de septiembre de 2022, 08:15 AM
 */

#include <iomanip>
#include <iostream>
#include "PunterosAPunteros.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **codigo,**titulo,*tipo,**nombre;
    int *carne,*cantEnBibl;
    double *precio;
    estructuraParaLosLibros_CargaDeDatos(codigo,titulo,cantEnBibl,precio);
    estructuraParaLosLibros_Reporte(codigo,titulo,cantEnBibl,precio);
    usuarioDeLaBiblioteca_CargaDeDatos(carne,tipo,nombre);
    usuarioDeLaBiblioteca_Reporte(carne,tipo,nombre);
    libroYUsuariosInhabilitados_Reporte(codigo,titulo,cantEnBibl,precio,carne,
            tipo,nombre);
    return 0;
}

