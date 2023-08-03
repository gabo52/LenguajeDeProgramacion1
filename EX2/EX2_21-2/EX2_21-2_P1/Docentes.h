/* 
 * File:   Docentes.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:34 PM
 */

#ifndef DOCENTES_H
#define DOCENTES_H

#include "Usuario.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Docentes : public Usuario{
public:
    //Docentes(const Docentes& orig);
    void SetAnexo(int anexo);
    int GetAnexo() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int anexo;
};

#endif /* DOCENTES_H */

