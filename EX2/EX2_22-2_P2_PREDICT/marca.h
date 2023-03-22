/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   marca.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 06:03 PM
 */

#ifndef MARCA_H
#define MARCA_H

#include "medicamento.h"


class marca : public medicamento{
public:
    marca();
    virtual ~marca();
    void SetLaboratorio(char* laboratorio);
    void GetLaboratorio(char* cad) const;
    void SetLote(int lote);
    int GetLote() const;
    void operator = (const marca &c);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void copia(medicamento *&med);
    void copiar(marca &c);
private:
    int lote;
    char *laboratorio;
};

#endif /* MARCA_H */

