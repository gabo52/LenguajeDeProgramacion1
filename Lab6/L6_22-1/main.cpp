/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de octubre de 2022, 11:19 PM
 */

#include <iostream>
#include <iomanip>
#include "BibGenerica.h"
#include "FunNumeros.h"
#include "FunPedidos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *arbol;
    creaarbol(arbol,leenumero,cmpnumero,"numeros.txt");
    muestraarbol(arbol,imprimenumero,"reporte.txt");
    
    creaarbol(arbol,leepedido,cmppedido,"Pedidos2.csv");
    muestraarbol(arbol,imprimepedido,"reporteped.txt");
    return 0;
}

