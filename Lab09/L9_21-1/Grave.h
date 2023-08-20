

/* 
 * File:   Grave.h
 * Author: USER
 *
 * Created on 20 de junio de 2023, 03:33 PM
 */

#ifndef GRAVE_H
#define GRAVE_H
#include "Falta.h"

class Grave : public Falta{
public:
    Grave();
    Grave(const Grave& orig);
    virtual ~Grave();
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
private:
    double descuento;
    int puntos; 
};

#endif /* GRAVE_H */

