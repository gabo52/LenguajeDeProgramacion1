/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 27 de octubre de 2022, 06:46 PM
 */

#include <iostream>
#include <iomanip>
#include "BibliotecaColaGenerica.h"
#include "FuncNumeros.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *cola;
    creaCola(cola,leenum,"numeros.txt");
    imprimir(cola,imprimenum,"ColaSinOrdenar.txt");
    ordenaCola(cola,cmpnum);
    imprimir(cola,imprimenum,"ColaOrdenada.txt");
    return 0;
}

