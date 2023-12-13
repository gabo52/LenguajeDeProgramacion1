#include "funciones.hpp"

void leerCursos(struct StCurso *arregloCurso) {
    struct StCurso curso;
    ifstream archCurso;
    AperturaDeUnArchivoDeTextosParaLeer(archCurso, "Cursos.txt");
    strcpy(arregloCurso[0].codigoDelCurso, "XXXXXX");
    while (true) {
        if (!(archCurso >> curso)) {
            break;
        }
        arregloCurso += curso;
    }
}

void leerAlumnos(struct StAlumno *arregloAlumno) {
    struct StAlumno alumno;
    ifstream archAlumno;
    AperturaDeUnArchivoDeTextosParaLeer(archAlumno, "Alumnos.txt");
    arregloAlumno[0].semestre = 0;
    while (true) {
        if (!(archAlumno >> alumno)) {
            break;
        }
        arregloAlumno += alumno;
    }
}

void leerMatricula(struct StCurso *arregloCurso, struct StAlumno *arregloAlumno) {
    struct StRegistroDeMatricula matricula;
    ifstream archMatricula;
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    while (true) {
        if (!(archMatricula >> matricula)) {
            break;
        }
        arregloAlumno *= matricula;
        arregloCurso *= matricula;
    }
}

void calcularIngresosYCostos(struct StCurso *arregloCurso, struct StAlumno *arregloAlumno) {
    double escalas[5],creditoCurso;
    llenarEscalas(escalas);
    int escalaAlumno;
    // calculo del ingreso
    for (int i = 0; strcmp(arregloCurso[i].codigoDelCurso,"XXXXXX") != 0; i++) {
        for (int j = 0; j < arregloCurso[i].numeroDeAlumnos; j++) {
            escalaAlumno = escalaDelAlumno(arregloAlumno,arregloCurso[i].alumnos[j]);
            if (escalaAlumno != -1) {
                arregloCurso[i].ingresos += escalas[escalaAlumno - 1] * arregloCurso[i].creditos;
            }
        }
    }
    // calculo de costo total
    for (int i = 0; arregloAlumno[i].semestre != 0; i++) {
        for (int j = 0;j <  arregloAlumno[i].numeroDeCursos; j++) {
            creditoCurso = buscarCreditoDelCurso(arregloCurso,arregloAlumno[i].cursos[j]);
            arregloAlumno[i].costoTotal += creditoCurso * arregloAlumno[i].escala;
        }
    }
}

void llenarEscalas(double *arregloEscala) {
    ifstream archEscalas;
    AperturaDeUnArchivoDeTextosParaLeer(archEscalas, "Escalas.txt");
    char c;
    int escala;
    double costo;
    for (int i = 0; !(archEscalas.eof()); i++) {
        archEscalas >> c >> escala >> costo;
        arregloEscala[escala - 1] = costo;
    }
}

int escalaDelAlumno(struct StAlumno *arregloAlumno,int codigoAlumno){
    int semestre = codigoAlumno / 10000;
    int codigo = codigoAlumno % 10000;
    for (int i = 0;arregloAlumno[i].semestre != 0 ; i++) {
        if (arregloAlumno[i].semestre == semestre and 
                arregloAlumno[i].codigo == codigo) {
            return arregloAlumno[i].escala;
        }
    }
    return -1;
}

double buscarCreditoDelCurso(struct StCurso *arregloCurso,char *codigoCurso){
    for (int i = 0; strcmp(arregloCurso[i].codigoDelCurso,"XXXXXX") != 0; i++) {
        if (strcmp(arregloCurso[i].codigoDelCurso,codigoCurso) == 0) {
            return arregloCurso[i].creditos;
        }
    }
}

void realizarReporte(struct StCurso *arregloCurso, struct StAlumno *arregloAlumno){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    archReporte << "REPORTE DE CURSOS\n";
    for (int i = 0; strcmp(arregloCurso[i].codigoDelCurso,"XXXXXX") != 0; i++) {
        archReporte << arregloCurso[i];
    }
    archReporte << "REPORTE DE ALUMNOS\n";
    for (int i = 0; arregloAlumno[i].semestre != 0; i++) {
        archReporte << arregloAlumno[i];
    }
}
