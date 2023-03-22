/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 06:24 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class Infraccion {
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(char* gravedad);
    void GetGravedad(char* cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &arch)=0;
    virtual void imprime(ofstream &arch)=0;
    virtual void aplica()=0;
    virtual void sumaDatos(int &puntos,int &meses,double &monto)=0;
private:
    int codigo;
    char *gravedad;
    double multa;
};

#endif /* INFRACCION_H */

