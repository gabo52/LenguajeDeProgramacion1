/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docentes.h
 * Author: Gabo
 *
 * Created on 26 de noviembre de 2022, 08:34 PM
 */

#ifndef DOCENTES_H
#define DOCENTES_H

#include "Usuario.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Docentes : public Usuario{
public:
    //Docentes(const Docentes& orig);
    void SetAnexo(int anexo);
    int GetAnexo() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int anexo;
};

#endif /* DOCENTES_H */

