
/* 
 * File:   FunConEnteros.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 05:29 PM
 */

#ifndef FUNCONENTEROS_H
#define FUNCONENTEROS_H
#include <fstream>
using namespace std;

int prioridadnumero(void *dato); 
void *leenumero(ifstream &arch);
void imprimirnum(void *cola, const char *nomarch); 

#endif /* FUNCONENTEROS_H */

