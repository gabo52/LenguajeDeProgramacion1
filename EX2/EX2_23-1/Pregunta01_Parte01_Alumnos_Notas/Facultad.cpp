/* 
 * File:   Facultad.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 7 de julio de 2024, 11:56 PM
 */

#include "Facultad.hpp"
#include "Alumno.hpp"

using namespace std;

Facultad::Facultad() {
}

Facultad::Facultad(const Facultad& orig) {
}

Facultad::~Facultad() {
}

void Facultad::leerAlumnosNotas(const char * alumnosPreg01, const char * notasPreg01) {
    //lectura de archivos
    ifstream archAlumnos(alumnosPreg01, ios::in);
    if (not archAlumnos.is_open()) {
        cout << "ERROR: no se puede abrir el archivo " << alumnosPreg01 << endl;
        exit(1);
    }
    Nodo *nodo;
    Alumno alumno;
    while (!archAlumnos.eof()) {// mientras no acabe
        archAlumnos >> alumno;
        // vefifico
        if (this->alumnosxNotas.existeAlumno(alumno)) {
            continue;
        }
        nodo = new Nodo();
        nodo->insertarAlumno(alumno);
        this->alumnosxNotas.insertarOrdenado(nodo);
    }
    archAlumnos.close();
    ifstream archNota(notasPreg01, ios::in);
    if (not archNota.is_open()) {
        cout << "ERROR: no se puede abrir el archivo " << notasPreg01 << endl;
        exit(1);
    }
    Nota nota;
    int ciclo, codigo_alumno;
    char c;
    while (!archNota.eof()) {
        archNota >> ciclo >> c;
        archNota >> codigo_alumno;
        while (archNota >> nota) {
            nota.SetCiclo(ciclo);
            this->alumnosxNotas.insertarNota(codigo_alumno, nota);
        }
    }
}

void Facultad::imprimeAlumnosNotas(const char *nombreReporte) {
    ofstream archReporte(nombreReporte, ios::out);
    if (not archReporte.is_open()) {
        cout << "ERROR: no se puede abrir el archivo " << nombreReporte << endl;
        exit(1);
    }
    archReporte << left << fixed << setprecision(2) << endl;
    archReporte << setw(60) << "REPORTE DE NOTAS" << endl;
    archReporte << setfill('=') << setw(100) << "=" << endl;
    this->alumnosxNotas.imprimirReporte(archReporte);
}

