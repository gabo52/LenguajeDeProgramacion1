/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196401
 */

#include <iostream>
#include <iomanip>
#include "operadoresSobrecargados.hpp"
using namespace std;

int main(int argc, char** argv) {
    ifstream archMedico, archPaciente, archCitas;
    ofstream archReporte;
    struct StMedico arregloMedico[100];
    struct StPaciente arregloPaciente[100];
    struct StCita cita;
    AperturaDeUnArchivoDeTextosParaLeer(archMedico, "MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPaciente, "PacientesLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archCitas, "ConsultasLab3.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "Reporte.txt");
    
    for (int i = 0; i < 40; i++) {
        archMedico >> arregloMedico[i];
        archPaciente >> arregloPaciente[i];
    }
    
    for (int i = 0; i < 40; i++) {
        arregloPaciente[i].citas[0] = StCita();
    }
    
    while(true){
        int dni = (archCitas >> cita);
        if (dni == -1) break; // se terminaron de leer las consultas
        if (!(cita <= arregloMedico)) continue;
        int j;
        for (j = 0; arregloPaciente[j].dni != dni and j < 40; j++); // buscamos al paciente
        if (j == 40) continue; // no se encontro al paciente con el dni
        arregloPaciente[j] += cita; // como si se encontro, vamos a guardar su cita
    }
    
    for (int i = 0; i < 40; i++) {
        ++(arregloPaciente[i]); //calculamos el costo de sus consultas
        archReporte << arregloPaciente[i]; //imprimos el reporte
    }
    return 0;
}

