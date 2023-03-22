/* 
 * File:   ColaEnteros.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de octubre de 2022, 05:18 PM
 */

#ifndef COLAENTEROS_H
#define COLAENTEROS_H
#include <fstream>
using namespace std;


void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void imprimeRegEnteros(void *dt,ofstream &arch);
int obtienePrioridadEnteros(void *dt);
void *leeRegistroEnteros(ifstream &arch);



#endif /* COLAENTEROS_H */

