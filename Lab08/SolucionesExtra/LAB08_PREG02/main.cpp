/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Tienda.h"

int main(int argc, char** argv) {
    Tienda tien;
    
    tien.carga();
    tien.actualiza(20);
    tien.muestra();
    
    return 0;
}

