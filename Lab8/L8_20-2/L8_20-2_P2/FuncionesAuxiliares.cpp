/* 
 * File:   FuncionesAuxiliares.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 12:17 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#include "ListaDePacientes.h"
#include "FuncionesLecturaEscritura.h"
using namespace std;

void leerListaDePacientes(ListaDePacientes &lista){
    ifstream arch;
    AbrirArchivo("AtencionDeCitas.csv",arch);
    while(1){
        arch>>lista;
        if(arch.eof())break;
    }
}
void imprimirListaDePacientes(ListaDePacientes lista){
    ofstream arch;
    AbrirArchivo("ReporteListaPacientes.txt",arch);
    arch<<lista;
}