/* 
 * File:   BibliotecaColaGenerica.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 20 de octubre de 2022, 04:35 PM
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H
#include <fstream>
using namespace std;
void AbrirArchivo(ifstream &,const char *);
void AbrirArchivo(ofstream &,const char *);
void creaCola(void *&, void*(*)(ifstream &),const char *nomb);
void encola(void *&,void *);
void *desencola(void *&);
int colaVacia(void *cl);
void imprimir(void *,void (*)(ofstream &,void *,void *&),const char *);
void atiendeNumero(void *&);
void ordenaCola(void *cl,int (*cmpn)(void *dato1,void *dato2));
#endif /* BIBLIOTECACOLAGENERICA_H */

