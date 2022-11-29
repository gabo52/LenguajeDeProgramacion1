/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.h
 * Author: Gabo
 *
 * Created on 26 de noviembre de 2022, 08:39 PM
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "ColaSol.h"

class NodoCola {
public:
    NodoCola();
    void SetCarne(int carne);
    int GetCarne() const;
    void SetLibsol(char* libsol);
    void GetLibsol(char* cad) const;
    friend class ColaSol;
    virtual ~NodoCola();
private:
    char *libsol;
    int carne;
    NodoCola *sig;
};

#endif /* NODOCOLA_H */

