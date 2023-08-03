

/* 
 * File:   Copia.h
 * Author: USER
 *
 * Created on 21 de junio de 2023, 06:42 PM
 */

#ifndef COPIA_H
#define COPIA_H
#include <fstream>
#include "Libro.h"
using namespace std; 

class Copia {
public:
    Copia();
    Copia(const Copia& orig);
    virtual ~Copia();
    void SetEstado(char *cad);
    void GetEstado(char *cad) const;
    void SetNumero(int numero);
    int GetNumero() const;
    void actualizar();
    int existe();
    void imprimelibros(ofstream &arch);
    void copiar(char *codlib, char *tit, char *aut, int cant, double prec, int num, int zone); 
private:
    int numero;
    char *estado; 
    Libro *Olibro; 
};

#endif /* COPIA_H */

