/* 
 * File:   FuncionesLecturaEscritura.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 11:39 AM
 */

#ifndef FUNCIONESLECTURAESCRITURA_H
#define FUNCIONESLECTURAESCRITURA_H
#include <iostream>
#include <iomanip>
#include "ListaDePacientes.h"
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
ifstream & operator >> (ifstream &arch, ListaDePacientes &lista);
ifstream &operator >>(ifstream &arch, Ambulatorio &amb);
ifstream &operator >>(ifstream &arch, Emergencia &amb);
ifstream &operator >>(ifstream &arch, Urgencia &amb);
ofstream &operator <<(ofstream &arch, ListaDePacientes &c);
ofstream &operator <<(ofstream &arch,const Ambulatorio &amb);
ofstream &operator <<(ofstream &arch,const Emergencia &emer);
ofstream &operator <<(ofstream &arch,const Urgencia &urg);
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* FUNCIONESLECTURAESCRITURA_H */

