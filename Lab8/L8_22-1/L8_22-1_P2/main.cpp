/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de noviembre de 2022, 05:22 PM
 */

#include <iostream>
#include <iomanip>
#include "Tienda.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tienda tien;
    tien.carga();
    tien.actualiza(20);
    tien.muestra();
    return 0;
}

