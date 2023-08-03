/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 11 de abril de 2023, 08:18 AM
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"

using namespace std;

int main(int argc, char** argv) {
    generaclientebin();
    generaproductosbin();
    generapedidosbin(); 
    imprimeReporteClientes(); 
    imprimeReporteProductos();
    imprimeReportePedidos();
    imprimeReporteFinal();
    imprimeReporteClientes(); 
    return 0;
}

