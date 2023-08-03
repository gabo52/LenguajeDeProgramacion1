/* 
 * File:   Procesa.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

