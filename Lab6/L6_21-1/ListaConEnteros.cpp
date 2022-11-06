/* 
 * File:   ListaConEnteros.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 25 de octubre de 2022, 06:16 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "ListaConEnteros.h"

void *leenum(ifstream &arch){
    char buff[150],c;
    arch.getline(buff,150,',');
    if(arch.eof())return nullptr;
    int dd,mm,aa,*fecha;
    arch.getline(buff,150,',');
    arch>>dd>>c>>mm>>c>>aa;
    fecha = new int;
    *fecha = dd + mm*100+ aa*10000;
    arch.getline(buff,150);
    void **aux;
    aux = new void *[1];
    aux[0] = fecha;
    return aux;
}

int cmpnum(void *dt1,void *dt2){
    void **dato1=(void**)dt1,**dato2=(void**)dt2;
    int *n1=(int *)dato1[0],*n2=(int *)dato2[0];
    return *n1-*n2;
}

void imprimenum(void *dt,ofstream &arch,void *&cabecera){
    int *fechaP;
    void **dato=(void **)dt;
    fechaP=(int*)dato[0];
    arch<<*fechaP<<endl;
}