/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
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
    ofarm.cargamedico();
    ofarm.leerecetas();
    ofarm.imprimirrecetas();
    return 0;
}

