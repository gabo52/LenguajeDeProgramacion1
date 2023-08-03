/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sinreceta.h
 * Author: cueva
 *
 * Created on 11 de junio de 2023, 11:00 AM
 */

#ifndef SINRECETA_H
#define SINRECETA_H

#include "medicamento.h"


class sinreceta:public medicamento {
public:
    sinreceta();
    sinreceta(const sinreceta& orig);
    virtual ~sinreceta();
    void SetNombre(char* );
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void leesinreceta(int ,int ,char *,int );
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

