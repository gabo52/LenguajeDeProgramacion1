/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prestamo.h
 * Author: Gabo
 *
 * Created on 10 de noviembre de 2022, 07:31 PM
 */

#ifndef PRESTAMO_H
#define PRESTAMO_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Prestamo {
public:
    void SetFecha(int fecha);
    int GetFecha()const;
    void SetDias(int dias);
    int GetDias() const ;
    void operator = (const Prestamo &c);
    void imprimePrestamo(ofstream &arch);
private:
    int dias;
    int fecha;
};

#endif /* PRESTAMO_H */

