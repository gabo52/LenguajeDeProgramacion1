

/* 
 * File:   Disponible.h
 * Author: USER
 *
 * Created on 21 de junio de 2023, 07:02 PM
 */

#ifndef DISPONIBLE_H
#define DISPONIBLE_H
#include "Libro.h"
#include <fstream>
using namespace std; 

class Disponible : public Libro{
public:
    Disponible();
    Disponible(const Disponible& orig);
    virtual ~Disponible();
    void SetZona(int zona);
    int GetZona() const;
    void actualiza(int dias, int fecha, double precio){}; 
    void cargadatos(char *codlib, char *tit, char *aut, int cant, double prec, int zone);
    void imprimir(ofstream &arch);
private:
    int zona;
};

#endif /* DISPONIBLE_H */

