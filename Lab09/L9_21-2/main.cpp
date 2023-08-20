/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 21 de junio de 2023, 06:41 PM
 */

#include <iostream>
#include <iomanip>
#include "Biblioteca.h"
using namespace std;

int main(int argc, char** argv) {
    Biblioteca bib; 
    
    bib.GeneraCopias();
    bib.ActualizaLibros();
    bib.ImprimeCopias();
    return 0;
}

