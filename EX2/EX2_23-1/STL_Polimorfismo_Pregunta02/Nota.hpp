/* 
 * File:   Nota.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:53 PM
 */

#ifndef NOTA_HPP
#define NOTA_HPP

#include "Utils.hpp"
#include "CursoAlumno.hpp"
#include "Primera.hpp"
class Nota {
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    //funciones
    void leernota(std::ifstream &file);
    int GetCodigoAlumno();
    void GetCodcurAlumno(char *codcur);
    int GetCicloAlumno();
    void SetVez(int vez);
    void imprime(std::ofstream &file);
private:
    CursoAlumno * pnota;
};

#endif /* NOTA_HPP */

