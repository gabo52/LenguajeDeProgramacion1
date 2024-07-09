/* 
 * File:   ListaDoble.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 12:00 AM
 */

#ifndef LISTADOBLE_HPP
#define LISTADOBLE_HPP

#include "Utils.hpp"
#include "Nodo.hpp"
#include "Alumno.hpp"

class ListaDoble {
public:
    ListaDoble();
    ListaDoble(const ListaDoble& orig);
    virtual ~ListaDoble();
    void insertarOrdenado(class Nodo *&);
    bool existeAlumno(class Alumno &alumno);
    void insertarNota(int codigo_alumno,class Nota &nota);
    void imprimirReporte(std::ofstream &archReporte);
    void actualizar(void );
private:
    class Nodo *inicio;
    class Nodo *fin;
};

#endif /* LISTADOBLE_HPP */

