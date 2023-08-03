/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:06 PM
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cola cola;
    cola.lee("Miembros.csv");
    cola.imprime("Reporte.txt");
    return 0;
}

