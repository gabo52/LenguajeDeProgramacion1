/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NArbol.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 06:08 PM
 */

#ifndef NARBOL_H
#define NARBOL_H

#include "medicamento.h"
#include "Arbol.h"


class NArbol {
public:
    NArbol();
    NArbol(const NArbol& orig);
    virtual ~NArbol();
    friend class Arbol;
private:
    medicamento *med;
    NArbol *izq;
    NArbol *der;
};

#endif /* NARBOL_H */

