/* 
 * File:   Nodo.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 12:00 AM
 */

#include "Nodo.hpp"

Nodo::Nodo() {
    siguiente = nullptr;
    anterior = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

void Nodo::insertarAlumno(Alumno &alumno){
    this->dato.insertarAlumno(alumno);
}

void Nodo::insertarNota(Nota &nota){
    this->dato.insertarNota(nota);
}


