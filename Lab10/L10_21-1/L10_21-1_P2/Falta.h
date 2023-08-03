/* 
 * File:   Falta.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:34 PM
 */

#ifndef FALTA_H
#define FALTA_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Falta {
public:
    Falta();
    virtual ~Falta();
    void SetPlaca(char* placa);
    void GetPlaca(char* cad) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void leer(ifstream &arch);
    void operator = (const Falta &c); 
private:
    int licencia;
    int fecha;
    char *placa;
};

void operator << (ofstream &arch,const Falta &F);
void imprimeFecha(int fecha,ofstream &arch);
#endif /* FALTA_H */

