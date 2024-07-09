/* 
 * File:   Alumno.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:48 PM
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include "Utils.hpp"

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetPromedio(double promedio);
    double GetPromedio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *nombre) const;
    void SetCodigo_alumno(int codigo_alumno);
    int GetCodigo_alumno() const;
    // funciones del problema
    void imprimeAlumno (std::ofstream &file);
    
private:
    int codigo_alumno;
    char* nombre;
    double promedio;
};
void operator>>(std::ifstream &file, Alumno &alumno);

#endif /* ALUMNO_HPP */

