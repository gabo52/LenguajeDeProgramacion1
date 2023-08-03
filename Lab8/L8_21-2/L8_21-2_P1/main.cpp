/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:17 PM
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
    bib.generaCopias();
    bib.actualizaLibros();
    bib.imprimeCopias();
    return 0;
}

