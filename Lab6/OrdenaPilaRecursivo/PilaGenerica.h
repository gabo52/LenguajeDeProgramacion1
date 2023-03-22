/* 
 * File:   PilaGenerica.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de octubre de 2022, 04:45 PM
 */

#ifndef PILAGENERICA_H
#define PILAGENERICA_H
#include <fstream>
using namespace std;

void creaPila(void *&pl,void *(*lee)(ifstream &arch),const char *nomb);
int pilavacia(void *pl);
void apila(void *pl,void *dato);
void *desapila(void *pl);
int longitudPila(void *pl);
void imprimePila(void *pl,void (*imprime)(void *dato,ofstream &arch,void *&condicion),
        const char *nomb);
void ordenaPila(void *pl,int (*cmp)(void *dato1,void *dato2));
void ordenaPilaAux(void *pl,int (*cmp)(void *dato1,void *dato2));
void *cimaPila(void *pl);
#endif /* PILAGENERICA_H */

