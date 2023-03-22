/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:05 AM
 */
#include "Producto.h"
#include <fstream>
using namespace std;

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido: public Producto {
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    char *obs;

public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
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
    void SetObs(char*);
    void GetObs(char *) const;
    void leepedido(ifstream &);
    void imprimePedido(ofstream &);

};

#endif /* PEDIDO_H */

