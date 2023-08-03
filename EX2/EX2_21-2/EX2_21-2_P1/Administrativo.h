/* 
 * File:   Administrativo.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:34 PM
 */

#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "Usuario.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Administrativo : public Usuario{
public:
    Administrativo();
    virtual ~Administrativo();
    void SetArea(char* area);
    void GetArea(char* cad) const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
private:
    char *area;
};  

#endif /* ADMINISTRATIVO_H */

