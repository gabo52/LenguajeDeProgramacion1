/* 
 * File:   Grave.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:37 PM
 */

#ifndef GRAVE_H
#define GRAVE_H

#include "Infraccion.h"


class Grave : public Infraccion{
public:
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    double descuento;
    int puntos;
};

#endif /* GRAVE_H */

