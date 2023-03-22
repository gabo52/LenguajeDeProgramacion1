/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   farmacia.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 10:11 PM
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include <iostream>
#include <iomanip>

#include <fstream>
using namespace std;
#include "medico.h"
#include "medped.h"


class farmacia {
public:
    farmacia();
    virtual ~farmacia();
    void cargamedico();
    void leerecetas();
    void imprimirrecetas();
    void leer(ifstream &arch,int &n);
    void buscaMedicamento(int cod,char *nomb,double &precio);
    void buscarMedico(int codmed,char *nombMedico,char *esp);
    void imprimeSinReceta(ofstream &arch);
    void imprimeConReceta(ofstream &arch);
private:
    medico lmedico[200];
    medped medicamentos[2000];
};


void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
#endif /* FARMACIA_H */

