/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#include "Preg1_Funciones_de_cursos_y_alumnos.hpp"

int main(int argc, char** argv) {
    char ***cursos, ***alumnos_nom_mod;
    double *cursos_cred, escalas[5];
    int *alumnos_cod, **alumnos;
    cargarCursosYEscalas(cursos, cursos_cred, escalas, "Cursos.csv", "Escalas.csv");
//    pruebaDeCargaDeCursos(cursos, cursos_cred, "PruebaCursos.txt");
//    cargarAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "Alumnos.csv");
//    pruebaDeCargaDeAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "PruebaAlumnos.txt");
    return 0;
}
