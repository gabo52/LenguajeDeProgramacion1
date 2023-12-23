/* 
 * File:   operadoresSobrecargados.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de diciembre de 2023, 11:08 AM
 */

#ifndef OPERADORESSOBRECARGADOS_HPP
#define OPERADORESSOBRECARGADOS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
using namespace std;
/*****************************************************************************
 * LECTURA
 ******************************************************************************/
bool operator>>(ifstream &archMedico, struct StMedico &medico);
bool operator>>(ifstream &archPaciente, struct StPaciente &paciente);
int operator>>(ifstream &archCita, struct StCita &cita);
/*****************************************************************************
 * BUSQUEDA
 ******************************************************************************/
bool operator<=(struct StCita &cita, struct StMedico *arregloMedico);
/*****************************************************************************
 * AGREGACION
 ******************************************************************************/
void operator+=(struct StPaciente &paciente, const struct StCita cita);
/*****************************************************************************
 * GASTOS
 ******************************************************************************/
void operator++(struct StPaciente &paciente);
/*****************************************************************************
 * IMPRESION
 ******************************************************************************/
void operator<<(ofstream &output, const struct StPaciente paciente);
void obtenerFecha(int *fecha, int fechaCompuesta);
#endif /* OPERADORESSOBRECARGADOS_HPP */

