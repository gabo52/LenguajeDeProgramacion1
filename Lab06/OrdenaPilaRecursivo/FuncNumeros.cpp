/* 
 * File:   FuncNumeros.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de octubre de 2022, 05:12 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncNumeros.h"
using namespace std;


void *leenum(ifstream &arch){
    int num;
    arch>>num;
    if(arch.eof())return nullptr;
    int *numP;
    numP = new int;
    *numP = num;
    return numP;
}

int cmpnum(void *dt1,void *dt2){
    int *n1=(int *)dt1,*n2=(int *)dt2;
    return *n2-*n1;
}

void imprimenum(void *dato,ofstream &arch,void *&condicion){
    int *n=(int *)dato;
    if(condicion==nullptr){
        arch<<setw(25)<<right<<"REPORTE DE NUMEROS"<<endl;
        int *aux;
        aux = new int;
        condicion=aux;
    }
    arch<<*n<<endl;
}