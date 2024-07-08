/* 
 * File:   Nodo.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 12:00 AM
 */

#ifndef NODO_HPP
#define NODO_HPP

#include "Utils.hpp"
#include "AlumnoNotas.hpp"
#include "ListaDoble.hpp"
#include "Nota.hpp"
class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class ListaDoble;
    void insertarAlumno(Alumno &alumno);
    void insertarNota(Nota &nota);
private:
    AlumnoNotas dato;
    class Nodo *siguiente;
    class Nodo *anterior;
};

#endif /* NODO_HPP */

