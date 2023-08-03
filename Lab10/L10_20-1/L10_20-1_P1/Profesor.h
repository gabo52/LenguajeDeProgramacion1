/* 
 * File:   Profesor.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 24 de noviembre de 2022, 06:15 PM
 */

#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"


class Profesor :public Persona{
public:
    Profesor();
    
    virtual ~Profesor();
    void SetGrado(char* grado);
    void GetGrado(char* cad) const;
    void SetSeccion(char* seccion);
    void GetSeccion(char* cad) const;
    void SetDedicacion(char* dedicacion);
    void GetDedicacion(char* cad) const;
    void SetCategoria(char* categoria);
    void GetCategoria(char* cad) const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);    
private:
    char *categoria;
    char *dedicacion;
    char *seccion;
    char *grado;
};

#endif /* PROFESOR_H */

