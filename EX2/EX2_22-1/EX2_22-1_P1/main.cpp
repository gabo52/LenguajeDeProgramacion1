/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 02:53 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Empresa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Empresa empresa;
    empresa.leerClientes("clientes.csv");
    empresa.imprimirClientes("PruebaClientes.txt");
    empresa.leerPedidos("Pedidos.csv");
    empresa.ordenarPedidos();
    empresa.imprimirProductos("ReporteDeProductos.txt");
    empresa.imprimirClientes("ReporteDeClientes.txt");
    return 0;
}

