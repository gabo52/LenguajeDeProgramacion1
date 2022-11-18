/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 16 de noviembre de 2022, 09:43 AM
 */

#include <iostream>
#include <iomanip>
#include "Procesa.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    pro.carga();
    pro.actualiza();
    pro.muestra();
    return 0;
}

