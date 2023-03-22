/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: Gabo
 *
 * Created on 10 de noviembre de 2022, 07:22 PM
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Libro {
public:
    Libro();
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(char* autor);
    void GetAutor(char* ad) const;
    void SetTitulo(char* titulo);
    void GetTitulo(char* cad) const;
    void SetCodigo(char* codigo);
    void GetCodigo(char* cad) const;
    void imprimeLibro(ofstream &arch);
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    double precio;
};

#endif /* LIBRO_H */

