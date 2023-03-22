/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 07:18 PM
 */

#ifndef COLA_H
#define COLA_H

#include "NCola.h"


class Cola {
public:
    Cola();
    virtual ~Cola();
    void encola(medicamento *&med);
    void desencola(medicamento *&med);
    bool empty();
private:
    class NCola *ini;
    class NCola *fin;
};

#endif /* COLA_H */

