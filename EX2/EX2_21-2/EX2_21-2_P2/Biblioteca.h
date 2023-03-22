/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: Gabo
 *
 * Created on 26 de noviembre de 2022, 10:36 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "RegistroUsuario.h"
#include "Libro.h"
#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Biblioteca {
public:
    void leeLibros(const char*);
    void imprimeLibros(const char*);
    void leerUsuarios(const char*);
    void leerPrestamos(const char *);
    void imprimeUsuarios(const char*);
    void imprimirSuspendidos(const char*,int dd, int mm, int aa);
    void actualizarLibros(char *cad);
    void actualizarUsuario(int cod,char tipo,int fecha,char *cad);
private:
    list<Libro>libros;
    vector<RegistroUsuario>usuarios;
};

#endif /* BIBLIOTECA_H */

