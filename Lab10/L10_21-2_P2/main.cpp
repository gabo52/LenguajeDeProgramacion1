/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
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

