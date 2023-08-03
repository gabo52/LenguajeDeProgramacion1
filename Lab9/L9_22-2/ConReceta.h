
/* 
 * File:   ConReceta.h
 * Author: cueva
 *
 * Created on 5 de noviembre de 2022, 10:23 PM
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include <fstream>
#include "medicamento.h"

using namespace std;

class ConReceta:public medicamento {
public:
    ConReceta();
    ConReceta(const ConReceta& orig);
    virtual ~ConReceta();
    void SetEspecialidad(char* );
    void GetEspecialidad(char *) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
        
    void aplicadescuento();
    void leemedicamento(ifstream&,int);
    void imprimemedicamento(ofstream&);
private:
    int codmed;
    char *especialidad;
    void leespecialidad(int );
};

#endif /* CONRECETA_H */

