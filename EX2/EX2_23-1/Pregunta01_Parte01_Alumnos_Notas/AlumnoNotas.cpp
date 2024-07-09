/* 
 * File:   AlumnoNotas.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:59 PM
 */

#include "AlumnoNotas.hpp"

using namespace std;

AlumnoNotas::AlumnoNotas() {
}

AlumnoNotas::AlumnoNotas(const AlumnoNotas& orig) {
}

AlumnoNotas::~AlumnoNotas() {
}

bool AlumnoNotas::operator<(AlumnoNotas & nota) {
    int codigoA = this->alumno.GetCodigo_alumno();
    int codigoB = nota.alumno.GetCodigo_alumno();
    return codigoA < codigoB;
}

bool AlumnoNotas::esAlumno(Alumno &alumno) {
    return this->alumno.GetCodigo_alumno() == alumno.GetCodigo_alumno();
}

bool AlumnoNotas::esALumno(int codigo_alumno) {
    int codigo = this->alumno.GetCodigo_alumno();
    return codigo == codigo_alumno;
}

void AlumnoNotas::insertarAlumno(Alumno &alumno) {
    char nombre[50];
    alumno.GetNombre(nombre);
    this->alumno.SetCodigo_alumno(alumno.GetCodigo_alumno());
    this->alumno.SetPromedio(alumno.GetPromedio());
    this->alumno.SetNombre(nombre);
}

void AlumnoNotas::insertarNota(Nota &n) {
    int vez = 1;
    char codigo[10], codigo_nota[10];
    n.GetCodigo_curso(codigo_nota);

    for (int i = 0; i < notas.size(); i++) {
        this->notas[i].GetCodigo_curso(codigo);
        if (strcmp(codigo, codigo_nota) == 0) vez++;
    }
    n.SetVez(vez);
    this->notas.push_back(n);
}

void AlumnoNotas::imprimirAlumno(std::ofstream &archReporte) {
    this->alumno.imprimeAlumno(archReporte);
    archReporte << left << setw(10) << "CICLO"
            << setw(10) << "CURSO"
            << setw(10) << "CREDITO"
            << setw(10) << "NOTA"
            << "VEZ" << endl;
    for (Nota nota : notas) {
        nota.imprimeNota(archReporte);
    }
    archReporte << setw(100) << setfill('=') << endl;
};
