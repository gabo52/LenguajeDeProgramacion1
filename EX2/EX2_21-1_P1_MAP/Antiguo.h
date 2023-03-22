/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Antiguo.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 08:44 PM
 */

#ifndef ANTIGUO_H
#define ANTIGUO_H

#include "Renovacion.h"


class Antiguo : public Renovacion{
public:
    Antiguo();
    void SetEstado(int estado);
    int GetEstado() const;
    void SetExmanejo(double exmanejo);
    double GetExmanejo() const;
    void leer(ifstream &arch,int lic);
    void imprimir(ofstream &arch);
    bool activo();
private:
    double exmanejo;
    int estado;
};

#endif /* ANTIGUO_H */

