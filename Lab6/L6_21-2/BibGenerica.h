
/* 
 * File:   BibGenerica.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 04:35 PM
 */

#ifndef BIBGENERICA_H
#define BIBGENERICA_H
#include <fstream>
using namespace std;

void crearcola(void *&cola,void *(*leer)(ifstream &arch),int (*prioridad)(void *),const char *nomarch);
void encola(void *cola,void *dato,int (*obtienePrioridad)(void *));
int colaVacia(void *cola);
void *desencola(void *cola);
void imprimeLinea(ofstream &arch, int n, char c);
void imprimir(void *cola,void (*imprime)(void *dato,ofstream &arch));
void atiendeNumero(void *cola);

#endif /* BIBGENERICA_H */

