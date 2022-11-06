/* 
 * File:   BibliotecaColaGenerica.h
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 06:38 PM
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H

void creaCola(void *&, void*(*)(ifstream &),ifstream &);
void encola(void *&,void *);
void *desencola(void *&);
int colaVacia(void *);
void imprimir(void *,void (*)(ofstream &,void *),ofstream &);
void atiendeNumero(void *&);
void atiendeCola(void *,int ,int ,int );

#endif /* BIBLIOTECACOLAGENERICA_H */

