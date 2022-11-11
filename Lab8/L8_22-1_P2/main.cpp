/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 9 de noviembre de 2022, 05:22 PM
 */

#include <iostream>
#include <iomanip>
#include "Tienda.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tienda tien;
    tien.carga();
    tien.actualiza(20);
    tien.muestra();
    return 0;
}

