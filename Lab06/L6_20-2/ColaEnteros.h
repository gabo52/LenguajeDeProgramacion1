
/* 
 * File:   ColaEnteros.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 25 de mayo de 2023, 08:48 PM
 */

#ifndef COLAENTEROS_H
#define COLAENTEROS_H
#include <fstream>
using namespace std;

void *leeRegistroEnteros(ifstream &arch); 
int hallarprioridad(void *dato);
void imprimeRegEnteros(void *dt,ofstream &arch);

#endif /* COLAENTEROS_H */

