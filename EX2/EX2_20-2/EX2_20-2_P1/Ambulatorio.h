/* 
 * File:   Ambulatorio.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:19 PM
 */

#ifndef AMBULATORIO_H
#define AMBULATORIO_H

#include "Paciente.h"


class Ambulatorio : public Paciente{
public:
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int prioridad();
    void observacion(char *cad);
private:
    double porcSeguro;
};

#endif /* AMBULATORIO_H */

