/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20296202
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesAuxiliares.hpp"

int main(int argc, char** argv) {
    // Especialidades
    char especialidad1[50], especialidad2[50], c;
    int ddV, mmV, aaaaV, fechaVencimiento;
    int cntEspecilidad1 = 0, cntEspecilidad2 = 0;
    int cntEsp1Pacientes = 0, cntEsp2Pacientes = 0;
    int cntMedVecEspecilidad1 = 0, cntMedVecEspecilidad2 = 0;
    // doctor
    char codigoDoctor[10], nombreDoctor[100], especialidadDoctor[50], especialidadMayusculaDoc[50];
    // paciente y medicamentos
    char nombrePaciente[100], nombreMedicamento[50];
    int dniPaciente, cntMedicamentos, codMedicamento, ddM, mmM, aaaaM, fechaMedicamento, cntPacientes = 0;
    int cntMedicamentosVencidos = 0;

    std::cin >> especialidad1 >> especialidad2 >> ddV >> c >> mmV >> c >> aaaaV;
    fechaVencimiento = fecha(ddV, mmV, aaaaV);
    imprirCabeceraReporte(especialidad1, especialidad2, ddV, mmV, aaaaV);

    while (true) {
        std::cin >> dniPaciente;
        if (std::cin.eof()) break;
        if (std::cin.fail()) {
            imprimeLinea('=');
            std::cin.clear();
            std::cin >> codigoDoctor >> nombreDoctor;
            especialidadDelDoctor(nombreDoctor, especialidadDoctor, especialidadMayusculaDoc);
            imprimeDoctor(codigoDoctor, nombreDoctor, especialidadDoctor);
            if (compararEspecialidades(especialidad1, especialidadMayusculaDoc)) {
                cntEspecilidad1++;
                cntEsp1Pacientes += cntPacientes;
            } else if (compararEspecialidades(especialidad2, especialidadMayusculaDoc)) {
                cntEspecilidad2++;
                cntEsp2Pacientes += cntPacientes;
            }
            cntPacientes = 1;
        } else {
            imprimeLinea('-');
            std::cin >> nombrePaciente >> cntMedicamentos;
            imprimirPaciente(cntPacientes, dniPaciente, nombrePaciente);
            cntMedicamentosVencidos = 0;
            for (int i = 0; i < cntMedicamentos; i++) {
                std::cin >> codMedicamento >> nombreMedicamento >> ddM >> c >> mmM >> c >> aaaaM;
                fechaMedicamento = fecha(ddM, mmM, aaaaM);
                imprimeMedicamento(i, cntMedicamentos, codMedicamento, nombreMedicamento, ddM, mmM, aaaaM);
                if (fechaMedicamento >= fechaVencimiento) {
                    std::cout << std::setw(11) << std::right << "VENCIDA\n";
                    cntMedicamentosVencidos++;
                } else {
                    std::cout << "\n";
                }
            }
            if (compararEspecialidades(especialidad1, especialidadMayusculaDoc)) {
                cntMedVecEspecilidad1+= cntMedicamentosVencidos;
            } else if (compararEspecialidades(especialidad2, especialidadMayusculaDoc)) {
                cntMedVecEspecilidad2+= cntMedicamentosVencidos;
            }
            std::cout << std::setw(100) << std::right << "Cantidad de medicamentos vencidos: " << cntMedicamentosVencidos << '\n';
            cntPacientes++;
        }
    }
    
    imprimeLinea('=');
    std::cout << "RESUMEN\n";
    ResumenEspecilidades(especialidad1,cntEspecilidad1,cntEsp1Pacientes,cntMedVecEspecilidad1);
    ResumenEspecilidades(especialidad2,cntEspecilidad2,cntEsp2Pacientes,cntMedVecEspecilidad2);
    imprimeLinea('=');
    
    


    return 0;
}

