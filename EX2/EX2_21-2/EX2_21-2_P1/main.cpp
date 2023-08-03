/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:31 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Procesa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    
    pro.Carga();
    pro.Atiende();
    pro.Imprime();
    return 0;
}

