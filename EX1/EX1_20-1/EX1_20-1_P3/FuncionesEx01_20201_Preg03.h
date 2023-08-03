/* 
 * File:   FuncionesEx01_20201_Preg03.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 5 de octubre de 2022, 08:47 PM
 */

#ifndef FUNCIONESEX01_20201_PREG03_H
#define FUNCIONESEX01_20201_PREG03_H

void reporteDeCargaHorariaDeProf(char ***cursos,int *codProfesores,
        char **profesores,void *sesiones);
void imprimeCabeceraProf(char *profesor,int cod,ofstream &arch);
void imprimeCursos(char *profesor,ofstream &arch,void *sesiones,
        int &horas,int &cantAl,char ***cursos,int codProf);
void imprimeLinea(ofstream &arch,int cant,char c);

int sesionPerteneceAProfesor(void *sesi,int codProf,char *&codCur,
        char *&codHorario,int *&cant,void *&horarios);

int imprimeHorarioEspecifico(void *&sesiones,ofstream &arch,int i);

void imprimeHorario(ofstream &arch,void *horarios,int &horas,int &cantAl,int &nd
        ,char *codCur,char *codHorario,char ***cursos, int *cant);

void imprimeResumen(int &horas,int &cantAl,ofstream &arch);
void imprimeDia2(int dd,ofstream &arch);

void buscarProd(char *codCur,char ***cursos,char *&nombre,char *&esp);
int comparaCursos(char **cursos,char *codCur,char *&nombre,char *&esp);
void imprimeResumen(int &horas,int &cantAl,ofstream &arch);

#endif /* FUNCIONESEX01_20201_PREG03_H */

