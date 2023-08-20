/* 
 * File:   FuncionesLecturaEscritura.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 10:40 PM
 */

#ifndef FUNCIONESLECTURAESCRITURA_H
#define FUNCIONESLECTURAESCRITURA_H
#include <fstream>
#include "Miembro.h"
using namespace std;

void AbrirArchivo(const char *nomb, ifstream &arch);
void AbrirArchivo(const char *nomb, ofstream &arch);
void operator >> (ifstream &arch, Alumno &alu);
void operator >> (ifstream &arch, Profesor &prof);
void operator >> (ifstream &arch, Miembro &miemb);
#endif /* FUNCIONESLECTURAESCRITURA_H */

