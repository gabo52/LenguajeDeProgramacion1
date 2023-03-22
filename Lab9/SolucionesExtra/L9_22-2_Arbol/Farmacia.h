/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Farmacia.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 07:16 PM
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "medicamento.h"
#include "medico.h"
#include "Arbol.h"
class Farmacia {
public:
    Farmacia();
    virtual ~Farmacia();
    void leer();
    void imprimir();
    void leerRecetas(ifstream &arch);
    void buscaMedico(int codMed,char *nombreMedico,char *especialidad);
private:
    medico lmedico[200];
    Arbol arbol;
};
void buscaMedicamento(int cod,char *nomb,double &precio);
#endif /* FARMACIA_H */

