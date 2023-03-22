/* 
 * File:   FuncionesLecturaEscritura.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 09:52 PM
 */

#ifndef FUNCIONESLECTURAESCRITURA_H
#define FUNCIONESLECTURAESCRITURA_H
#include <fstream>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
using namespace std;

void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void separaNombreEsp(char *nomb,char *esp);
ifstream & operator >> (ifstream &arch, Medico &med);
ifstream & operator >> (ifstream &arch, Paciente &pac);
int operator >> (ifstream &arch, Cita &cita);
ofstream& operator << (ofstream &arch, Paciente &pac);
#endif /* FUNCIONESLECTURAESCRITURA_H */

