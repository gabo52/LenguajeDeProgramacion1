/* 
 * File:   conreceta.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 06:54 PM
 */

#ifndef CONRECETA_H
#define CONRECETA_H

#include "medicamento.h"


class conreceta :public medicamento{
public:
    conreceta();
    virtual ~conreceta();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char* cad) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void asigna(int cod,char *nombreMed,int cant,double prec,
    int fech,int codmed,char *esp,int dni,char *nombrePac);
    void imprime(ofstream &arch);
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

