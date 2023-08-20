/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.h
 * Author: cueva
 *
 * Created on 11 de junio de 2023, 10:38 AM
 */
#include <fstream>

using namespace std;

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

class medicamento {
public:
    medicamento();
    medicamento(const medicamento& orig);
    virtual ~medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* );
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leemedicamento(int);
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
};

#endif /* MEDICAMENTO_H */

