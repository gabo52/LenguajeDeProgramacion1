/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renovacion.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 08:43 PM
 */

#ifndef RENOVACION_H
#define RENOVACION_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Renovacion {
public:
    Renovacion();
    void SetExmedico(double exmedico);
    double GetExmedico() const;
    void SetTramite(double tramite);
    double GetTramite() const;
    void SetMulta(double multa);
    double GetMulta() const;
    virtual void leer(ifstream &arch,int lic)=0;
    virtual void imprimir(ofstream &arch)=0;
    virtual bool activo()=0;
private:
    double multa;
    double tramite;
    double exmedico;
};

#endif /* RENOVACION_H */

