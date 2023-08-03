/* 
 * File:   Procesa.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:48 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Nodo.h"
using namespace std;

class Procesa {
public:
    void imprimeLinea(ofstream &arch,int cant,char c);
    void lee();
    void imprime();
private:
    list<Nodo>lrenueva;
};

void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
#endif /* PROCESA_H */

