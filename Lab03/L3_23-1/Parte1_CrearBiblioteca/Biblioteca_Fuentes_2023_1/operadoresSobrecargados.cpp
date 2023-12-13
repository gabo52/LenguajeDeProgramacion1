#include "operadoresSobrecargados.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////LECTURA//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//INF263   Algoritmia   3.75   35030611   INGA_FLORES_CESAR_ADOLFO

bool operator>>(ifstream &input, struct StCurso& curso) {
    char codCurso[7], nomCurso[60], nomProfesor[60];
    double credito;
    int codProfesor;
    input >> codCurso;
    if (input.fail()) {
        input.clear();
        return false;
    }
    input >> nomCurso >> credito >> codProfesor >> nomProfesor;
    strcpy(curso.codigoDelCurso, codCurso);
    strcpy(curso.nombreDelCurso, nomCurso);
    strcpy(curso.nombreDelProfesor, nomProfesor);
    curso.creditos = credito;
    curso.codigoDelProfesor = codProfesor;
    curso.numeroDeAlumnos = 0;
    curso.ingresos = 0.0;
    return true;
}

bool operator>>(ifstream &input, struct StAlumno & alumno) {
    int semestre, codigo, escala, porcentaje;
    char nombre[60], modalidad, c;
    input >> semestre;
    if (input.fail()) {
        input.clear();
        return false;
    }
    input >> c >> codigo >> nombre >> modalidad;
    //informacion general
    alumno.semestre = semestre;
    alumno.codigo = codigo;
    strcpy(alumno.nombre, nombre);
    if (modalidad == 'G') { // caso cuando es presencial
        input >> escala;
        strcpy(alumno.modalidad, "PRESENCIAL");
    } else if (modalidad == 'V') { // caso cuando la modalidad es Virtual
        input >> c >> escala;
        strcpy(alumno.modalidad, "VIRTUAL");
    } else { // ultimo caso cuando es semi-presencial
        input >> porcentaje >> c >> escala;
        strcpy(alumno.modalidad, "SEMIPRESENCIAL");
        alumno.porcentaje = porcentaje;
    }
    alumno.escala = escala;
    alumno.numeroDeCursos = 0;
    alumno.costoTotal = 0.0;
    return true;
}

bool operator>>(ifstream &input, struct StRegistroDeMatricula &matricula) {
    char codCurso[7], c;
    int semestre, codAlumno;
    input >> codCurso;
    if (input.fail()) {
        input.clear();
        return false;
    }
    input >> semestre >> c >> codAlumno;
    strcpy(matricula.codigoDelCurso, codCurso);
    matricula.semestreDelAlumno = semestre;
    matricula.codigodelAlumno = codAlumno;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////AGREGACION//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void operator+=(struct StCurso *arregloCurso, const struct StCurso curso) {
    int i = 0;
    while (true) {
        if (strcmp(arregloCurso[i].codigoDelCurso, "XXXXXX") == 0) {
            break;
        }
        i++;
    }
    for (int j = 0; j < curso.numeroDeAlumnos; j++) {
        arregloCurso[i].alumnos[j] = curso.alumnos[j];
    }
    strcpy(arregloCurso[i].codigoDelCurso, curso.codigoDelCurso);
    strcpy(arregloCurso[i].nombreDelCurso, curso.nombreDelCurso);
    strcpy(arregloCurso[i].nombreDelProfesor, curso.nombreDelProfesor);
    arregloCurso[i].codigoDelProfesor = curso.codigoDelProfesor;
    arregloCurso[i].creditos = curso.creditos;
    arregloCurso[i].numeroDeAlumnos = curso.numeroDeAlumnos;
    arregloCurso[i].ingresos = curso.ingresos;
    strcpy(arregloCurso[++i].codigoDelCurso, "XXXXXX");
    
}

void operator+=(struct StAlumno *arregloAlumno, const struct StAlumno alumno) {
    int i = 0;
    for (i = 0; arregloAlumno[i].semestre != 0; i++);
    for (int j = 0; j < alumno.numeroDeCursos; j++) {
        arregloAlumno[i].cursos[j] = new char[strlen(alumno.cursos[j]) + 1];
        strcpy(arregloAlumno[i].cursos[j],alumno.cursos[j]);
    }
    arregloAlumno[i].semestre = alumno.semestre;
    arregloAlumno[i].codigo = alumno.codigo;
    strcpy(arregloAlumno[i].nombre, alumno.nombre);
    strcpy(arregloAlumno[i].modalidad, alumno.modalidad);
    arregloAlumno[i].escala = alumno.escala;
    if (strcmp(alumno.modalidad, "SEMIPRESENCIAL") == 0) {
        arregloAlumno[i].porcentaje = alumno.porcentaje;
    }
    arregloAlumno[i].numeroDeCursos = alumno.numeroDeCursos;
    arregloAlumno[i].costoTotal = alumno.costoTotal;
    arregloAlumno[++i].semestre = 0;
}

void operator*=(struct StCurso *arregloCurso, const struct StRegistroDeMatricula &matricula) {
    for (int i = 0; strcmp(arregloCurso[i].codigoDelCurso, "XXXXXX") != 0; i++) {
        if (strcmp(arregloCurso[i].codigoDelCurso, matricula.codigoDelCurso) == 0) {
            arregloCurso[i].alumnos[arregloCurso[i].numeroDeAlumnos] =
                    matricula.semestreDelAlumno * 10000 + matricula.codigodelAlumno;
            arregloCurso[i].numeroDeAlumnos++;
            break; // dejamos de buscar
        }
    }
}

void operator*=(struct StAlumno *arregloAlumno, const struct StRegistroDeMatricula &matricula) {
    for (int i = 0; arregloAlumno[i].semestre != 0; i++) {
        if (arregloAlumno[i].semestre == matricula.semestreDelAlumno
                && arregloAlumno[i].codigo == matricula.codigodelAlumno) {
            arregloAlumno[i].cursos[arregloAlumno[i].numeroDeCursos] =
                    new char[strlen(matricula.codigoDelCurso) + 1];
            strcpy(arregloAlumno[i].cursos[arregloAlumno[i].numeroDeCursos],
                    matricula.codigoDelCurso);
            arregloAlumno[i].numeroDeCursos++;
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////IMPRESION//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void operator<<(ofstream &output, const struct StCurso curso) {
    output << left << setprecision(2) << fixed;
    output << setw(18) << "CODIGO"
            << setw(55) << "NOMBRE"
            << setw(10) << "CREDITOS" << endl;
    output << setw(16) << curso.codigoDelCurso
            << setw(59) << curso.nombreDelCurso
            << setw(10) << curso.creditos << endl;
    output << "PROFESOR: " << curso.nombreDelProfesor
            << "[" << curso.codigoDelProfesor << "]" << endl;
    output << "Alumnos matriculados:" << endl;
    output << setw(15) << "Semestre" << "Código" << endl;
    for (int i = 0; i < curso.numeroDeAlumnos; i++) {
        output << " " << setw(15) << curso.alumnos[i] / 1000
                << curso.alumnos[i] % 10000 << endl;
    }
    output << "Numeros de alumnos: " << curso.numeroDeAlumnos << endl;
    output << "Total ingresado: " << curso.ingresos << endl;
}

void operator<<(ofstream&output, const struct StAlumno alumno) {
    output << left << setprecision(2) << fixed;
    output << setw(12) << "SEMESTRE"
            << setw(10) << "CODIGO"
            << setw(40) << "NOMBRE"
            << setw(30) << "MODALIDAD"<< "ESCALA" << endl;
    output << setw(12) << alumno.semestre
            << setw(10) << alumno.codigo
            << setw(40) << alumno.nombre;
    if (strcmp(alumno.modalidad,"SEMIPRESENCIAL") == 0) {
        output << alumno.modalidad << " CON " << alumno.porcentaje<< setw(9) << "%";
    }else{
        output <<setw(30) <<  alumno.modalidad;
    }
    output << alumno.escala << endl;
    output << "Codigos de cursos matriculados: \n";
    for (int i = 0; i < alumno.numeroDeCursos; i++) {
        output << setw(15) << alumno.cursos[i] << endl;
    }

}
