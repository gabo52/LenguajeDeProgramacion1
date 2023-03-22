/* 
 * File:   FuncionesLecturaEscritura.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 6 de noviembre de 2022, 10:40 PM
 */

#ifndef FUNCIONESLECTURAESCRITURA_H
#define FUNCIONESLECTURAESCRITURA_H
#include <fstream>
using namespace std;

void AbrirArchivo(const char *nomb, ifstream &arch);
void AbrirArchivo(const char *nomb, ofstream &arch);

#endif /* FUNCIONESLECTURAESCRITURA_H */

