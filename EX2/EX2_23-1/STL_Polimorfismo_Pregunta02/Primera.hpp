/* 
 * File:   Primera.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:47 PM
 */

#ifndef PRIMERA_HPP
#define PRIMERA_HPP

#include "Utils.hpp"
#include "CursoAlumno.hpp"

class Primera : public CursoAlumno {
public:
    Primera();
    Primera(const Primera& orig);
    virtual ~Primera();
    void SetCodacceso(const char* codacceso);
    void GetCodacceso(char* codacceso) const;
    void leerNota(std::ifstream &file);
    void imprime(std::ofstream &file);
private:
    char *codacceso;
};

#endif /* PRIMERA_HPP */

