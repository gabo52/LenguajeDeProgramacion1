/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MuyGrave.h
 * Author: Gabo
 *
 * Created on 23 de noviembre de 2022, 06:38 PM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H

#include "Infraccion.h"


class MuyGrave : public Infraccion{
public:
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    int puntos;
    int meses;
};

#endif /* MUYGRAVE_H */

