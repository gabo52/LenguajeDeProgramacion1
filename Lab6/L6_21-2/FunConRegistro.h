
/* 
 * File:   FunConRegistro.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 05:46 PM
 */

#ifndef FUNCONREGISTRO_H
#define FUNCONREGISTRO_H
#include <fstream>
using namespace std;

void *leepedido(ifstream &arch);
char *leerCadena(ifstream &arch,char c);
int prioridadpedido(void *dato);
void imprimirped(void *cola, const char *nomarch);

#endif /* FUNCONREGISTRO_H */

