
/* 
 * File:   BibliotecaColaGenerica.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 03:15 PM
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H
#include <fstream>
using namespace std;

void creaCola(void *&cola,void *(*leer)(ifstream &arch));
void encola(void *cola,void *dato);
int colaVacia(void *cola); 
void *desencola(void *cola); 
void imprimeLinea(ofstream &arch, int n, char c);
void imprimir(void *cola,void (*imprime)(void *dato,ofstream &arch));
void atiendeNumero(void *cola); 


#endif /* BIBLIOTECACOLAGENERICA_H */

