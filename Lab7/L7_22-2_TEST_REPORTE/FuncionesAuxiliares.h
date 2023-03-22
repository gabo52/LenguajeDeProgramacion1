/* 
 * File:   FuncionesAuxiliares.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:53 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
#include "Medico.h"
#include "Paciente.h"
#include "Cita.h"
using namespace std;
void cargaMedicos(Medico *arr);
void cargaPacientes(Paciente *arr);
void cargaCitas(Paciente *arrPac,Medico *arrMed);
int  buscarPaciente(Paciente *arr,int dni);
void imprimeReporte(Paciente *arr);
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* FUNCIONESAUXILIARES_H */

