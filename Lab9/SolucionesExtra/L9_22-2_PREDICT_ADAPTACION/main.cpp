/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:01 PM
 */

#include <iostream>
#include <iomanip>
#include "farmacia.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    farmacia ofarm;
    ofarm.leerecetas();
    ofarm.imprimirrecetas();
    return 0;
}

