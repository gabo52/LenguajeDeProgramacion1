/* 
 * File:   Nodo.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:47 PM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
using namespace std;
#include "Renovacion.h"
#include "Conductor.h"
#include "Nuevo.h"
#include "Antiguo.h"

class Nodo {
public:
    Nodo();
    virtual ~Nodo();
    Nodo(const Nodo &orig);
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    bool operator < (const Nodo &c);
private:
    Renovacion *pcosto;
    Conductor chofer;
};

#endif /* NODO_H */

