/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 27 de octubre de 2022, 04:44 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncNumeros.h"
#include "PilaGenerica.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *pila;
    creaPila(pila,leenum,"numeros.txt");
    imprimePila(pila,imprimenum,"PilaSinOrdenar.txt");
    ordenaPila(pila,cmpnum);
    imprimePila(pila,imprimenum,"PilaOrdenada.txt");
    return 0;
}

