/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Gabo
 *
 * Created on 8 de noviembre de 2022, 06:55 PM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <fstream>
#include "Registro.h"
using namespace std;

class Procesa {
public:
    Procesa();
    virtual ~Procesa();
    void leeRegistro(ifstream &,int &,int &,int &,char *);
    int buscarConductor(int cod);
    void PagregaFalta(Registro &reg,int codInfrac,int fecha,char *placa);
    void lee();
    void imprime();
    void consolida();
private:
    Registro lregistro[200];
    int cantidad;
};

#endif /* PROCESA_H */

