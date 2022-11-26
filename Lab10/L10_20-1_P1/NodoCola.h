/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.h
 * Author: Gabo
 *
 * Created on 24 de noviembre de 2022, 06:43 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Persona.h"
#include "Cola.h"

class NodoCola {
public:
    NodoCola();
    friend class Cola;
private:
    NodoCola *sig;
    Persona *persona;
};

#endif /* NODOCOLA_H */

