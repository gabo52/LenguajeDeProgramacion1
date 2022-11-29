/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 03:01 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    void SetOrden(int orden);
    int GetOrden() const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator = (const Pedido &c);
    bool operator > (const Pedido &c);
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    int orden;
};

#endif /* PEDIDO_H */

