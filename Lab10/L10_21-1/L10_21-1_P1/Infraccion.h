/* 
 * File:   Infraccion.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:31 PM
 */

#ifndef INFRACCION_H
#define INFRACCION_H
#include <fstream>
#include <iomanip>
#include <iostream>
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
    virtual void leer(ifstream &arch)=0;
    virtual void imprimir(ofstream &arch)=0;
private:
    int codigo;
    char *gravedad;
    double multa;
};

#endif /* INFRACCION_H */

