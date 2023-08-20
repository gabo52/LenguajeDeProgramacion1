/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conreceta.h
 * Author: cueva
 *
 * Created on 11 de junio de 2023, 10:44 AM
 */

#ifndef CONRECETA_H
#define CONRECETA_H

#include "medicamento.h"

class conreceta:public medicamento {
public:
    conreceta();
    conreceta(const conreceta& orig);
    virtual ~conreceta();
    void SetEspecialidad(char* );
    void GetEspecialidad(char *) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void leeconreceta(int,char*,int,int,int);
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

