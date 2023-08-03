/* 
 * File:   Conductor.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:40 PM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class Conductor {
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
    void operator =(const Conductor &c);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    int licencia;
    char *nombre;
};

#endif /* CONDUCTOR_H */

