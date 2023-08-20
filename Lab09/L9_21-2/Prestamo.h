
/* 
 * File:   Prestamo.h
 * Author: USER
 *
 * Created on 21 de junio de 2023, 07:03 PM
 */

#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Libro.h"
#include <fstream>
using namespace std;

class Prestamo : public Libro{
public:
    Prestamo();
    Prestamo(const Prestamo& orig);
    virtual ~Prestamo();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDias(int dias);
    int GetDias() const;
    void cargadatos(char *codlib, char *tit, char *aut, int cant, double prec, int zone){}; 
    void actualiza(int dias, int fecha, double precio); 
    void imprimir(ofstream &arch);
private:
    int dias;
    int fecha;
};

#endif /* PRESTAMO_H */

