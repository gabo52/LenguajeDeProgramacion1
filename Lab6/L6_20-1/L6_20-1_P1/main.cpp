/* 
 * File:   main.cpp
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 04:33 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "BibliotecaColaGenerica.h"
#include "FuncionesLaboratorio01.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *cola;
    creaCola(cola,leenumero);
    imprimir(cola,imprimenumero);
    atiendeNumero(cola);
    return 0;
}

