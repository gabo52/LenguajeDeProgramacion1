/* 
 * File:   sinreceta.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:09 PM
 */

#ifndef SINRECETA_H
#define SINRECETA_H

#include "medicamento.h"


class sinreceta : public medicamento{
public:
    sinreceta();
    virtual ~sinreceta();
    void SetNombre(char* cad);
    void GetNombre(char* cad) const;
    void SetDni(int dni);
    int GetDni() const;
    void asignar(int medicamento,char *nombMedicamento,int cant,double precio,
                int fecha,int codmed,char *esp,int dni,char *nombPac);
    void imprime(ofstream &arch);
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

