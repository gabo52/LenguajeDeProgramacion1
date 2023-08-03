/* 
 * File:   Pedido.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de noviembre de 2022, 05:35 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Pedido : public Producto{
public:
    Pedido();
    virtual ~Pedido();
    void SetObs(char* obs);
    void GetObs(char*cad) const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator = (const Pedido &c);
    void SetDni(int dni);
    int GetDni() const;
    void imprime(ofstream &arch);
private:
    int codigo;
    int cantidad;
    int fecha;
    double total;
    char *obs;
    int dni;
};

#endif /* PEDIDO_H */

