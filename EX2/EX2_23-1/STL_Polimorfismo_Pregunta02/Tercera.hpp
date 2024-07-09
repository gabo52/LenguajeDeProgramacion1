/* 
 * File:   Tercera.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:53 PM
 */

#ifndef TERCERA_HPP
#define TERCERA_HPP

#include "CursoAlumno.hpp"
#include "Utils.hpp"

class Tercera : public CursoAlumno {
public:
    Tercera();
    Tercera(const Tercera& orig);
    virtual ~Tercera();
    void SetPorcentaje(double porcentaje);
    double GetPorcentaje() const;
    void leerNota(std::ifstream &file);
    void imprime(std::ofstream &file);
private:
    double porcentaje;
};

#endif /* TERCERA_HPP */

