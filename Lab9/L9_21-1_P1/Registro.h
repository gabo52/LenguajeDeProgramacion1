/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 06:39 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H
#include <fstream>
using namespace std;
#include "Conductor.h"
#include "Falta.h"
#include "Infraccion.h"
#include "Grave.h"
#include "Leve.h"
#include "MuyGrave.h"


class Registro : public Conductor , public Falta{
public:
    void leeInfraccion(ifstream &arch,int cod);
    void leeRegistro(ifstream &arch);
    void imprimeReg(ofstream &arch);
    void leeConductores(ifstream &arch,int licencia);
private:
    Infraccion *pfalta;
};
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
#endif /* REGISTRO_H */

