/* 
 * File:   Disponible.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:30 PM
 */

#ifndef DISPONIBLE_H
#define DISPONIBLE_H
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
class Disponible {
public:
    void SetZona(int zona);
    int GetZona() const;
    void operator = (const Disponible &c);
    void imprimeDisponible(ofstream &arch);
private:
    int zona;
};

#endif /* DISPONIBLE_H */

