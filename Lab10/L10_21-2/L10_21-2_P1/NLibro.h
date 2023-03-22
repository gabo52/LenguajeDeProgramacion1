/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NLibro.h
 * Author: Gabo
 *
 * Created on 24 de noviembre de 2022, 09:38 PM
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include "Libro.h"
#include "ALibro.h"

class NLibro {
public:
    NLibro();
    friend class ALibro;
private:
    Libro dlibro;
    NLibro *izq;
    NLibro *der;
};

#endif /* NLIBRO_H */

