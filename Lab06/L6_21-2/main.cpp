/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 04:34 PM
 */

#include <iostream>
#include <iomanip>
#include "BibGenerica.h"
#include "FunConEnteros.h"
#include "FunConRegistro.h"
using namespace std;

int main(int argc, char** argv) {
    void *cola;
    
    //crearcola(cola,leenumero,prioridadnumero,"numeros.txt");
    //imprimirnum(cola,"Reporte.txt"); 
    
    crearcola(cola,leepedido,prioridadpedido,"Pedidos.csv");
    imprimirped(cola,"Reppedidos.txt"); 
    return 0;
}

