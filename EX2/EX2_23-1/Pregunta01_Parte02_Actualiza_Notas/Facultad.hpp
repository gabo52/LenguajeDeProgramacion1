/* 
 * File:   Facultad.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:56 PM
 */

#ifndef FACULTAD_HPP
#define FACULTAD_HPP

#include "Utils.hpp"
#include "ListaDoble.hpp"
#include "Nota.hpp"

class Facultad {
public:
    Facultad();
    Facultad(const Facultad& orig);
    virtual ~Facultad();
    void leerAlumnosNotas(const char * archAlumnosPreg01,const char * NotasPreg01);
    void imprimeAlumnosNotas(const char *archReporte);
    // PARTE 2
    void actualizaNotas(void);

private:
    ListaDoble alumnosxNotas;
};

#endif /* FACULTAD_HPP */

