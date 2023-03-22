/* 
 * File:   FuncionesLecturaEscrituraa.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 07:02 PM
 */

#ifndef FUNCIONESLECTURAESCRITURAA_H
#define FUNCIONESLECTURAESCRITURAA_H
#include <fstream>
using namespace std;

void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* FUNCIONESLECTURAESCRITURAA_H */

