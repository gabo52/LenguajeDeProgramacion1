/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 06:40 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include "Registro.h"
class Procesa {
public:
    Procesa();
    virtual ~Procesa();
    void leer(); 
    void imprimir();
    void aplicar();
    void consolidar();
    void imprimeConsolidar(ofstream &archRep,int licencia);
private:
    Registro lregistro[10000];  
    int cantidad;                
};

#endif /* PROCESA_H */

