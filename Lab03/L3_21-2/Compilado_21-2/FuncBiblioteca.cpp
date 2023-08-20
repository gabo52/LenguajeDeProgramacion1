/*
 * File:   FuncBiblioteca.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "FuncBiblioteca.h"
#include "Estructuras.h"
#define MAXCANTLINEA 100

using namespace std;
//KC34197    Las_demoliciones_de_Paris     15    294.26
bool operator >> (ifstream &in, Libro &lib){
    char codigo[8], titulo[50];
    int stock;
    double precio;
    in>>codigo;
    if(in.fail()){
        in.clear();
        return false;
    }
    in>>titulo>>stock>>precio;
    strcpy(lib.codigo,codigo);
    strcpy(lib.titulo,titulo);
    lib.stock=stock;
    lib.precio=precio;
    return true;
}

ofstream abrirArchivoE(const char *nombre,char modo){
    ofstream arch;
    if (modo='T')arch.open(nombre,ios::out);
    else arch.open(nombre,ios::out|ios::binary);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

ifstream abrirArchivoL(const char *nombre,char modo){
    ifstream arch;
    if (modo='T')arch.open(nombre,ios::in);
    else arch.open(nombre,ios::in|ios::binary);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}
bool operator >> (ifstream &in, Usuario &usuario){
    char tipo,nombre[100];
    int carne;
    in>>carne;
    if(in.fail()){
        in.clear();
        return false;
    }
    //arreglar
    in>>tipo>>nombre;
    usuario.carne=carne;
    strcpy(usuario.nombre,nombre);
    if(tipo=='A'){
        strcpy(usuario.tipo,"ADMINISTRATIVO");
    }else if(tipo=='E'){
        strcpy(usuario.tipo,"ESTUDIANTE");
    }else{
        strcpy(usuario.tipo,"DOCENTE");
    }
    return true;
}

void operator += (Usuario &usuario,LibroPrestado lib ){
    int i=usuario.numLibPrest;
    usuario.libPrest[i]=lib;
    usuario.numLibPrest++;
}

void operator += (Libro &lib,UsuarioPrestamo usuario){
    int i;
    if(usuario.tipo=='E'){
        i=lib.cantEst;
        lib.estudiantes[i]=usuario;
        lib.cantEst++;
    }else if (usuario.tipo=='A'){
        i=lib.cantAdm;
        lib.administrativos[i]=usuario;
        lib.cantAdm++;
    }else{
        i=lib.cantDoc;
        lib.docentes[i]=usuario;
        lib.cantDoc++;
    }
}

void operator <= (Usuario &usuario, int fecha){
    int k=usuario.numLibPrest,aux;
    strcpy(usuario.condicion,"HABILITADO");
    for(int i=0;i<k;i++){
        aux=usuario.libPrest[i].fechaDeRetiro;
        if(strcmp(usuario.tipo,"ADMINISTRATIVO")){
            if(numeroDeDias(aux,fecha)>3){
                usuario.libPrest[i].deuda=true;
                strcpy(usuario.condicion,"INHABILITADO");
            }else usuario.libPrest[i].deuda=false;
        }else if(strcmp(usuario.tipo,"ESTUDIANTE")){
            if(numeroDeDias(aux,fecha)>7){
                usuario.libPrest[i].deuda=true;
                strcpy(usuario.condicion,"INHABILITADO");
            }else usuario.libPrest[i].deuda=false;
        }else{
            if(numeroDeDias(aux,fecha)>15){
                usuario.libPrest[i].deuda=true;
                strcpy(usuario.condicion,"INHABILITADO");
            }else usuario.libPrest[i].deuda=false;
        }
    }
}

void imprimeFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa;
}
void imprimeLibro(ofstream &arch,LibroPrestado lib){
    arch<<setw(20)<<left<<lib.codigoLib;
    imprimeFecha(arch,lib.fechaDeRetiro);
    if(lib.deuda)arch<<"      Deuda"<<endl;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void operator << (ofstream &arch,const Usuario &usuario){
    arch<<left<<usuario.carne<<endl;
    arch<<usuario.nombre<<endl<<usuario.tipo<<endl<<usuario.condicion<<endl;
    for(int i=0;i<usuario.numLibPrest;i++){
        imprimeLibro(arch,usuario.libPrest[i]);
    }
}

void imprimePrestamos(ofstream &arch,const char *cadena,const UsuarioPrestamo *arr,
        int cant){
    arch<<cadena<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    if(cant>0){
       arch<<"No."<<setw(12)<<right<<"Carne"<<setw(30)<<right<<"Fecha de retiro"
               <<setw(18)<<right<<"Observacion"<<endl; 
       for(int i=0;i<cant;i++){
            arch<<setw(20)<<left<<arr[i].carne;
            imprimeFecha(arch,arr[i].fechaDeRetiro);
            if(arr[i].deuda)arch<<"      Deuda"<<endl;
       }
    }
}
void operator << (ofstream &arch, const Libro &lib){
    arch<<left<<"Titulo  : "<<left<<lib.titulo<<endl;
    arch<<left<<"Codigo  : "<<setw(21)<<left<<lib.codigo<<"Precio  :"<<setw(10)
            <<right<<setprecision(2)<<fixed<<lib.precio<<endl;
    arch<<left<<"Stock   :     "<<setw(17)<<left<<lib.stock<<"Prestados:     "
            <<left<<lib.prestados<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<"Usuarios que lo tienen en su poder:"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    imprimePrestamos(arch,"DOCENTES:",lib.docentes,lib.cantDoc);
    imprimePrestamos(arch,"ESTUDIANTES:",lib.estudiantes,lib.cantEst);
    imprimePrestamos(arch,"ADMINISTRATIVOS:",lib.administrativos,lib.cantAdm);
    imprimeLinea(arch,MAXCANTLINEA,'=');
}
int numeroDeDias(int fecha1,int fecha2){
    // fecha1 y fecha2 están en el formato aaaammdd
    int dd1,mm1,aa1, dd2,mm2,aa2;
    int cont=0, aux;
    if(fecha1 < fecha2) {
        aux = fecha1;
        fecha1 = fecha2;
        fecha2 = aux;
    }
    fTodma(fecha1, dd1,mm1,aa1);
    fTodma(fecha2, dd2,mm2,aa2);
    while(dd1!=dd2 or mm1!=mm2 or aa1!=aa2){
        dd1--; cont++;
        if (dd1==0){
            mm1--;
            if(mm1==0){
                aa1--;
                mm1=12;
            }
            dd1 = diasDelMes(mm1,aa1);
        }
    }
    return cont;
}

void fTodma(int fecha, int &dd, int &mm, int &aa){
    aa = fecha / 10000;
    fecha = fecha % 10000;
    mm = fecha /100;
    dd = fecha % 100;
}

int diasDelMes(int mm, int aa){
    switch(mm){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: 
            if(aa%4==0 && (aa%100!=0 || aa%400==0))
		return 29;
            return 28;
    }
}