/* 
 * File:   FunNumeros.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de octubre de 2022, 11:22 PM
 */

#include <iostream>
#include <iomanip>
#include "FunNumeros.h"
using namespace std;


void *leenumero(ifstream &arch){
    int n;
    arch>>n;
    if(arch.eof())return nullptr;
    int *nP;
    nP = new int;
    *nP = n;
    void **aux;
    aux = new void *[1];
    aux[0]= nP;
    return aux;
}



int cmpnumero(void *dt1,void *dt2){
    void **dato1=(void**)dt1,**dato2=(void**)dt2;
    int *d1=(int*)dato1[0],*d2=(int*)dato2[0];
    return *d1-*d2;
}


void imprimenumero(void *dt,ofstream &arch,void *&nl){
    void **dato=(void**)dt;
    int *datoInt=(int *)dato[0];
    arch<<*datoInt<<endl;
}