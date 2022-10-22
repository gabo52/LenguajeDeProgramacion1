/* 
 * File:   main.cpp
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 06:24 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "ColaBanco-Clientes.h"
#include "BibliotecaColaGenerica.h"
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch;
    ofstream archRep;
    void *cola;
    AbrirArchivo(arch,"Banco-Clientes.csv");
    AbrirArchivo(archRep,"ReporteCola.txt");
    creaCola(cola,leenumero,arch);
    imprimir(cola,imprimenumero,archRep);
    atiendeCola(cola,10,00,00);
    return 0;
}

