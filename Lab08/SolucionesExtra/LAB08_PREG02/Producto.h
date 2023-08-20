/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Alumna: Sun Ji Sánchez
 * Código: 20180454
 * Created on 17 de junio de 2022, 08:05 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    int codprod;
    char *nombre;
    double precio;
    int stock;

public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    void SetNombre(char*);
    void GetNombre(char *) const;
    void cargaproducto(int codigo);

};

#endif /* PRODUCTO_H */

