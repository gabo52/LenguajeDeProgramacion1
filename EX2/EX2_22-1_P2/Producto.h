/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 03:04 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Producto {
public:
    Producto();
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    virtual void leer(ifstream &arch)=0;
    virtual void imprime(ofstream &arch)=0;
    virtual int obtienePrioridad()=0;
private:
    int codprod;
    char *nombre;
    int stock;
};

#endif /* PRODUCTO_H */

