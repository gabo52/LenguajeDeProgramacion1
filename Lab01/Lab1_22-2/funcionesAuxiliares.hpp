/* 
 * File:   funcionesAuxiliares.hpp
 * Author: Jesus Huayhua
 */

#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP
int fecha(int dia, int mes, int anho);
void especialidadDelDoctor(char *nombreDoctor, char *especialidadDoctor, char *especialidadMayusculaDoc);
void imprirCabeceraReporte(char *especialidad1, char *especialidad2, int dia, int mes, int anho);
void imprimeDoctor(char *codigoDoctor, char *nombreDoctor, char *especialidadDoctor);
void imprimirPaciente(int cntPaciente, int dniPaciente, char *nombrePaciente);
void imprimeMedicamento(int i, int cnt, int codigo, char *nombre, int dia, int mes, int anho);
void imprimeLinea(char c);
bool compararEspecialidades(char *especialidad, char *especialidadDoc);
void ResumenEspecilidades(char *especialidad,int cntEspecilidad,int cntPacientes,int cntMedicamentoVencido);
#endif /* FUNCIONESAUXILIARES_HPP */

