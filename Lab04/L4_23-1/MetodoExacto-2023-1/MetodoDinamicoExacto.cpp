#include "MetodoDinamicoExacto.h"

// Funciones de apertura de archivo

void abrirArchivoLectura(ifstream &file, const char *nombre_archivo) {
    file.open(nombre_archivo, ios::in);
    if (!file) {
        cerr << "No se pudo abrir el archivo para su lectura: " << nombre_archivo << endl;
        exit(1);
    }
}

void abrirArchivoEscritura(ofstream &file, const char *nombre_archivo) {
    file.open(nombre_archivo, ios::out);
    if (!file) {
        cerr << "No se puedo abrir el archivo para su escritura: " << nombre_archivo << endl;
        exit(1);
    }
}

//5802,MINAYA AMEZQUITA RHONY JAIME,5
//2050,LOYOLA HIJAR NICOLAS OSCAR,V,4
//7660,CHANG ARGUEDAS HENRY ANTONIO,S,25,4

void lecturaAlumnos(const char *nombre_archivo, int *&alumno_Codigo, char **&alumno_Nombre,
                    char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala) {
    ifstream file;
    abrirArchivoLectura(file, nombre_archivo);
    inicializarValoresAlumno(MAX_ALUMNO, alumno_Codigo, alumno_Nombre, alumno_Modalidad, alumno_Porcentaje,
                             alumno_Escala);
    char c; // auxiliar para leer la coma
    int i = 0;
    while (!file.eof()) {
        alumno_Nombre[i] = new char[50];
        file >> alumno_Codigo[i] >> c; //guardamos codigo
        file.getline(alumno_Nombre[i], 50, ','); //leemos el nombre
        file >> alumno_Modalidad[i];
        funcionLeerModalidad(file, alumno_Modalidad[i], alumno_Escala[i], alumno_Porcentaje[i]);
        i++;
    }
    recorteLecturaAlumno(i, alumno_Codigo, alumno_Nombre, alumno_Modalidad, alumno_Porcentaje, alumno_Escala);
    file.close();
}

void funcionLeerModalidad(ifstream &file, char &modalidad, int &escala, int &porcentaje) {
    char c;
    switch (modalidad) {
        case 'V'://modalidad virtual
            file >> c >> escala; //leemos la escala
            porcentaje = 0;
            break;
        case 'S'://modalidad semi-presencial
            file >> c >> porcentaje >> c >> escala;
            break;
        default://modalidad presencial
            escala = modalidad - '0'; //conseguimos el numero
            modalidad = 'P';
            porcentaje = 0;
            break;
    }
}

void recorteLecturaAlumno(int cnt, int *&alumno_Codigo, char **&alumno_Nombre,
                          char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala) {
    int *Codigo, *Porcentaje, *Escala;
    char *Modalidad, **Nombre;
    inicializarValoresAlumno(cnt, Codigo, Nombre, Modalidad, Porcentaje, Escala);
    for (int i = 0; i < cnt; i++) {
        Codigo[i] = alumno_Codigo[i];
        Porcentaje[i] = alumno_Porcentaje[i];
        Escala[i] = alumno_Escala[i];
        Modalidad[i] = alumno_Modalidad[i];
        Nombre[i] = new char[strlen(alumno_Nombre[i]) + 1];
        strcpy(Nombre[i], alumno_Nombre[i]);
        delete[]alumno_Nombre[i];
    }
    borrarValoresAlumno(alumno_Codigo, alumno_Nombre, alumno_Modalidad, alumno_Porcentaje, alumno_Escala);
    alumno_Codigo = Codigo;
    alumno_Nombre = Nombre;
    alumno_Modalidad = Modalidad;
    alumno_Porcentaje = Porcentaje;
    alumno_Escala = Escala;
}

void inicializarValoresAlumno(int cnt, int *&alumno_Codigo, char **&alumno_Nombre,
                              char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala) {
    alumno_Codigo = new int[cnt]();
    alumno_Nombre = new char *[cnt]();
    alumno_Modalidad = new char[cnt]();
    alumno_Porcentaje = new int[cnt]();
    alumno_Escala = new int[cnt]();
}

void borrarValoresAlumno(int *&alumno_Codigo, char **&alumno_Nombre,
                         char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala) {
    delete[]alumno_Codigo;
    delete[]alumno_Nombre;
    delete[]alumno_Modalidad;
    delete[]alumno_Porcentaje;
    delete[]alumno_Escala;
}

void pruebaLecturaAlumnos(const char *nombre_archivo, int *alumno_Codigo, char **alumno_Nombre,
                          char *alumno_Modalidad, int *alumno_Porcentaje, int *alumno_Escala) {
    ofstream file;
    abrirArchivoEscritura(file, nombre_archivo);
    file << left;
    file << setw(20) << "Codigo"
         << setw(25) << "Nombre"
         << setw(15) << "Modalidad"
         << setw(15) << "Porcentaje"
         << setw(15) << "Escala" << endl;
    for (int i = 0; alumno_Codigo[i] != 0; i++) {
        file << setw(10) << alumno_Codigo[i]
             << setw(40) << alumno_Nombre[i]
             << setw(15) << alumno_Modalidad[i]
             << setw(10) << alumno_Porcentaje[i]
             << setw(15) << alumno_Escala[i] << endl;
    }
}
// Funciones para la lectura de Cursos

//8072,Aplicaciones de las Ciencias de la Computacion,3.5
//6995,Lenguaje de Programacion 1,5

void lecturaCursos(const char *nombre_archivo, int *alumno_Codigo, int *alumno_Escala,
                   char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos) {
    ifstream file;
    abrirArchivoLectura(file, nombre_archivo);
    inicializarValoresCursos(MAX_CURSO, curso_Nombre, curso_Credito, curso_Alumnos);
    char *curso = new char[50], c; // para poder leer el curso del archivo
    int codigo, i = 0;
    double credito;
    while (!file.eof()) { // mientras no se llega al fin del archivo
        file >> codigo >> c; // leemos el codigo
        file.getline(curso, 50, ','); // leemos el curso
        file >> credito; // leemos el creditaje del curso
        agregarCurso(curso, credito, curso_Nombre, curso_Credito, curso_Alumnos);
        agregarAlumno(codigo, alumno_Codigo, alumno_Escala, curso_Alumnos, curso, curso_Nombre);
        i++;
    }
    file.close(); // cerramos el archivo
}

void inicializarValoresCursos(const int cnt, char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos) {
    curso_Nombre = new char *[cnt]();
    curso_Credito = new double[cnt]();
    curso_Alumnos = new int *[cnt]();
}

void agregarCurso(const char *curso, double credito, char **&curso_Nombre, double *curso_Credito,
                  int **&curso_Alumnos) {
    int i = 0;
    while (true) {
        if (curso_Nombre[i] == nullptr) break; // El curso no fue agregado
        if (strcmp(curso, curso_Nombre[i]) == 0) {//el curso ya fue agregado
            return;
        }
        i++;
    }
    //agregamos el curso
    curso_Nombre[i] = new char[strlen(curso) + 1];
    strcpy(curso_Nombre[i], curso);
    curso_Credito[i] = credito;
    curso_Alumnos[i] = new int[MAX_ALUMNO_CURSO]();
}

void agregarAlumno(int codigo, int *alumno_Codigo, int *alumno_Escala, int **&curso_Alumnos,
                   const char *curso, char **curso_nombre) {
    int i = 0, j = 0;
    while (alumno_Codigo[i] != codigo) i++;//encontramos al alumno
    while (strcmp(curso, curso_nombre[j]) != 0) j++;//encontramos el curso
    insertarAlumno(curso_Alumnos[j], alumno_Codigo[i], alumno_Escala[i]);
}

void insertarAlumno(int *&curso_Alumnos, int codigo, int escala) {
    int i = 0;
    while (curso_Alumnos[i] != 0) i += 2;
    curso_Alumnos[i] = codigo;
    curso_Alumnos[i + 1] = escala;
}

void pruebaDeLecturaCursos(const char *nombre_archivo, char **curso_Nombre, double *curso_Credito,
                           int **curso_Alumnos) {
    ofstream file;
    abrirArchivoEscritura(file, nombre_archivo);
    for (int i = 0; curso_Nombre[i] != nullptr; i++) {
        file << setw(50) << setfill('=') << "=" << endl
             << "Curso: " << curso_Nombre[i] << endl
             << "Credito: " << curso_Credito[i] << endl
             << setw(50) << "=" << endl << setfill(' ')
             << "Alumnos: " << endl;
        imprimirAlumno(file, curso_Alumnos[i]);
    }
}

void imprimirAlumno(ofstream &file, int *curso_Alumnos) {
    for (int i = 0; curso_Alumnos[i] != 0; i += 2) {
        file << "Codigo: " << left << setw(20) << curso_Alumnos[i]
             << "Escala: " << curso_Alumnos[i + 1] << endl;
    }
}

void reporteDeRecaudacionPorModalidad(const char *nombre_archivo, int *alumno_Codigo, char *alumno_Modalidad,
                                      int *alumno_Porcentaje, char **alumno_Nombre, char **curso_Nombre,
                                      double *curso_Credito, int **curso_Alumnos) {
    //variables
    ofstream file;
    double *pagoTotal = new double[3]();
    abrirArchivoEscritura(file, nombre_archivo);
    file << setw(75) << "ENTIDAD EDUCATIVA LP1" << endl << setw(73) << "LISTADOS DE CLASE" << endl;
    for (int i = 0; curso_Nombre[i] != nullptr; ++i) {
        imprimirCurso(file, i + 1, curso_Nombre[i], curso_Credito[i]);
        imprimirAlumnosDelCurso(file, curso_Alumnos[i], alumno_Codigo, alumno_Nombre,
                                alumno_Modalidad, alumno_Porcentaje, curso_Credito[i], pagoTotal);
    }
    imprimirResultadoCurso(file, pagoTotal);
    delete[] pagoTotal;
    file.close();
}

void imprimirCurso(ofstream &file, const int cnt, const char *nombre, const double credito) {
    file << setw(MAX_LINEA) << setfill('=') << '=' << endl
         << right << setw(2) << setfill('0') << cnt << left << setw(10) << setfill(' ') << ')'
         << left << setw(15) << setfill(' ') << "Curso:"
         << left << setw(50) << nombre
         << "Creditos: " << credito << endl
         << setw(MAX_LINEA) << setfill('-') << '-' << endl
         << "ALUMNOS Matriculados" << endl
         << setw(MAX_LINEA) << setfill('-') << '-' << endl
         << right << setw(85) << setfill(' ') << "PAGOS" << endl
         << left << setw(14) << "    CODIGOS"
         << setw(40) << "NOMBRE"
         << "ESCALA    " << setw(12) << "PRESENCIAL" << setw(17) << "SEMI PRESENCIAL" << "VIRTUAL" << endl
         << setw(MAX_LINEA) << setfill('-') << '-' << endl;
}

void imprimirAlumnosDelCurso(ofstream &file, int *curso_Alumnos, int *alumno_codigo, char **alumno_Nombre,
                             char *alumno_Modalidad, int *alumno_Porcentaje, double creditoCurso, double *&pagoTotal) {
    double *escala = new double[MAX_ESCALA](); // cantidad de escalas
    int indexAlumno = 0;
    double *pagoTotalCurso = new double[3]();
    obtenerEscalas(escala);
    for (int i = 0; curso_Alumnos[i] != 0; i += 2) {
        file << right << setw(2) << setfill('0') << (i / 2 + 1) << ")  "
             << left << setw(6) << setfill(' ') << curso_Alumnos[i];
        indexAlumno = 0;
        while (alumno_codigo[indexAlumno] != curso_Alumnos[i]) indexAlumno++;//buscamos el index del alumno
        file << left << setw(45) << setfill(' ') << alumno_Nombre[indexAlumno]
             << curso_Alumnos[i + 1]; // imprimirEscalar
        file << fixed << setprecision(2);
        imprimirPago(file, alumno_Modalidad[indexAlumno], alumno_Porcentaje[indexAlumno],
                     escala, curso_Alumnos[i + 1], creditoCurso, pagoTotal, pagoTotalCurso);
    }
    imprimirPagoCurso(file, pagoTotalCurso);
    delete[] escala;
    delete[] pagoTotalCurso;
}

void obtenerEscalas(double *&escala) {
    ifstream file;
    abrirArchivoLectura(file, "escalas.csv");
    char c;
    int n;
    double credito;
    for (int i = 0; i < MAX_ESCALA; ++i) {
        file >> c >> n >> c >> credito;
        escala[n - 1] = credito;
    }
    file.close();
}

void imprimirPago(ofstream &file, char modalidad, int porcentaje, double *escala, int escalaAlumno,
                  double creditoCurso, double *&pagoTotal, double *&pagoTotalCurso) {
    double pago;
    switch (modalidad) {
        case 'S'://semi presencial
            pago = (escala[escalaAlumno - 1] * creditoCurso * (100 - porcentaje)) / 100;
            file << right << setw(29) << setfill(' ') << pago << endl;
            pagoTotalCurso[1] += pago;
            pagoTotal[1] += pago;
            break;
        case 'V': // virtual
            pago = escala[escalaAlumno - 1] * creditoCurso;
            file << right << setw(43) << setfill(' ') << pago << endl;
            pagoTotalCurso[2] += pago;
            pagoTotal[2] += pago;
            break;
        default: // presencial
            pago = escala[escalaAlumno - 1] * creditoCurso;
            file << right << setw(16) << setfill(' ') << pago << endl;
            pagoTotalCurso[0] += pago;
            pagoTotal[0] += pago;
            break;
    }
}

void imprimirPagoCurso(ofstream &file, double *pagoTotalCurso) {
    double totalRecaudado = pagoTotalCurso[0] + pagoTotalCurso[1] + pagoTotalCurso[2];
    file << setw(MAX_LINEA) << setfill('=') << '=' << '\n'
         << left << setw(66) << setfill(' ') << "RECAUDACION  POR MODALIDAD DE ESTUDIO"
         << pagoTotalCurso[0]
         << right << setw(13) << pagoTotalCurso[1]
         << right << setw(15) << pagoTotalCurso[2] << '\n'
         << setw(MAX_LINEA) << setfill('-') << '-' << '\n'
         << left << setw(93) << setfill(' ') << "TOTAL RECAUDADO:" << totalRecaudado << endl;
}

void imprimirResultadoCurso(ofstream &file, double *pagoTotal) {
    double totalRecaudado = pagoTotal[0] + pagoTotal[1] + pagoTotal[2];
    file << setw(MAX_LINEA) << setfill('=') << '=' << endl
         << left << setw(65) << setfill(' ') << "RECAUDACION TOTAL POR MODALIDAD DE ESTUDIO"
         << pagoTotal[0]
         << right << setw(13) << pagoTotal[1]
         << right << setw(15) << pagoTotal[2] << '\n'
         << setw(MAX_LINEA) << setfill('-') << '-' << '\n'
         << left << setw(93) << setfill(' ') << "TOTAL RECAUDADO:" << totalRecaudado << endl;
}






