/* 
 * File:   medped.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:13 PM
 */

#ifndef MEDPED_H
#define MEDPED_H

#include "medicamento.h"


class medped {
public:
    medped();
    virtual ~medped();
    void leer(ifstream &arch);
    void asignar(int medicamento,char *nombMedicamento,int cant,double precio,
                int fecha,int codmed,int dni,char *nombPac);
    int activo();
    int codigo();
    void imprime(ofstream &arch);
private:
    medicamento *ptrmedped;
};

#endif /* MEDPED_H */

