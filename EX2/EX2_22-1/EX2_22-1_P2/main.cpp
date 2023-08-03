/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 02:52 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Programa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Programa prog;
    prog.carga();
    prog.actualiza();
    prog.muestra();
    return 0;
}

