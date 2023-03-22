/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
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
    lf2.leer("RegistroDeFaltas2.csv");
    lf1.unir(lf2);
    lf1.imprimir("Reporte.txt");
    return 0;
}

