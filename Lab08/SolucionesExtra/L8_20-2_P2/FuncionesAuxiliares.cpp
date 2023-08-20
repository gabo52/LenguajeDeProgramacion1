/* 
 * File:   FuncionesAuxiliares.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 12:03 AM
 */

#include <iostream>
#include <iomanip>

#include "Miembro.h"
#include "FuncionesLecturaEscritura.h"
using namespace std;

void leemiembro(Miembro &miembros){
    ifstream arch;
    AbrirArchivo("Miembros.csv",arch);
    while(1){
        arch>>miembros;
        if(arch.eof())break;
    }
}
void imprimeReportes(Miembro miembros){
    ofstream arch1,arch2;
    AbrirArchivo("ReporteAlumnos.txt",arch1);
    AbrirArchivo("ReporteProfesores.txt",arch2);
    miembros.imprimeAlumnos(arch1);
    miembros.imprimeProfesores(arch2);
}