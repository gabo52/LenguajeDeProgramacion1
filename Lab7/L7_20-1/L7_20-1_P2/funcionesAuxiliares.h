/* 
 * File:   funcionesAuxiliares.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 1 de noviembre de 2022, 09:28 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include "Acurso.h"
#include "Alumno.h"
#include "Curso.h"
#include <fstream>
using namespace std;

void AbrirArchivo(const char *nomb, ifstream &arch);
void AbrirArchivo(const char *nomb, ofstream &arch);
ifstream& operator>>(ifstream& arch, Acurso &acur);
ofstream & operator<<(ofstream & arch, Alumno &alum);
ifstream& operator>>(ifstream& arch,Alumno &alum);
int busca(int dato,int *arr);
void imprimeLinea(ofstream & arch,int cant,char c);
#endif /* FUNCIONESAUXILIARES_H */

