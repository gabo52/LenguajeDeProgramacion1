/* 
 * File:   BibliotecaColaGenerica.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 20 de octubre de 2022, 04:35 PM
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H
#include <fstream>

void AbrirArchivo(ifstream &,const char *);
void AbrirArchivo(ofstream &,const char *);
void creaCola(void *&, void*(*)(ifstream &));
void encola(void *&,void *);
void *desencola(void *&);
int colaVacia(void **);
void imprimir(void *,void (*)(ofstream &,void *));
void atiendeNumero(void *&);
#endif /* BIBLIOTECACOLAGENERICA_H */

