/* 
 * File:   Renovacion.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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
private:
    double multa;
    double tramite;
    double exmedico;
};

#endif /* RENOVACION_H */

