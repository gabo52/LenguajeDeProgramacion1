/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Gabo
 *
 * Created on 28 de noviembre de 2022, 06:36 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
#include "NPaciente.h"


class Procesa {
public:
    void lee(ifstream &arch);
    void ordena();
    void imprime();
    void imprimeLinea(ofstream &arch,int cant,char c);

private:
    NPaciente pacientes[500];
};

#endif /* PROCESA_H */

