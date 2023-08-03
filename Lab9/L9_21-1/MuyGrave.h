
/* 
 * File:   MuyGrave.h
 * Author: USER
 *
 * Created on 20 de junio de 2023, 03:34 PM
 */

#ifndef MUYGRAVE_H
#define MUYGRAVE_H
#include "Falta.h"

class MuyGrave : public Falta{
public:
    MuyGrave();
    MuyGrave(const MuyGrave& orig);
    virtual ~MuyGrave();
    void SetMeses(int meses);
    int GetMeses() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
private:
    int puntos;
    int meses; 
};

#endif /* MUYGRAVE_H */

