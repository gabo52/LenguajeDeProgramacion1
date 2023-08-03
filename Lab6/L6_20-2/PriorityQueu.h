
/* 
 * File:   PriorityQueu.h
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 25 de mayo de 2023, 05:19 PM
 */

#ifndef PRIORITYQUEU_H
#define PRIORITYQUEU_H
#include <fstream>
using namespace std;

void crearCola(void *&cola,ifstream &arch,int (*obtienePrioridad)(void *dato),void *(*leeRegistro)(ifstream &arch)); 
void encolar(void *cola,void *dato,int (*obtienePrioridad)(void *dato));
void agregar(void **rec,void **nuevo,int(*obtienePrioridad)(void *dato),void **ant,void **cola,int p2);
void *desencolar(void *cl);
int es_cola_vacia(void *cola); 
void prueba(void *cola,void (*imprimeReg)(void *dato,ofstream &arch),ofstream &arch); 
void imprimeLinea(ofstream &arch, int n, int c);

#endif /* PRIORITYQUEU_H */

