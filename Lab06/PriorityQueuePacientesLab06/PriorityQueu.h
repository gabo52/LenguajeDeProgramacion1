/* 
 * File:   PriorityQueu.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 20 de octubre de 2022, 10:27 PM
 */

#ifndef PRIORITYQUEU_H
#define PRIORITYQUEU_H
#include <fstream>
using namespace std;
void crearCola(void *&cl,ifstream &arch,int (*obtienePrioridad)(void *dato),
        void *(*leeRegistro)(ifstream &arch));
void encolar(void *cl,void *dato,int (*obtienePrioridad)(void *dato));
void *desencolar(void *cl);
int es_cola_vacia(void *cl);
void prueba(void *cl,void (*imprimeReg)(void *dato,ofstream &arch),ofstream &arch);

#endif /* PRIORITYQUEU_H */

