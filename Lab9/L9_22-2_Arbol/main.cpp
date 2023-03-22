/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 06:48 PM
 */

#include <iostream>
#include <iomanip>
#include "Farmacia.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Farmacia farm;
    farm.leer();
    farm.imprimir();
    return 0;
}

