/* 
 * File:   Paciente.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:15 PM
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class Paciente {
public:
    Paciente();
    virtual ~Paciente();
    void SetCodMed(char* codMed);
    void GetCodMed(char* cad) const;
    void SetNombre(char* nombre);
    void GetNombre(char* cad) const;
    void SetDni(int dni);
    int GetDni() const;
    virtual void leer(ifstream &arch)=0;
    virtual void imprimir(ofstream &arch)=0;
    virtual int prioridad()=0;
    void SetEdad(int edad);
    int GetEdad() const;
    virtual void observacion(char *cad)=0;
private:
    int dni;
    char *nombre;
    char *codMed;
    int edad;
};

#endif /* PACIENTE_H */

