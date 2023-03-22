/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.h
 * Author: Gabo
 *
 * Created on 17 de noviembre de 2022, 06:52 PM
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class medicamento {
public:
    medicamento();
    virtual ~medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombreMedicamento(char* nombre);
    void GetNombreMedicamento(char* cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void asigna(int cod,char *nombreMed,int cant,double prec,
    int fech,int codmed,char *esp,int dni,char *nombrePac)=0;
    virtual void imprime(ofstream &arch)=0;
    int operator > (medicamento *med);
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
};

#endif /* MEDICAMENTO_H */

