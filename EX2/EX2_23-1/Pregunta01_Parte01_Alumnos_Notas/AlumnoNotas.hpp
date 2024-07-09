/* 
 * File:   AlumnoNotas.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:59 PM
 */

#ifndef ALUMNONOTAS_HPP
#define ALUMNONOTAS_HPP

#include "Utils.hpp"
#include "Alumno.hpp"
#include "Nota.hpp"

class AlumnoNotas {
public:
    AlumnoNotas();
    AlumnoNotas(const AlumnoNotas& orig);
    virtual ~AlumnoNotas();
    bool operator<(AlumnoNotas & nota);
    void insertarAlumno(Alumno &alumno);
    bool esAlumno(Alumno &alumno);
    bool esALumno(int);
    void insertarNota(Nota &nota);
    void imprimirAlumno(std::ofstream &archReporte);


private:
    Alumno alumno;
    std::vector<class Nota>notas;
};

#endif /* ALUMNONOTAS_HPP */

