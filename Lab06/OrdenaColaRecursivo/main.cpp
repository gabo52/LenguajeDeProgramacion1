/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

