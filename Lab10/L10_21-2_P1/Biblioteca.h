/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: Gabo
 *
 * Created on 24 de noviembre de 2022, 09:43 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "ALibro.h"


class Biblioteca {
public:
    void LeeLibros();
    void ImprimeLibros();
    void ActualizaLibros();
private:
    ALibro AStock;
};
void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);
#endif /* BIBLIOTECA_H */

