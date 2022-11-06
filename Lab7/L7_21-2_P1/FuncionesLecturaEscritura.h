/* 
 * File:   FuncionesLecturaEscritura.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 12:03 AM
 */

#ifndef FUNCIONESLECTURAESCRITURA_H
#define FUNCIONESLECTURAESCRITURA_H
#include"Libro.h"
#include "LibroPrestado.h"
#include "Usuario.h"
#include <fstream>
#include <cstring>
using namespace std;


void AbrirArchivo(const char *nomb, ifstream &arch);
void AbrirArchivo(const char *nomb, ofstream &arch);
ifstream & operator >>(ifstream &arch,Libro &lib);
ifstream & operator >>(ifstream &arch,Usuario &usu);
ifstream & operator >>(ifstream &arch,LibroPrestado &lpres);
ofstream & operator <<(ofstream &arch, Usuario &usu);
ofstream & operator <<(ofstream &arch,const LibroPrestado &lib);
ofstream & operator <<(ofstream &arch,const Libro &lib);
#endif /* FUNCIONESLECTURAESCRITURA_H */

