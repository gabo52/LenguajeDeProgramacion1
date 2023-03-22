/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 10 de octubre de 2022, 07:42 PM
 */

#include <iostream>
#include <iomanip>
#include "PunterosGenericos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *stock;
    cargalibros(stock);
    actualiza(stock);
    imprimestock(stock);
    return 0;
}

