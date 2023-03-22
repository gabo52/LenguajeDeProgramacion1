/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   generico.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 06:01 PM
 */

#ifndef GENERICO_H
#define GENERICO_H

#include "medicamento.h"


class generico : public medicamento{
public:
    generico();
    virtual ~generico();
    void SetPais(char* pais);
    void GetPais(char* cad) const;
    void operator = (const generico &c);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void copia(medicamento *&med);
    void copiar(generico &c);
private:
    char *pais;
};

#endif /* GENERICO_H */

