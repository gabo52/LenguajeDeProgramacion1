/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 05:55 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Almacen.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Almacen alma;
    alma.carga();
    alma.actualiza();
    alma.imprime();
    return 0;
}

