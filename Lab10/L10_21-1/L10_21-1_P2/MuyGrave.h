/* 
 * File:   MuyGrave.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 23 de noviembre de 2022, 06:38 PM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H

#include "Infraccion.h"


class MuyGrave : public Infraccion{
public:
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    int puntos;
    int meses;
};

#endif /* MUYGRAVE_H */

