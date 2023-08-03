/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 9 de mayo de 2023, 08:23 PM
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char ***medicoDatos, ****citaPaciente;
    int **citaCantidad;
    double *medicoTarifaHora, ***citaTiempoYPago;
    
    cargarCitas("Citas.csv",medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,citaTiempoYPago);
    ReporteDeCitasPorMedico("ReporteDeCitasPorMedico.txt",medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,citaTiempoYPago);
    return 0;
}

