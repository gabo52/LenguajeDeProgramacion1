/* 
 * File:   Segunda.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:52 PM
 */

#ifndef SEGUNDA_HPP
#define SEGUNDA_HPP

#include "CursoAlumno.hpp"
#include "Utils.hpp"

class Segunda : public CursoAlumno {
public:
    Segunda();
    Segunda(const Segunda& orig);
    virtual ~Segunda();
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void leerNota(std::ifstream &file);
    void imprime(std::ofstream &file);
private:
    double creditos;
};

#endif /* SEGUNDA_HPP */

