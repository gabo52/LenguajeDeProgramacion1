/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 09:31 PM
 */

#include <iostream>
#include <iomanip>
#include "Biblioteca.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca bib;
    
    bib.LeeLibros();
    bib.ActualizaLibros();
    bib.ImprimeLibros();
    return 0;
}

