/* 
 * File:   BibGenerica.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de octubre de 2022, 11:21 PM
 */

#ifndef BIBGENERICA_H
#define BIBGENERICA_H
#include <fstream>
using namespace std;
int arbolvacio(void *arb);
void creaarbol(void *&arb,void *(*lee)(ifstream &arch),
        int (*cmp)(void *dato1,void *dato2),const char *nomb);
void insertanodo(void *&arb,void *dato,int (*cmpnumero)(void *dato1,void *dato2));
void muestraarbol(void *arbol,void (*imprime)(void *dato,ofstream &arch,void *&dato2),
        const char *nomb);
void enorden(void *arb,void (*imprime)(void *dato,ofstream &arch,void *&dato2),
        ofstream &arch,void *&flag);
#endif /* BIBGENERICA_H */

