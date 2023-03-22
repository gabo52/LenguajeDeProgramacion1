/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: Gabo
 *
 * Created on 9 de noviembre de 2022, 05:31 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
public:
    Producto();
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    void operator = (const Producto &c);
private:
    int codprod;
    char *nombre;
    double precio;
    int stock;
};

#endif /* PRODUCTO_H */

