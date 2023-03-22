/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estudiante.h
 * Author: Gabo
 *
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

