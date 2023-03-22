/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Gabo
 *
 * Created on 16 de noviembre de 2022, 09:52 AM
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "Pedido.h"
#include "Deudor.h"

class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void carga();
    void muestra();
    void actualiza();
private:
    Pedido lpedido[200];
    Deudor ldeudor[200];
};
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
#endif /* PROCESA_H */

