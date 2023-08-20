
/* 
 * File:   BibliotecaPilaGenerica.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 30 de mayo de 2023, 08:41 AM
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H
#include <fstream>
using namespace std; 

void cargaarreglo(void *&arreglo, int(*cmp)(const void *,const void *), void*(*lee)(ifstream &),const char *nombre); 
void cargapila(void *&pila, void *arreglo);
void push(void *&pila, void *arreglo); 
void generapila(void *&pila); 
int pilavacia(void *pila);
void hanoi(int n, void *ini, void *aux, void *fin); 
void *pop(void *pila); 
void muevepila(void *pilaini, void *&pilafin); 


#endif /* BIBLIOTECAPILAGENERICA_H */

