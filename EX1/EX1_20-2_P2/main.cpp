/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
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

