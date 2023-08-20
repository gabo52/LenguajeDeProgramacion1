/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 15 de noviembre de 2022, 11:30 AM
 */

#include <iostream>
#include <iomanip>
#include "ListaDePacientes.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ListaDePacientes l;
    l.CreaLista("AtencionDeCitas.csv");
    l.imprimeLista("Reporte.txt");
    return 0;
}

