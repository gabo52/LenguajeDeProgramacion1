#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.hpp"


void leerMedicos(struct StMedico *arregloMedico){
    ifstream archMedicos;
    AperturaDeUnArchivoDeTextosParaLeer(archMedicos,"MedicosLab3.txt");
    for (int i = 0; archMedicos >> arregloMedico[i]; i++);
}

void leerPacientes(struct StPaciente *paciente){
    ifstream archPaciente;
    AperturaDeUnArchivoDeTextosParaLeer(archPaciente,"PacientesLab3.txt");
    for (int i = 0; archPaciente >> paciente[i]; i++);
}

void leerCitas(struct StMedico *medico,struct StPaciente *paciente){
    struct StCita cita;
    ifstream archCita;
    AperturaDeUnArchivoDeTextosParaLeer(archCita,"ConsultasLab3.txt");
    while (true) {
        int dni = (archCita >> cita);
        if (dni == -1) break;
        if(!(cita <= medico)) continue;
        int j;
        for(j = 0; paciente[j].dni != dni and j < 68; j++);// se conoce la cantidad de datos del archivo de texto que se nos brindo
        if(j == 68) continue;
        paciente[j] += cita;
    }
}

void gastosPaciente(struct StPaciente *paciente){
    for (int i = 0; i < 68; i++) {
        ++(paciente[i]);
    }
}

void reporte(struct StPaciente *paciente){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"reporte.txt");
    archReporte << setw(51) << "EMPRESA PRESTADORA DE SALUD LP1" << endl;
    archReporte << setw(51) << "PACIENTES QUE FUERON ATENDIDOS" << endl;
    for (int i = 0; i < 68; i++) {
        archReporte << setfill('=') << setw(70) << '=' << endl;
        archReporte << setfill(' ');
        archReporte << paciente[i];
    }
}

