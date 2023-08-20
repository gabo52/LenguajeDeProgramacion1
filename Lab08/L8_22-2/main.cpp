/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 11 de junio de 2023, 10:36 AM
 */

#include <cstdlib>

#include "farmacia.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    farmacia ofarma;
    
    ofarma.cargamedicos();
    ofarma.leerecetas();
    ofarma.imprimirrecetas();
    return 0;
}

