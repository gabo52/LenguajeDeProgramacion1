/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 08:47 PM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
using namespace std;
#include "Renovacion.h"
#include "Conductor.h"
#include "Nuevo.h"
#include "Antiguo.h"

class Nodo {
public:
    Nodo();
    virtual ~Nodo();
    Nodo(const Nodo &orig);
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    bool operator < (const Nodo &c);
    int licencia();
    bool activo();
private:
    Renovacion *pcosto;
    Conductor chofer;
};

#endif /* NODO_H */

