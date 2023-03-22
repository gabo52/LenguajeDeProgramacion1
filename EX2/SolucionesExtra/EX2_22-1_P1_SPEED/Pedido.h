/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Gabo
 *
 * Created on 28 de noviembre de 2022, 04:15 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Pedido {
public:
    void SetSubTotal(double subTotal);
    double GetSubTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCantidad(double cantidad);
    double GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    int leerDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
    void imprimeFecha(ofstream &arch,int fecha);
    bool operator <(const Pedido &c);
private:
    int codigo;
    double cantidad;
    int fecha;
    double subTotal;
};

#endif /* PEDIDO_H */

