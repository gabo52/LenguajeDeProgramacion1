/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MuyGrave.h
 * Author: Gabo
 *
 * Created on 8 de noviembre de 2022, 06:50 PM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H

#include "Infraccion.h"
#include "Falta.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class MuyGrave:public Infraccion, public Falta {
public:
    MuyGrave();
    virtual ~MuyGrave();
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void operator = (const MuyGrave &c);
    void imprime(ofstream &arch);
private:
    int puntos;
    int meses;
};

#endif /* MUYGRAVE_H */

