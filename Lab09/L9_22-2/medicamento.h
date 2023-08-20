/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.h
 * Author: cueva
 *
 * Created on 5 de noviembre de 2022, 11:16 AM
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <fstream>

using namespace std;

class medicamento {
public:
    medicamento();
    medicamento(const medicamento& orig);
    virtual ~medicamento();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* );
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetTotal(double total);
    double GetTotal() const;
    virtual void aplicadescuento();
    virtual void leemedicamento(ifstream&,int);
    virtual void imprimemedicamento(ofstream&);
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
    double total;
};

#endif /* MEDICAMENTO_H */

