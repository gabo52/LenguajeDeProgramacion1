/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de octubre de 2022, 07:42 PM
 */

#include <iostream>
#include <iomanip>
#include "PunterosGenericos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *stock;
    cargalibros(stock);
    actualiza(stock);
    imprimestock(stock);
    return 0;
}

