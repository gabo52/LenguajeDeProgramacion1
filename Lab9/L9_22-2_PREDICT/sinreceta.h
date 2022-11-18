/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sinreceta.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 10:09 PM
 */

#ifndef SINRECETA_H
#define SINRECETA_H

#include "medicamento.h"


class sinreceta : public medicamento{
public:
    sinreceta();
    virtual ~sinreceta();
    void SetNombre(char* cad);
    void GetNombre(char* cad) const;
    void SetDni(int dni);
    int GetDni() const;
    void asignar(int medicamento,char *nombMedicamento,int cant,double precio,
                int fecha,int codmed,char *esp,int dni,char *nombPac);
    void imprime(ofstream &arch);
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

