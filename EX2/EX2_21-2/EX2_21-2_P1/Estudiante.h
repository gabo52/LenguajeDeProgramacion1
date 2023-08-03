/* 
 * File:   Estudiante.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:36 PM
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Estudiante : public Usuario{
public:
    //Estudiante(const Estudiante& orig);
    void SetCelular(int celular);
    int GetCelular() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);    
private:
    int celular;
};

#endif /* ESTUDIANTE_H */

