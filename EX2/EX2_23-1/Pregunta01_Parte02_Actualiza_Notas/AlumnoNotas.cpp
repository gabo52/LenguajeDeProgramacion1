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

void AlumnoNotas::actualizar(void){
    vector<Nota> cursos; // para poder almacenar los cursos
    char codigo_curso[10];
    for (int j = 0; j < notas.size(); j++)  {
        notas[j].GetCodigo_curso(codigo_curso);
        if(notas[j].GetVez() == 1){
            cursos.push_back(notas[j]);//guardamos el curso
            continue;
        }
        //en caso de ser bika o trika en algun curso
        int i = 0;
        for (i = 0; i < cursos.size(); i++) {
            char curso_eliminar[10];
            cursos[i].GetCodigo_curso(curso_eliminar);
            if(strcmp(codigo_curso,curso_eliminar) == 0) break;
        }
        cursos.erase(cursos.begin() + i);
        cursos.push_back(notas[j]);
    }
    this->notas.clear();//eliminamos todas las notas
    this->notas.assign(cursos.begin(),cursos.end());
    this->totalizar();
}

void AlumnoNotas::totalizar(void){
    double total_creditos = 0;
    double suma_notas_x_promedio = 0;
    for (int i = 0; i < this->notas.size(); i++) {
        total_creditos += notas[i].GetCreditos();
        suma_notas_x_promedio += notas[i].GetCalificacion() * notas[i].GetCreditos();
    }
    this->alumno.SetPromedio(suma_notas_x_promedio / total_creditos);
}