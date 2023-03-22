/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 08:48 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <list>
#include <map>
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
    void leeConductores();
    void leeConsultados();
    void verificarAgregarNodo(int lic);
    void imprimeLista();
    void imprimeMapa();
private:
    list<Nodo>lrenueva;
    map<int,Nodo>consultados;
};

void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
#endif /* PROCESA_H */

