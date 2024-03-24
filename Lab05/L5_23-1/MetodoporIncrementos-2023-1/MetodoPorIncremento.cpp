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

void cargarCursos(const char *nombreArchivo, char ***&cursos_datos, int *&cursos_credito, char ****&cursos_alumnos,
                  double **&cursos_informacion_economica) {
    ifstream file;
    int cntCursos = 1;
    abrirArchivoLectura(file, nombreArchivo);
    while (true) {
        leerCurso(file, cursos_datos, cntCursos); // supondremos que esta bien xD
        leerCredito(file, cursos_credito, cntCursos);
        leerAlumnos(file, cursos_alumnos, cntCursos);
        calcularInformacionEconomica(cursos_informacion_economica, cursos_alumnos[cntCursos - 1], cntCursos,
                                     cursos_credito);
        cntCursos++;
        if (file.peek() == ',') break;
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
    } else if (cntCursos % INCREMENTO == 0) { // incrementamos la funcion
        incrementarCursos(cursos_datos, cntCursos);// para incrementar de 5 en 5
    }
    agregarCurso(cursos_datos[cntCursos - 1], codigoCurso, nombreCurso);//agregamos los valores
    delete[] codigoCurso;
    delete[] nombreCurso;
}

bool existeCurso(char ***&cursos_datos, const int cntCursos, const char *nombreCurso) {
    if (cntCursos == 1) return false; // no se agrego ningun curso
    for (int i = 0; i < cntCursos; ++i) {
        if (cursos_datos[i] != nullptr && compararCurso(cursos_datos[i], nombreCurso)) return true;
    }
    return false;
}

bool compararCurso(char **curso_datos, const char *nombreCurso) {
    return strcmp(curso_datos[1], nombreCurso) == 0;
}

void incrementarCursos(char ***&cursos_datos, const int cntCursos) {
    char ***new_cursos_datos = new char **[cntCursos + INCREMENTO]();
    for (int i = 0; i < cntCursos; ++i) {
        new_cursos_datos[i] = cursos_datos[i];
    }
    delete[] cursos_datos;
    cursos_datos = new_cursos_datos;
}

void agregarCurso(char **&cursos_datos, const char *codigoCurso, const char *nombreCurso) {
    cursos_datos = new char *[2]();//siempre son 2
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
    if (cntCursos == 1) {
        cursos_credito = new int[INCREMENTO]();
    } else if (cntCursos % INCREMENTO == 0) {
        int *new_cursos_credito = new int[cntCursos + INCREMENTO]();
        for (int i = 0; i < cntCursos; ++i) { // copiamos los valores
            new_cursos_credito[i] = cursos_credito[i];
        }
        delete[] cursos_credito;
        cursos_credito = new_cursos_credito;
    }
    file >> cursos_credito[cntCursos - 1] >> c;//leemos el codigo y la coma
}

void leerAlumnos(ifstream &file, char ****&cursos_alumno, const int cntCurso) {
    char *nombreAlumno = new char[MAX_NOMBRE_ALUMNO];
    char *codigoEscalaStr = new char[MAX_CODIGO_ESCALA];
    double codigoEscala;
    int cntAlumnos = 1;
    char c;
    incrementarAlumnos(cursos_alumno, cntCurso);
    do {
        file.getline(nombreAlumno, MAX_NOMBRE_ALUMNO, ','); // leemos el nombre del alumno
        file >> codigoEscala; // leemos el codigo mas escala
        sprintf(codigoEscalaStr, "%.1f", codigoEscala);//convertimos el codigo a string
        agregarAlumno(cursos_alumno[cntCurso - 1], cntAlumnos, nombreAlumno, codigoEscalaStr);
        cntAlumnos++;
    } while (file.get() != '\n'); // leemos la coma y verificamos si acabaron los alumnos
    delete[] nombreAlumno;
    delete[] codigoEscalaStr;
}

void incrementarAlumnos(char ****&cursos_alumno, int cntCurso) {
    if (cntCurso == 1) {
        cursos_alumno = new char ***[INCREMENTO]();
    } else if (cntCurso % 5 == 0) {
        char ****nuevo_curso_alumno = new char ***[INCREMENTO + cntCurso]();
        for (int i = 0; i < cntCurso; ++i) {
            nuevo_curso_alumno[i] = cursos_alumno[i];
        }
        delete[] cursos_alumno;
        cursos_alumno = nuevo_curso_alumno;
    }
}

void agregarAlumno(char ***&cursos_alumno, int cntAlumnos, const char *nombreAlumno, const char *codigoEscalaStr) {
    if (cntAlumnos == 1) {
        cursos_alumno = new char **[INCREMENTO]();
    } else if (cntAlumnos % 5 == 0) {
        char ***nuevos_curso_alumnos = new char **[INCREMENTO + cntAlumnos]();
        for (int i = 0; i < cntAlumnos; ++i) {
            nuevos_curso_alumnos[i] = cursos_alumno[i];
        }
        delete[]cursos_alumno;
        cursos_alumno = nuevos_curso_alumnos;
    }
    insertarAlumno(cursos_alumno[cntAlumnos - 1], nombreAlumno, codigoEscalaStr);
}

void insertarAlumno(char **&cursos_alumno, const char *nombreAlumno, const char *codigoEscalaStr) {
    cursos_alumno = new char *[2](); // siempre son 2
    cursos_alumno[0] = new char[MAX_CODIGO_ESCALA]();
    cursos_alumno[1] = new char[strlen(nombreAlumno) + 1]();
    strcpy(cursos_alumno[0], codigoEscalaStr); // guardamos el codigo
    strcpy(cursos_alumno[1], nombreAlumno); // guardamos el nombre
}

void calcularInformacionEconomica(double **&cursos_informacion_economica, char ***&cursos_alumnos, int cntCursos,
                                  int *creditos) {
    incrementarInformacionEconomica(cursos_informacion_economica, cntCursos);
    double *informacion = new double[2]();
    int i = 0;
    while (cursos_alumnos[i] != nullptr) {
        int escala = obtenerEscalaAlumno(cursos_alumnos[i]);
        switch (escala) {
            case 1:
                informacion[1] += ESCALA1 * creditos[cntCursos - 1];
                break;
            case 2:
                informacion[1] += ESCALA2 * creditos[cntCursos - 1];
                break;
            case 3:
                informacion[1] += ESCALA3 * creditos[cntCursos - 1];
                break;
            case 4:
                informacion[1] += ESCALA4 * creditos[cntCursos - 1];
                break;
            case 5:
                informacion[1] += ESCALA5 * creditos[cntCursos - 1];
                break;
        }
        i++;
    }
    informacion[0] = i;
    cursos_informacion_economica[cntCursos - 1] = informacion;
}

void incrementarInformacionEconomica(double **&cursos_informacion_economica, int cntCursos) {
    if (cntCursos == 1) {
        cursos_informacion_economica = new double *[INCREMENTO];
    } else if (cntCursos % INCREMENTO == 0) {
        double **new_cursos_informacion_economica = new double *[INCREMENTO + cntCursos];
        for (int i = 0; i < cntCursos; ++i) {
            new_cursos_informacion_economica[i] = cursos_informacion_economica[i];
        }
        delete[]cursos_informacion_economica;
        cursos_informacion_economica = new_cursos_informacion_economica;
    }
}

int obtenerEscalaAlumno(char **cursos_alumnos) {
    char codigo[MAX_CODIGO_ESCALA];
    strcpy(codigo, cursos_alumnos[0]);
    int cod = codigo[strlen(codigo) - 1] - '0';
    return cod;
}

void pruebaCursos(const char *nombreArchivo, char ***cursos_datos, int *cursos_credito, char ****cursos_alumnos,
                  double **cursos_informacion_economica) {
    ofstream file;
    abrirArchivoEscritura(file, nombreArchivo);
    for (int i = 0; cursos_datos[i] != nullptr; ++i) {
        file << setw(MAX_LINEA) << setfill('=') << '=' << endl
             << left << setw(15) << setfill(' ') << "CODIGO"
             << setw(50) << "Nombre curso"
             << setw(10) << "Credito" << endl;
        imprimirCodCurso(file, cursos_datos[i], cursos_credito[i]);
        imprimirAlumnos(file, cursos_alumnos[i]);
        imprimirInformacionEconomica(file, cursos_informacion_economica[i]);
    }
}

void imprimirCodCurso(ofstream &file, char **cursos_datos, int credito) {
    file << setw(15) << setfill(' ') << cursos_datos[0]
         << setw(50) << cursos_datos[1]
         << setw(10) << credito << endl;
}

void imprimirAlumnos(ofstream &file, char ***cursos_alumnos) {
    file << setw(MAX_LINEA) << setfill('-') << '-' << endl
         << setw(50) << setfill(' ') << "NOMBRE ALUMNO" << "CODIGO.ESCALA" << endl
         << setw(MAX_LINEA) << setfill('-') << '-' << endl;
    for (int i = 0; cursos_alumnos[i] != nullptr; ++i) {
        imprimirAlumno(file, cursos_alumnos[i]);
    }
}

void imprimirAlumno(ofstream &file, char **cursos_alumnos) {
    file << setw(50) << setfill(' ') << cursos_alumnos[1]
         << cursos_alumnos[0] << endl;
}

void imprimirInformacionEconomica(ofstream &file, double *cursos_informacion_economica) {
    file << fixed << setprecision(2);
    file << setw(MAX_LINEA) << setfill('=') << '=' << endl
         << left << "Cantidad de Alumnos: " << cursos_informacion_economica[0]
         << right << setw(20) << setfill(' ') << ' ' << "Total Recaudado: " << cursos_informacion_economica[1] << endl;
}


void reporteDeAlumnosPorCurso(const char *nombreArchivo, char ***cursos_datos, int *cursos_credito,
                              char ****cursos_alumnos, double **cursos_informacion_economica) {
    ofstream file;
    abrirArchivoEscritura(file, nombreArchivo);
    file << fixed << setprecision(2);
    file << setw(35) << setfill(' ') << ' ' << "CURSOS EN EL CICLO 2023-1" << endl;
    int i = 0;
    while (cursos_datos[i] != nullptr) {
        imprimirCabecerReporte(file, cursos_credito[i]);
        imprimirNameCodCurso(file, cursos_datos[i]);
        imprimirAlumnosReporte(file, cursos_alumnos[i], cursos_informacion_economica[i], cursos_credito[i]);
        imprimirTotalReporte(file, cursos_informacion_economica[i]);
        i++;
    }
    file.close();
}

void imprimirCabecerReporte(ofstream &file, int credito) {
    file << setw(MAX_LINEA) << setfill('=') << '=' << endl
         << "RELACION DE ALUMNOS POR CURSO" << endl
         << setw(MAX_LINEA) << setfill('=') << '=' << endl
         << left << setw(15) << setfill(' ') << "CODIGO"
         << setw(50) << "NOMBRE" << "Credito:     " << credito << endl;
}

void imprimirNameCodCurso(ofstream &file, char **cursos_datos) {
    file << setw(15) << cursos_datos[0] << setw(50) << cursos_datos[1] << endl
         << setw(MAX_LINEA) << setfill('-') << '-' << endl
         << "RELACION DE ALUMNOS MATRICULADOS:" << endl
         << setw(MAX_LINEA) << setfill('-') << '-' << endl
         << "          CODIGO         " << setw(40) << setfill(' ') << "NOMBRE" << "Pago Total" << endl
         << setw(MAX_LINEA) << setfill('-') << '-' << endl;
}

void
imprimirAlumnosReporte(ofstream &file, char ***cursos_alumnos, double *cursos_informacion_economica, int credito) {
    int cntAlumnos = static_cast<int>(cursos_informacion_economica[0]);
    char *s;
    int codAlumno;
    double pagoAlumno;
    for (int i = 0; i < cntAlumnos; ++i) {
        codAlumno = obtenerCodigoAlumno(cursos_alumnos[i]);
        s = obtenerNombreAlumno(cursos_alumnos[i]);
        pagoAlumno = obtenerPagoAlumno(cursos_alumnos[i], credito);
        file << "    " << right << setw(2) << setfill('0') << (i + 1) << "    "
             << left << setw(10) << setfill(' ') << codAlumno << "     " << setw(40) << s << pagoAlumno << endl;
    }
    file << setw(MAX_LINEA) << setfill('-') << '-' << endl;

}

void imprimirTotalReporte(ofstream &file, double *cursos_informacion_economica) {
    file << setw(25) << setfill(' ') << ' '
         << left << setw(40) << "TOTAL:" << cursos_informacion_economica[1] << endl;
}

int obtenerCodigoAlumno(char **cursos_alumnos) {
    return atoi(cursos_alumnos[0]);
}

char *obtenerNombreAlumno(char **cursos_alumnos) {
    return cursos_alumnos[1];
}

double obtenerPagoAlumno(char **cursos_alumnos, int credito) {
    int escala = obtenerEscalaAlumno(cursos_alumnos);
    double pago = 0;
    switch (escala) {
        case 1:
            pago = ESCALA1 * credito;
            break;
        case 2:
            pago = ESCALA2 * credito;
            break;
        case 3:
            pago = ESCALA3 * credito;
            break;
        case 4:
            pago = ESCALA4 * credito;
            break;
        case 5:
            pago = ESCALA5 * credito;
            break;
    }
    return pago;
}
