/* 
 * File:   FuncionesLecturaEscritura.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:59 AM
 */

#ifndef FUNCIONESLECTURAESCRITURA_H
#define FUNCIONESLECTURAESCRITURA_H

#include "Cliente.h"
#include "Pedido.h"
#include <fstream>
using namespace std;

void AbrirArchivo(const char *nomb,ofstream &arch);
void AbrirArchivo(const char *nomb,ifstream &arch);
ifstream & operator >> (ifstream &arch, Cliente &clien);
ifstream & operator >> (ifstream &arch, Pedido &ped);
void imprimeLinea(ofstream &arch,int cant,char c);
ofstream & operator << (ofstream &arch,Cliente &clien);
#endif /* FUNCIONESLECTURAESCRITURA_H */

