/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oferta.h
 * Author: cueva.r
 *
 * Created on 14 de junio de 2023, 10:58 AM
 */

#ifndef OFERTA_H
#define OFERTA_H
#include <fstream>
#include "medicamento.h"

using namespace std;

class Oferta {
public:
    Oferta();
    Oferta(const Oferta& orig);
    virtual ~Oferta();
    void leeoferta(ifstream &,int);
    void aplicadescuento();
    void imprimeoferta(ofstream &);
    int existe();
private:
    medicamento *poferta;
};

#endif /* OFERTA_H */

