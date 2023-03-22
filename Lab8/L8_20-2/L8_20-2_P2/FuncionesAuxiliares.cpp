/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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