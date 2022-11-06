/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 7 de octubre de 2022, 10:59 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesEx01_20202_Preg01.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *pedidos,*stock;
    leerDatos(pedidos,stock);
    atiende(pedidos,stock);
    imprimirDatos(pedidos,stock);
    return 0;
}

