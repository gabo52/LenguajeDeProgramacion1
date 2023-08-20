/* 
 * File:   Ambulatorio.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:41 AM
 */

#ifndef AMBULATORIO_H
#define AMBULATORIO_H
#include "Paciente.h"
class Ambulatorio : public Paciente{
public:
    Ambulatorio();
    virtual ~Ambulatorio();
    void SetProcSeguro(double procSeguro);
    double GetProcSeguro() const;
    void operator = (const Ambulatorio &c);
private:
    double procSeguro;
};

#endif /* AMBULATORIO_H */

