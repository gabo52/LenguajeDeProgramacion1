/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de noviembre de 2022, 04:50 PM
 */

#include <iostream>
#include <iomanip>
#include "Promociones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Promociones pro;
    pro.leepedidos();
    pro.actualizapedidos();
    pro.imprimepedidos();
    return 0;
}

