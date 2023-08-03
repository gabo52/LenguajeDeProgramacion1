/* 
 * File:   Alumno.cpp
 * Author: Gabriel Omar Duran Ruiz
 * Codigo: 20203371
 * Created on 31 de octubre de 2022, 10:43 AM
 */

#include "Alumno.h"
#include "Curso.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;



int busca(int dato,int *arr);


Alumno::Alumno() {
    nombre = nullptr;
    numCur = 0;
}



Alumno::~Alumno() {
    delete nombre;
}

void Alumno::SetNumCur(int numCur) {
    this->numCur = numCur;
}

int Alumno::GetNumCur() const {
    return numCur;
}

void Alumno::SetNombre(const char* nomb) {
    if(nombre)delete nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(this->nombre,nomb);
}

char* Alumno::GetNombre() const {
    char *aux;
    aux = new char [strlen(nombre)+1];
    strcpy(aux,nombre);
    return aux;
}

void Alumno::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Alumno::GetTipo() const {
    return tipo;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void  Alumno::copia(const Alumno &c){
    codigo = c.GetCodigo();
    tipo = c.GetTipo();
    nombre = c.GetNombre();
    //pasar arreglo
    numCur = c.GetNumCur();
    for(int i=0;i<numCur;i++){
        lcurso[i].copia(c.lcurso[i]);
    }
}

void Alumno::operator + (const Acurso& c) {
    lcurso[numCur].copia(c.GetClcurso());
    numCur ++;
}

void Alumno::operator *(const Acurso& c) {
    Curso aux;
    aux = c.GetClcurso();
    for(int i=0;i<numCur;i++){
        if(lcurso[i].compare(aux)){
            lcurso[i].asignar(aux);
            break;
        }
    }
}

void Alumno::operator-(const Acurso& c) {
    Curso aux,aux1;
    aux = c.GetClcurso();
    cout<<c.GetClcurso().GetCcurso()<<2<<endl;
    for(int i=0;i<numCur;i++){
        if(lcurso[i].compare(aux)){
            //preguntar como borrar
            aux1.asignar(lcurso[numCur-1]);
            lcurso[i].asignar(lcurso[numCur-1]);
            lcurso[numCur-1].asignar(aux1);
            numCur--;
            break;
        }
    }
}

double Alumno::operator/(int ciclo) {
    Curso aux;
    int n=0,cicloAux;
    double suma=0;
    for(int i=0;i<numCur;i++){
        cicloAux=lcurso[i].GetCiclo();
        if(ciclo==cicloAux){
            suma+=lcurso[i].GetNota();
            n++;
        }
    }
    if(n==0)return 0;
    return suma/n;
}

double Alumno::operator--() {
    double suma=0;
    for(int i=0;i<numCur;i++){
        suma+=lcurso[i].GetCredito();
    }
    return suma;
}

double Alumno::operator++() {
    double suma=0;
    for(int i=0;i<numCur;i++){
        if(lcurso[i].GetNota()>10){
            suma+=lcurso[i].GetCredito();
        }
    }
    return suma;
}

void Alumno::SetLcurso(Curso *arr,int n) {
    for(int i=0;i<n;i++){
        lcurso[i].copia(arr[i]);
    }
    numCur=n;
}

Curso* Alumno::GetLcurso(int n)const{
    Curso *cur;
    cur = new Curso [100]{};
    for(int i=0;i<n;i++){
        cur[i].copia(lcurso[i]);
    }
    return cur;
}
//R 20160658 Arca/Amezquita/Edric-Ronald IngenieriaMecanica FCI
// tipo,  codigo, nombre, especialidad, facultad











