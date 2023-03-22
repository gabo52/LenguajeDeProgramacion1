/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grave.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 06:33 PM
 */

#ifndef GRAVE_H
#define GRAVE_H

#include "Falta.h"
#include "Infraccion.h"


class Grave : public Infraccion{
public:
    //Grave(const Grave& orig);
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void operator = (const Grave &c);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    double descuento;
    int puntos;
};

#endif /* GRAVE_H */

