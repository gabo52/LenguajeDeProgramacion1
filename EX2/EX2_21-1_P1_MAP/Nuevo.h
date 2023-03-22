/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nuevo.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 08:45 PM
 */

#ifndef NUEVO_H
#define NUEVO_H

#include "Renovacion.h"


class Nuevo : public Renovacion{
public:
    Nuevo();
    void SetExreglas(double exreglas);
    double GetExreglas() const;
    void leer(ifstream &arch,int lic);
    void imprimir(ofstream &arch);
    bool activo();
private:
    double exreglas;
};

#endif /* NUEVO_H */

