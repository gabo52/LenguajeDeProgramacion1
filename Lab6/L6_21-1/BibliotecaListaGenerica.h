/* 
 * File:   BibliotecaListaGenerica.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 25 de octubre de 2022, 06:16 PM
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
#include <fstream>
using namespace std;
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
void creaLista(void *&ls,void *(*lee)(ifstream &),int (*cmp)(void *,void *)
    ,const char *nomb);
void insertaLista(void *ls,void *dato,int (*cmp)(void *dato1,void *dato2));
int listaVacia(void *ls);
void uneLista(void *ls1,void *ls2);
void imprimeLista(void *ls,void (*imprime)(void *,ofstream &,void *&),
        const char *nomb);

#endif /* BIBLIOTECALISTAGENERICA_H */

