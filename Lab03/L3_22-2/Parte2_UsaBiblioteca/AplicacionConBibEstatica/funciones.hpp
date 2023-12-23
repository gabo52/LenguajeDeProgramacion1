/* 
 * File:   funciones.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
//librerias
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "operadoresSobrecargados.hpp"
using namespace std;
//funciones
void leerMedicos(struct StMedico *arregloMedico);
void leerPacientes(struct StPaciente *paciente);
void leerCitas(struct StMedico *medico,struct StPaciente *paciente);
void gastosPaciente(struct StPaciente *paciente);
void reporte(struct StPaciente *paciente);


#endif /* FUNCIONES_HPP */

