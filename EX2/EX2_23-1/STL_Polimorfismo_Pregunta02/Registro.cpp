/* 
 * File:   Registro.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 8 de julio de 2024, 05:54 PM
 */

#include "Registro.hpp"
#include "CursoAlumno.hpp"
using namespace std;

Registro::Registro() {
}

Registro::Registro(const Registro& orig) {
}

Registro::~Registro() {
}

void Registro::carga(void) {
    ifstream file("registronotas.csv", ios::in);
    if (not file.is_open()) {
        cout << "ERROR: no se puede abrir el archivo registronotas.csv" << endl;
        exit(1);
    }
    Nota nota;
    while (true) {
        nota.leernota(file);
        if (file.eof()) break;
        this->vregistro.push_back(nota);
    }
}
// esta funcion tendria que ir en el HPP

bool Registro::ordenarRegistro(class Nota &a, class Nota &b) {
    // primero por el codigo del alumno
    if (a.GetCodigoAlumno() != b.GetCodigoAlumno())
        return a.GetCodigoAlumno() < b.GetCodigoAlumno();
    // segundo por el codigo del curso
    char cursoA[10], cursoB[10];
    a.GetCodcurAlumno(cursoA);
    b.GetCodcurAlumno(cursoB);
    if (strcmp(cursoA, cursoB) != 0) return strcmp(cursoA, cursoB) == -1;
    // tercero ordenamos por ciclo
    return a.GetCicloAlumno() < b.GetCicloAlumno();
}

void Registro::procesa(void) {
    sort(this->vregistro.begin(), this->vregistro.end(), ordenarRegistro);

    int codigo_alumno, nuevo_codigo_alumno;
    char curso[10], nuevo_curso[10];
    codigo_alumno = this->vregistro[0].GetCodigoAlumno();
    this->vregistro[0].GetCodcurAlumno(curso);
    int vez = 1;
    for (int i = 1; i < this->vregistro.size(); i++) {
        nuevo_codigo_alumno = this->vregistro[i].GetCodigoAlumno();
        //trabajamos el mismo alumno
        if (codigo_alumno == nuevo_codigo_alumno) {
            this->vregistro[i].GetCodcurAlumno(nuevo_curso);
            // verifcamos si seguimos analizando el mismo curso
            if (strcmp(curso, nuevo_curso) == 0) {
                vez++;
            } else {
                vez = 1;
                strcpy(curso, nuevo_curso);
                //                this->vregistro[i].SetVez(vez);
            }
            this->vregistro[i].SetVez(vez);
        } else {
            codigo_alumno = nuevo_codigo_alumno;
            vez = 1;
            this->vregistro[i].SetVez(vez);
            this->vregistro[i].GetCodcurAlumno(curso);
        }
    }
}

void Registro::muestra(void) {
    ofstream file("registroNotas.txt", ios::out);
    if (not file.is_open()) {
        cout << "ERROR: No se puede abrir el archivo registroNotas.txt" << endl;
        exit(1);
    }
    file << setw(70) << "REGISTRO DE NOTAS" << endl;
    file << setw(120) << setfill('=') << "=" << endl;
    file << left << setfill(' ') << setw(15) << "Codigo"
            << setw(15) << "Curso"
            << setw(15) << "Ciclo"
            << setw(15) << "Nota"
            << setw(10) << "Vez"
            << setw(15) << "Creditos"
            << "Codigo de Acceso" << endl;
    file << setw(120) << setfill('=') << "=" << endl;
    for (int i = 0; i < this->vregistro.size(); i++) {
        this->vregistro[i].imprime(file);
    }

}

