/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 30 de mayo de 2023, 08:17 AM
 */

#include <iostream>
#include <iomanip>
#include "PilaConEnteros.h"
#include "BibliotecaPilaGenerica.h"
using namespace std;

int main(int argc, char** argv) {
    void *arreglo, *pilaini, *pilafin; 
    
    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt"); 
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin); 
    
    return 0;
}

