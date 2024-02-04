#include "MetodoPorIncremento.h"

//funcionesDeApertura
void abrirArchivoLectura(ifstream &file, const char *nombre) {
    file.open(nombre, ios::in);
    if (!file) {
        cerr << "ERROR: no se pudo abrir el archivo: " << nombre << ", para su lectura." << endl;
        exit(1);
    }
}

void abrirArchivoEscritura(ofstream &file, const char *nombre) {
    file.open(nombre, ios::out);
    if (!file) {
        cerr << "ERROR: no se pudo abrir el archivo: " << nombre << ", para su escritura." << endl;
        exit(1);
    }
}

void cargarCursos(const char *nombreArchivo, char ***&cursos_datos, int *&cursos_credito, char ***&cursos_alumnos,
                  double **&cursos_informacion_economica) {
    ifstream file;
    int cntCursos = 1;
    abrirArchivoLectura(file, nombreArchivo);
    while (!file.eof()) {
        leerCurso(file, cursos_datos, cntCursos); // supondremos que esta bien xD
        leerCredito(file, cursos_credito, cntCursos);
        leerAlumnos(file, cursos_alumnos, cntCursos);
        cntCursos++;
    }
}

void leerCurso(ifstream &file, char ***&cursos_datos, int &cntCursos) {
    char *codigoCurso = new char[MAX_CODIGO_CURSO], *nombreCurso = new char[MAX_NOMBRE_CURSO];
    file.getline(codigoCurso, MAX_CODIGO_CURSO, ','); // leemos el codigo del curso
    file.getline(nombreCurso, MAX_NOMBRE_CURSO, ','); // leemos el nombre del curso
    if (existeCurso(cursos_datos, cntCursos, nombreCurso)) {
        cerr << "El curso: " << nombreCurso << ", ya existe" << endl;
        exit(1);
    }
    if (cntCursos == 1) {//recien se va a empezar a agregar cursos
        cursos_datos = new char **[INCREMENTO](); // se va a incrementar de 5 en 5
        agregarCurso(cursos_datos[0], codigoCurso, nombreCurso);//agregamos los valores
    } else if (cntCursos % INCREMENTO == 0) { // incrementamos la funcion
        incrementarCursos(cursos_datos, cntCursos);// para incrementar de 5 en 5
        agregarCurso(cursos_datos[cntCursos], codigoCurso, nombreCurso);//agregamos los valores
    }
    delete[] codigoCurso;
    delete[] nombreCurso;
}

bool existeCurso(char ***cursos_datos, const int cntCursos, const char *nombreCurso) {
    if (cntCursos == 0) return false; // no se agrego ningun curso
    for (int i = 0; i < cntCursos; ++i) {
        if (compararCurso(cursos_datos[i], nombreCurso)) return true;
    }
    return false;
}

bool compararCurso(char **curso_datos, const char *nombreCurso) {
    return strcmp(curso_datos[0], nombreCurso);
}

void incrementarCursos(char ***&cursos_datos, const int cntCursos)() {
    char ***new_cursos_datos = new char **[cntCursos + INCREMENTO];
    for (int i = 0; i < cntCursos; ++i) {
        new_cursos_datos[i] = cursos_datos[i];
    }
    delete[] cursos_datos;
    cursos_datos = new_cursos_datos;
}

void agregarCurso(char **&cursos_datos, const char *codigoCurso, const char *nombreCurso) {
    cursos_datos = new char *[2];//siempre son 2
    agregarCodigoCurso(cursos_datos[0], codigoCurso);
    agregarNombreCurso(cursos_datos[1], nombreCurso);
}

void agregarCodigoCurso(char *&cursos_datos, const char *codigoCurso) {
    cursos_datos = new char[MAX_CODIGO_CURSO];
    strcpy(cursos_datos, codigoCurso);
}

void agregarNombreCurso(char *&cursos_datos, const char *nombreCurso) {
    cursos_datos = new char[strlen(nombreCurso) + 1];
    strcpy(cursos_datos, nombreCurso);
}

void leerCredito(ifstream &file, int *&cursos_credito, int cntCursos) {
    char c;
    if (cntCursos == 0) {
        cursos_credito = new int[INCREMENTO];
        file >> cursos_credito[0] >> c;
    } else if (cntCursos % INCREMENTO == 0) {
        int *new_cursos_credito = new int[cntCursos + INCREMENTO]();
        for (int i = 0; i < cntCursos; ++i) { // copiamos los valores
            new_cursos_credito[i] = cursos_credito[i];
        }
        file >> cursos_credito[cntCursos] >> c;
    }
}

void leerAlumnos(ifstream &file, char ***&cursos_alumno, const int cntCurso) {
    char *nombreAlumno = new char[MAX_NOMBRE_ALUMNO];
    char *codigoEscalaStr = new char[MAX_CODIGO_ESCALA];
    double codigoEscala;
    int cntAlumnos = 1;
    incrementarAlumnos(cursos_alumno, cntCurso);
    do {
        file.getline(nombreAlumno, MAX_NOMBRE_ALUMNO, ','); // leemos el nombre del alumno
        file >> codigoEscala; // leemos el codigo mas escala
        sprintf(codigoEscalaStr, "%f", codigoEscala);//convertimos el codigo a string
        agregarAlumno(cursos_alumno[cntCurso - 1], cntAlumnos, nombreAlumno, codigoEscalaStr);
        cntAlumnos++;
    } while (file.get() != '\n'); // leemos la coma y verificamos si acabaron los alumnos
    delete[] nombreAlumno;
    delete[] codigoEscalaStr;
}

void incrementarAlumnos(char ***&cursos_alumnos, int cntCurso) {
    if (cntCurso == 1) {
        cursos_alumnos = new char **[INCREMENTO]();
    } else if (cntCurso % 5 == 0) {
        char ***nuevo_cursos_alumnos = new char **[INCREMENTO + cntCurso]();
        for (int i = 0; i < cntCurso; ++i) {
            nuevo_cursos_alumnos[i] = cursos_alumnos[i];
        }
        delete[] cursos_alumnos;
        cursos_alumnos = nuevo_cursos_alumnos;
    }
}

// funcion mal implementada
void agregarAlumno(char **&cursos_alumno, int cntAlumnos, char *nombreAlumno, char *codigoEscalaStr) {
    if (cntAlumnos == 1) {
        cursos_alumno = new char *[INCREMENTO]();// se incrementa de forma normal
    } else if (cntAlumnos % 5 == 0) {
        char **new_cursos_alumno = new char *[INCREMENTO + cntAlumnos](); //  siempre son 2
        for (int i = 0; i < cntAlumnos; ++i) {
            new_cursos_alumno[i] = cursos_alumno[i];
        }
        delete[] cursos_alumno;
        cursos_alumno = new_cursos_alumno;
    }
    insertarAlumno(cursos_alumno, nombreAlumno, codigoEscalaStr);
}


void pruebaCursos(const char *nombreArchivo, char ***cursos_datos, int *cursos_credito, char ***cursos_alumnos,
                  double **cursos_informacion_economica) {
    ofstream file;
    abrirArchivoEscritura(file, nombreArchivo);
    for (int i = 0; cursos_datos[i] != nullptr; ++i) {
        file << left << setw(10) << setfill(' ') << "Codigo"
             << setw(50) << "Nombre Curso"
             << setw(10) << "Credito" << endl;
        imprimirCodNombreCurso(file, cursos_datos[i], cursos_credito[i]);
        file << setw(MAX_LINEA) << setfill('-') << '-' << endl;
        imprimirAlumnos(file, cursos_alumnos[i]);
        file << setw(MAX_LINEA) << setfill('=') << '=' << endl;
    }
}

void imprimirCodNombreCurso(ofstream &file, char **codNombreCurso, int credito) {
    file << setw(10) << codNombreCurso[0]
         << setw(50) << codNombreCurso[1]
         << setw(10) << credito << endl;
}

void imprimirAlumnos(ofstream &file, char **cursos_alumnos) {
    for (int j = 0; cursos_alumnos[j] != nullptr; ++j) {
        imprimirNombre(file, cursos_alumnos[j]);
        imprimirCodigo(file, cursos_alumnos[j]);
    }
}

void imprimirNombre(file, char *cursos_alumnos) {

}

//
//void reporteDeAlumnosPorCurso(const char *nombreArchivo, char **cursos_datos, int *cursos_credito,
//                              char ***cursos_alumnos, double **cursos_informacion_economica) {
//
//}