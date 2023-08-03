/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   farmacia.h
 * Author: cueva
 *
 * Created on 11 de junio de 2023, 11:20 AM
 */

#ifndef FARMACIA_H
#define FARMACIA_H

#include "sinreceta.h"
#include "conreceta.h"
#include "medico.h"


class farmacia {
public:
    farmacia();
    farmacia(const farmacia& orig);
    virtual ~farmacia();
    void leerecetas();
    void cargamedicos();
    void cargamedicamento(ifstream &,int ,int ,char *,int );
    void buscaespecialidad(int ,char*);
    void imprimirrecetas();
private:
    medico lmedico[100];
    sinreceta lsinreceta[1000];
    conreceta lconreceta[1000];
    
};

#endif /* FARMACIA_H */

