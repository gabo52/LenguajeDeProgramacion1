#include "MetodoDinamicoExacto.h"

// Funciones de apertura de archivo

ifstream abrirArchivoLectura(const char *nombre_archivo) {
    ifstream file(nombre_archivo, ios::in);
    if (!file) {
        cerr << "No se pudo abrir el archivo para su lectura: " << nombre_archivo << endl;
        exit(1);
    }
    return file;
}

ofstream abrirArchivoEscritura(const char *nombre_archivo) {
    ofstream file(nombre_archivo, ios::out);
    if (!file) {
        cerr << "No se puedo abrir el archivo para su escritura: " << nombre_archivo << endl;
        exit(1);
    }
    return file;
}

//5802,MINAYA AMEZQUITA RHONY JAIME,5
//2050,LOYOLA HIJAR NICOLAS OSCAR,V,4
//7660,CHANG ARGUEDAS HENRY ANTONIO,S,25,4

void lecturaAlumnos(const char *nombre_archivo, int *&alumno_Codigo, char **&alumno_Nombre,
        char *&alumno_Modalidad, int *&alumno_Porcentaje, int *&alumno_Escala) {
    ifstream file = abrirArchivoLectura(nombre_archivo);
    inicializarValoresAlumno(MAX_ALUMNO, alumno_Codigo, alumno_Nombre, alumno_Modalidad, alumno_Porcentaje, alumno_Escala);
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
    alumno_Codigo = new int [cnt]();
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

void pruebaLecturaAlumnos(const char *nombre_archivo, int *alumno_Codigo, char ** alumno_Nombre,
        char *alumno_Modalidad, int *alumno_Porcentaje, int *alumno_Escala) {
    ofstream file = abrirArchivoEscritura(nombre_archivo);
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

void lecturaCursos(const char *nombre_archivo, int * alumno_Codigo, int *alumno_Escala,
        char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos) {
    ifstream file = abrirArchivoLectura(nombre_archivo);
    inicializarValoresCursos(MAX_CURSO, curso_Nombre, curso_Credito, curso_Alumnos);
    char *curso = new char[50], c; // para poder leer el curso del archivo
    int codigo, i = 0;
    double credito;
    while (!file.eof()) { // mientras no se llega al fin del archivo
        file >> codigo >> c; // leemos el codigo
        file.getline(curso, 50, ','); // leemos el curso
        file >> credito; // leemos el creditaje del curso
        if (!existeCurso(curso, curso_Nombre)) { // el curso todavia no fue agregado
            curso_Nombre[i] = new char[strlen(curso) + 1];
            strcpy(curso_Nombre[i], curso); //copiamos exactamente el curso
        }
        i++;
    }
    file.close(); // cerramos el archivo
}

void inicializarValoresCursos(const int cnt, char **&curso_Nombre, double *&curso_Credito, int **&curso_Alumnos) {
    curso_Nombre = new char *[cnt]();
    curso_Credito = new double[cnt]();
    curso_Alumnos = new int *[cnt]();
}

bool existeCurso(const char *curso, char **&curso_Nombre) {
    int i = 0;
    while (curso_Nombre[i] != nullptr && strcmp(curso, curso_Nombre[i]) != 0) i++;
    // si la condicion es true, el curso existe todavia, caso contrario es porque todavia no fue agregado
    return curso_Nombre[i] != nullptr;
}



















