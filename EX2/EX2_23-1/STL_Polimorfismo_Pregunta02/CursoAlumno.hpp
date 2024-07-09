/* 
 * File:   CursoAlumno.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:45 PM
 */

#ifndef CURSOALUMNO_HPP
#define CURSOALUMNO_HPP

#include "Utils.hpp"

class CursoAlumno {
public:
    CursoAlumno();
    CursoAlumno(const CursoAlumno& orig);
    virtual ~CursoAlumno();
    void SetVez(int vez);
    int GetVez() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcur(const char* codcur);
    void GetCodcur(char *codcur) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    // funciones
    virtual void leerNota(std::ifstream &file);
    virtual void imprime(std::ofstream &file){};


private:
    int codigo;
    char *codcur;
    int ciclo;
    double creditos;
    int nota;
    int vez;
};

#endif /* CURSOALUMNO_HPP */

