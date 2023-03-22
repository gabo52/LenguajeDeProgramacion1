/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 02:52 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Programa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Programa prog;
    prog.carga();
    prog.actualiza();
    prog.muestra();
    return 0;
}

