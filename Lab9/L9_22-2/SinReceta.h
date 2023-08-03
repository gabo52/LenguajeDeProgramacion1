/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinReceta.h
 * Author: cueva
 *
 * Created on 5 de noviembre de 2022, 10:23 PM
 */

#ifndef SINRECETA_H
#define SINRECETA_H
#include <fstream>

#include "medicamento.h"

using namespace std;

class SinReceta:public medicamento {
public:
    SinReceta();
    SinReceta(const SinReceta& orig);
    virtual ~SinReceta();
    void SetNombrepac(char* );
    void GetNombrepac(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    void aplicadescuento();
    void leemedicamento(ifstream&,int);
    void imprimemedicamento(ofstream&);
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

