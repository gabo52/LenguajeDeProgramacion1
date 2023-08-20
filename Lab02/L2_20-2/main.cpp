/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 18 de abril de 2023, 10:30 AM
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"

using namespace std;

int main(int argc, char** argv) {
    leerprimerarchivo(); 
    leersegundoarchivo();
    completarcampos();
    completarcamposfaltantes(); 
    imprimirreportefinal();
    return 0;
}

