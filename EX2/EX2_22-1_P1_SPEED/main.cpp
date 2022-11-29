/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabo
 *
 * Created on 28 de noviembre de 2022, 04:12 PM
 */

#include <iostream>
#include <iomanip>
#include "Empresa.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Empresa empresa;
    empresa.leerClientes("clientes.csv");
    empresa.imprimirClientes("PruebaDeClientes.txt");
    empresa.leerPedidos("Pedidos.csv");
    empresa.ordenarPedidos();
    empresa.imprimirProductos("ReporteDeProductos.txt");
    empresa.imprimirClientes("ReporteDeClientes.txt");
    return 0;
}

