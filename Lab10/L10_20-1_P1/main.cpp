/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
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

