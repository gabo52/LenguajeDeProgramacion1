/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   farmacia.h
 * Author: cueva.r
 *
 * Created on 14 de junio de 2023, 11:02 AM
 */

#ifndef FARMACIA_H
#define FARMACIA_H

#include "Oferta.h"


class farmacia {
public:
    farmacia();
    farmacia(const farmacia& orig);
    virtual ~farmacia();
    void leerecetas();
    void descuenta();
    void imprimerecetas();
private:
    Oferta loferta[1000];
    
};

#endif /* FARMACIA_H */

