/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 25 de mayo de 2023, 05:17 PM
 */

#include <iostream>
#include <iomanip>
#include "PriorityQueu.h"
#include "ColaRegistro.h"
#include "ColaEnteros.h"
using namespace std;

int main(int argc, char** argv) {
    void *cola1, *cola2;
    
    ifstream archPacientes("Pacientes.csv",ios::in);
    ifstream arch("Datos.txt",ios::in);
    ofstream archReporte("Reporte.txt",ios::out);
    ofstream archReporteFinal("ReporteFinal.txt",ios::out);
    
    crearCola(cola1,arch,hallarprioridad,leeRegistroEnteros);
    crearCola(cola2,archPacientes,hallarprioridadreg,leeRegistro);
    prueba(cola2,imprimeReg,archReporteFinal); 
    prueba(cola1,imprimeRegEnteros,archReporte);
    return 0;
}