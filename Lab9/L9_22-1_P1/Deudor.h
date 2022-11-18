/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deudor.h
 * Author: Gabo
 *
 * Created on 16 de noviembre de 2022, 09:51 AM
 */

#ifndef DEUDOR_H
#define DEUDOR_H
#include "Cliente.h"


class Deudor {
public:
    Deudor();
    virtual ~Deudor();
    void leer(ifstream &arch);
    int activo();
    void imprimir(ofstream &arch);
private:
    Cliente *Cdeudor;
};

#endif /* DEUDOR_H */

