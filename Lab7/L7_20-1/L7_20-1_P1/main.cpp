/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 31 de octubre de 2022, 10:42 AM
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Alumno.h"
#include "Curso.h"
#include "Acurso.h"
#include "funcionesAuxiliares.h"
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Curso cur,cur2,cur3;
    char nombCur[20];
    strcpy(nombCur,"LP1");
    
    cur.SetCiclo(20222);
    cur.SetCcurso(nombCur);
    cur.SetNota(18);
    cur.SetCredito(4.5);
    cur2.asignar(cur);
    
    cur3.SetCiclo(20222);
    strcpy(nombCur,"LP2");
    cur3.SetCcurso(nombCur);
    cur3.SetNota(10);
    cur3.SetCredito(5);
    if(cur.compare(cur2)){
        cout<<cur2.GetCcurso()<<endl;
    }
    Acurso a1,a2;
    a1.SetClcurso(cur);
    a1.SetClcurso(cur2);
    a2.SetClcurso(cur3);
    cout<<a1.GetClcurso().GetCcurso()<<"1"<<endl;
    Alumno alum1;
    alum1.SetCodigo(20203371);
    alum1.SetNombre("Gabriel");
    alum1.SetTipo('A');
    
    alum1+a1;
    alum1*a1;
    
    alum1+a2;
    alum1*a2;
    
    //alum1-a1;
    double prom=alum1/20222;
    cout<<prom<<endl;
    double sumCred=--alum1;
    double sumCredAprox = ++alum1;
    cout<<sumCred<<"    "<<sumCredAprox<<endl;
    
    ifstream arch1,arch2;
    ofstream rep;
    AbrirArchivo("Cursos.txt",arch1);
    AbrirArchivo("Alumnos.txt",arch2);
    AbrirArchivo("Rep.txt",rep);
    Alumno alu;
    arch2>>alu;
    alu+a1;
    alu*a1;
    alu+a2;
    alu*a2;
    rep<<alu;    return 0;
}

