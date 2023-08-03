/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de octubre de 2022, 01:20 AM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesEx01_20202_Preg02.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **clientes,***strProductos;
    int ***intProductos;
    leerDatos(clientes,intProductos,strProductos);
    imprimirDatos(clientes,intProductos,strProductos);
    return 0;
}

