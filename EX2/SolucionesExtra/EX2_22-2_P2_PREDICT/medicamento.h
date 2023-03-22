/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 05:58 PM
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
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch)=0;
    virtual void imprime(ofstream &arch)=0;
    virtual void copia(medicamento *&med)=0;
    
private:
    int codigo;
    char *nombre;
    int stock;
    double precio;
};

#endif /* MEDICAMENTO_H */

