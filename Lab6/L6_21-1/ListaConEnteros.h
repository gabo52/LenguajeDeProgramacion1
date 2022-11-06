/* 
 * File:   ListaConEnteros.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 25 de octubre de 2022, 06:16 PM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H
#include <fstream>
using namespace std;
void *leenum(ifstream &arch);
int cmpnum(void *dt1,void *dt2);
void imprimenum(void *dt,ofstream &arch,void *&cabecera);
#endif /* LISTACONENTEROS_H */

