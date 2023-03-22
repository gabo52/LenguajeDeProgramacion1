/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 22 de noviembre de 2022, 04:50 PM
 */

#include <iostream>
#include <iomanip>
#include "Promociones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Promociones pro;
    pro.leepedidos();
    pro.actualizapedidos();
    pro.imprimepedidos();
    return 0;
}

