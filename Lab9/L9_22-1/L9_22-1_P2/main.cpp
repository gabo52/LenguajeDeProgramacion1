/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:43 AM
 */

#include <iostream>
#include <iomanip>
#include "Procesa.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    pro.carga();
    pro.actualiza();
    pro.muestra();
    return 0;
}

