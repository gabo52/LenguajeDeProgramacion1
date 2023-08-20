/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 14 de junio de 2023, 09:12 AM
 */

#include <cstdlib>

#include "farmacia.h"

using namespace std;

int main(int argc, char** argv) {
    farmacia Pedidos;
    
    Pedidos.leerecetas();
    Pedidos.descuenta();
    Pedidos.imprimerecetas();
    
    return 0;
}

