/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:30 PM
 */

#include <iostream>
#include <iomanip>
#include "LFalta.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    LFalta lf1,lf2;
    
    lf1.leer("RegistroDeFaltas1.csv");
    lf2.leer("RegistroDeFaltas1.csv");
    lf1.unir(lf2);
    lf1.imprimir("Reporte.txt");
    return 0;
}

