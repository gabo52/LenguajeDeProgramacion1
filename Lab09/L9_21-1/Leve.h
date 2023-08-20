
/* 
 * File:   Leve.h
 * Author: USER
 *
 * Created on 20 de junio de 2023, 03:33 PM
 */

#ifndef LEVE_H
#define LEVE_H
#include "Falta.h"

class Leve : public Infraccion{
public:
    Leve();
    Leve(const Leve& orig);
    virtual ~Leve();
    void SetDescuento(double descuento);
    double GetDescuento() const;
private:
    double descuento; 
};

#endif /* LEVE_H */

