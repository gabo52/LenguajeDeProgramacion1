/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: Gabo
 *
 * Created on 24 de noviembre de 2022, 06:42 PM
 */

#ifndef COLA_H
#define COLA_H

#include "NodoCola.h"


class Cola {
public:
    Cola();
    virtual ~Cola();
    void encola(Persona *per);
    void desencola(Persona *&per);
    void imprime(const char *nomb);
    void lee(const char *nomb);
private:
    class NodoCola *ini;
    class NodoCola *fin;
};

#endif /* COLA_H */

