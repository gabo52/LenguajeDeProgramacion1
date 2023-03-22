/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Disponible.h
 * Author: Gabo
 *
 * Created on 10 de noviembre de 2022, 07:30 PM
 */

#ifndef DISPONIBLE_H
#define DISPONIBLE_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Disponible {
public:
    void SetZona(int zona);
    int GetZona() const;
    void operator = (const Disponible &c);
    void imprimeDisponible(ofstream &arch);
private:
    int zona;
};

#endif /* DISPONIBLE_H */

