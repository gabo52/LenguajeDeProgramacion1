#include <iostream>
#include <iomanip>
#include <cstring>
#include "funcionesAuxiliares.hpp"

/**
 * Convierte la fecha a una unidad standar, para facilitar las compraciones
 * @param dia
 * @param mes
 * @param anho
 * @return -> int
 */
int fecha(int dia, int mes, int anho) {
    return anho * 10000 + mes * 100 + dia;
}

/**
 * Separamos la especialidad del doctor de su nombre
 * @param nombreDoctor
 * @param especialidadDoctor
 */
void especialidadDelDoctor(char *nombreDoctor, char *especialidadDoctor,char *especialidadMayusculaDoc) {
    int i = 0, j = 0, aux;
    while (nombreDoctor[i++] != '\0');
    while (nombreDoctor[i--] != '_');
    aux = i;
    i += 2;
    while (nombreDoctor[i] != '\0') {
        especialidadDoctor[j] = nombreDoctor[i];
        if(nombreDoctor[i] >= 'a' and nombreDoctor[i] <= 'z'){
            especialidadMayusculaDoc[j] = nombreDoctor[i] - 'a' + 'A';
        }else{
            especialidadMayusculaDoc[j] = nombreDoctor[i];
        }
        i++;
        j++;
    }
    nombreDoctor[aux] = '\0';
    especialidadDoctor[j] = '\0';
    especialidadMayusculaDoc[j] = '\0';
}

/**
 * Impresion de la cebecera del reporte
 * @param especialidad1
 * @param especialidad2
 * @param dia
 * @param mes
 * @param anho
 */
void imprirCabeceraReporte(char *especialidad1, char *especialidad2, int dia, int mes, int anho) {
    std::cout << std::right << std::setw(75) << "EMPRESA PRESTADORA DE SALUD\n";
    std::cout << std::left;
    imprimeLinea('=');
    std::cout << "ESPECIALIDADES A VERIFICAR: " << especialidad1 << " y " << especialidad2 << '\n'
            << "FECHA DEL PROCESO: " << dia << '/' << mes << '/' << anho << std::endl;
}

void imprimeDoctor(char *codigoDoctor, char *nombreDoctor, char *especialidadDoctor) {
    std::cout << "Medico: " << nombreDoctor << " [" << codigoDoctor << "] ";
    std::cout << std::setw(30) << std::setfill(' ') << std::right << ' ' << " Especialidad: " << especialidadDoctor << "\n";
    imprimeLinea('-');
    std::cout << std::setw(29) << std::setfill(' ') << std::right << "Pacientes Atendidos";
    std::cout << std::setw(49) << std::setfill(' ') << std::right << "Medicinas Recibidas\n";
    imprimeLinea('-');
    std::cout << std::setw(6) << std::right << "DNI"
            << std::setw(14) << std::right << "Nombre"
            << std::setw(38) << std::right << "Cantidad"
            << std::setw(13) << std::right << "Codigo"
            << std::setw(19) << std::right << "Descripcion"
            << std::setw(46) << std::right << "F. de V"
            << std::setw(15) << std::right << "Obervacion\n";
}

void imprimirPaciente(int cntPaciente, int dniPaciente, char *nombrePaciente) {
    std::cout << std::setw(2) << std::setfill('0') << std::right << cntPaciente << ")";
    std::cout << std::setfill(' ');
    std::cout << ' ' << dniPaciente << ' ';
    std::cout << std::setw(40) << std::left << nombrePaciente;
}

void imprimeMedicamento(int i, int cnt, int codigo, char *nombre, int dia, int mes, int anho) {
    if (i == 0) {
        std::cout << cnt;
        std::cout << std::setw(16) << std::right << codigo;
        std::cout << std::setw(9) << ' ';
        std::cout << std::setw(39) << std::left << nombre;
        std::cout << std::setw(10) << ' ';
        std::cout << std::setw(2) << std::setfill('0') << std::right << dia << '/'
                << std::setw(2) << std::setfill('0') << std::right << mes << '/';
        std::cout << std::setfill(' ') << anho;
    } else {
        std::cout << std::setw(54) << std::setfill(' ') << ' ';
        std::cout << std::setw(16) << std::right << codigo;
        std::cout << std::setw(9) << ' ';
        std::cout << std::setw(39) << std::left << nombre;
        std::cout << std::setw(10) << ' ';
        std::cout << std::setw(2) << std::setfill('0') << std::right << dia << '/'
                << std::setw(2) << std::setfill('0') << std::right << mes << '/';
        std::cout << std::setfill(' ') << anho;
    }
}

/**
 * Linea divisora para mayor orden en el inform
 * @param c: caracter que se va a imprimir como linea divisoria
 */
void imprimeLinea(char c) {
    std::cout << std::setfill(c) << std::setw(150) << c << std::endl;
    std::cout << std::setfill(' ');
}

bool compararEspecialidades(char *especialidad,char *especialidadDoc){
    return strcmp(especialidad,especialidadDoc) == 0;
}

void ResumenEspecilidades(char *especialidad,int cntEspecilidad,int cntPacientes,int cntMedicamentoVencido){
    std::cout << "Especialidad " << std::setw(15) << std::setfill(' ') << std::left << especialidad << ':';
    std::cout << std::setw(2) << std::setfill('0') << std::right << cntEspecilidad << " medicos,";
    std::cout << cntPacientes << " pacientes,";
    std::cout << cntMedicamentoVencido << " medicinas vencidas.\n";
}


