/* 
 * File:   FuncionesLecturaEscritura.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 10:40 PM
 */

#ifndef FUNCIONESLECTURAESCRITURA_H
#define FUNCIONESLECTURAESCRITURA_H
#include <fstream>
#include "Alumno.h"
#include "Miembro.h"
#include "Profesor.h"
using namespace std;

void AbrirArchivo(const char *nomb, ifstream &arch);
void AbrirArchivo(const char *nomb, ofstream &arch);
ifstream & operator >> (ifstream &arch,Alumno &alu);
ifstream &operator >> (ifstream &arch,Profesor &prof);
ifstream &operator >>(ifstream &arch,Miembro &miembro);
ofstream &operator << (ofstream &arch,const Alumno &alum);
ofstream &operator << (ofstream &arch,const Profesor &prof);

#endif /* FUNCIONESLECTURAESCRITURA_H */

