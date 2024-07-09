/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#include "Facultad.hpp"

int main(int argc, char** argv) {
    class Facultad facultad;
    facultad.leerAlumnosNotas("Alumnos-Preg01.csv", "Notas-Preg01.csv");
    facultad.imprimeAlumnosNotas("PruebaAlumnosNotas.txt");
    return 0;
}

