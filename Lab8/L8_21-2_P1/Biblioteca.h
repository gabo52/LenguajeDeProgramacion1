/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: Gabo
 *
 * Created on 10 de noviembre de 2022, 07:37 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Copia.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "FuncionesFecha.h"
using namespace std;

class Biblioteca {
public:
    void generaCopias();
    int numeroLibros();
    void leeLibro(ifstream &arch,int &n);
    void actualizaLibros();
    void imprimeCopias();
    void leePrestamo(char *cad,int &cant,int &fecha,ifstream &arch);
    void actualizaDisponibilidadLibros(char *cad,int cant,int fecha,int ref);
    int buscarLibro(char *cad,int &cantidad);
    void imprimeLinea(ofstream &arch,int cant,char c);
private:
    Copia llibros[1000];
};

#endif /* BIBLIOTECA_H */

