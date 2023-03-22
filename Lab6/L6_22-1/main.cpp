/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
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

