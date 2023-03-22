/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 08:39 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Procesa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    pro.lee();
    pro.imprime();
    return 0;
}

