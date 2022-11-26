/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LFalta.h
 * Author: Gabo
 *
 * Created on 23 de noviembre de 2022, 06:40 PM
 */

#ifndef LFALTA_H
#define LFALTA_H
#include <fstream>
using namespace std;
#include "NFalta.h"
#include "Falta.h"
#include "Infraccion.h"
#include "Leve.h"
#include "Grave.h"
#include "MuyGrave.h"
class LFalta {
public:
    LFalta();
    virtual ~LFalta();
    void leer(const char *nomb);
    void imprimir(const char *nomb);
    void insertar(Falta &p,Infraccion *inf);
    void unir(LFalta &lista);
    void lee(ifstream &arch,Falta &falt,Infraccion *&inf);
private:
    class NFalta *lini;
    class NFalta *lfin;
};
void AbrirArchivo(const char *nomb, ifstream &arch);
void AbrirArchivo(const char *nomb, ofstream &arch);
void imprimeLinea(ofstream &arch,int cant,char c);
#endif /* LFALTA_H */

