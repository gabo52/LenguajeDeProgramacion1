

/* 
 * File:   Perdida.h
 * Author: USER
 *
 * Created on 21 de junio de 2023, 07:04 PM
 */

#ifndef PERDIDA_H
#define PERDIDA_H
#include "Libro.h"
#include <fstream>
using namespace std;

class Perdida : public Libro{
public:
    Perdida();
    Perdida(const Perdida& orig);
    virtual ~Perdida();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void cargadatos(char *codlib, char *tit, char *aut, int cant, double prec, int zone){};
    void actualiza(int dias, int fecha, double precio); 
    void imprimir(ofstream &arch);
private:
    double precio; 
};

#endif /* PERDIDA_H */

