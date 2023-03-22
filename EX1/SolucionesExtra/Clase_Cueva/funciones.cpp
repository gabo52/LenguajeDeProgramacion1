/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "funciones.h"
using namespace std;


void *generacopias(int copias){
    void **lcopias;
    int *numero,*fecha;
    double *valor;
    char *estado;
    lcopias = new void*[copias]{};
    for(int i =0; i<copias;i++){
        void **reg;
        reg = new void *[4];
        numero = new int;
        fecha = new int;
        valor = new double;
        estado = new char[12];
        *numero = i+1;
        *fecha=0;
        *valor=0;
        reg[0]=numero;
        reg[1]=strcpy(estado,"Disponible");
        reg[2]=fecha;
        reg[3]=valor;
        lcopias[0]=reg;
    }
    return lcopias;
}

void actualiza(void *&st){
    ifstream arch("RegistroDePrestamos2.csv",ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo RegistroDePrestamos2.csv";
        exit(1);
    }
    char codigo[10],cad[10],c;
    void *stock=(void**)st;
    int dd,mm,aa,copia;
    while(1){
        arch.getline(cad,10,',');
        if(arch.eof())break;
        arch.getline(codigo,10,',');
        arch>>copia>>c>>dd>>c>>mm>>c>>aa>>;
        arch.get();
        busca(stock,codigo,copia,mm);
    }
}

void busca(void *stock,char *codigo,int copia,int mm){
    void **lstock=(void**)stock;
    int i=0,*cant,*disponible;
    char *cadena;
    while(lstock[i]){
        void **reg=(void**)lstock[i];
        cadena=(char *)reg[0];
        if(strcmp(cadena,codigo)==0){
                
        }
        i++;
    }
}