/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NCola.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 07:19 PM
 */

#ifndef NCOLA_H
#define NCOLA_H

#include "medicamento.h"
#include "Cola.h"


class NCola {
public:
    NCola();
    virtual ~NCola();
    friend class Cola;
private:
    medicamento *med;
    NCola *sig;
};

#endif /* NCOLA_H */

