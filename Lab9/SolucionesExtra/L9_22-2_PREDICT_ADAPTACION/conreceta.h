/* 
 * File:   conreceta.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:07 PM
 */

#ifndef CONRECETA_H
#define CONRECETA_H

#include "medicamento.h"


class conreceta : public medicamento{
public:
    conreceta();
    virtual ~conreceta();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char* cad) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void asignar(int medicamento,char *nombMedicamento,int cant,double precio,
                int fecha,int codmed,char *esp,int dni,char *nombPac);
    void imprime(ofstream &arch);
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

