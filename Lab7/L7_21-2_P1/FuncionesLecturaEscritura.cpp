/* 
 * File:   FuncionesLecturaEscritura.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 12:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Libro.h"
#include "Usuario.h"
#include "FuncionesFecha.h"
#include "FuncionesLecturaEscritura.h"
#define MAXCANTLINEA 100
using namespace std;


void AbrirArchivo(const char *nomb, ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<< nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb, ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<< nomb;
        exit(1);
    }
}

ifstream & operator >>(ifstream &arch,Libro &lib){
    int aa,stock;
    char titulo[150],autor[100],codigo[15],c;
    double precio;
    arch.getline(codigo,15,',');
    if(arch.eof())return arch;
    arch.getline(titulo,150,',');
    arch.getline(autor,100,',');
    arch>>aa>>c>>stock>>c>>precio;
    arch.get();
    lib.SetAutor(autor);
    lib.SetCodigo(codigo);
    lib.SetPrecio(precio);
    lib.SetStock(stock);
    lib.SetTitulo(titulo);
}

ifstream & operator >>(ifstream &arch,Usuario &usu){
    int carne;
    char tipo,c;
    char nombre[50];
    arch>>carne;
    if(arch.eof())return arch;
    arch>>tipo>>c>>nombre;
    usu.SetCarne(carne);
    usu.SetNombre(nombre);
    usu.SetTipo(tipo);
}


ifstream & operator >>(ifstream &arch,LibroPrestado &lpres){
    int carne;
    char tipo,codLib[20],c;
    int dd,mm,aa;
    arch>>carne;
    if(arch.eof())return arch;
    arch>>tipo>>c;
    arch.getline(codLib,20,',');
    arch>>dd>>c>>mm>>c>>aa;
    lpres.SetCarne(carne);
    lpres.SetCodigoLib(codLib);
    lpres.SetFechaDeRetiro(dd+mm*100+aa*10000);
    lpres.SetTipo(tipo);
}


void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
ofstream & operator <<(ofstream &arch,const Libro &lib){
    char cadena[200];
    lib.GetCodigo(cadena);
    arch<<setw(10)<<left<<"Codigo:"<<cadena<<endl;
    lib.GetTitulo(cadena);
    arch<<setw(10)<<left<<"Titulo:"<<cadena<<endl;
    lib.GetAutor(cadena);
    arch<<setw(10)<<left<<"Autor:"<<cadena<<endl;
    arch<<setw(10)<<left<<"Stock :"<<lib.GetStock()<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(30)<<"Prestamos a docentes :"<<setw(5)<<right<<lib.GetCantDoc();
    arch<<setw(30)<<"Prestamos a alumnos :"<<setw(5)<<right<<lib.GetCantEst();
    arch<<setw(30)<<"Prestamos a administrativos :"<<setw(5)<<right<<
            lib.GetCantAdm();
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(30)<<"Total de Prestamos:"<<setw(5)<<right<<lib.GetPrestados();
    imprimeLinea(arch,MAXCANTLINEA,'=');
}

ofstream & operator <<(ofstream &arch,const LibroPrestado &lib){
    char codigo[15];
    int fecha=lib.GetFechaDeRetiro();
    int dd,mm,aa;
    fTodma(fecha,dd,mm,aa);
    lib.GetCodigoLib(codigo);
    arch<<setw(20)<<codigo;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa;
    double deuda=lib.GetDeuda();
    if(deuda>0){
        arch<<"                 DEUDA";
    }
    arch<<endl;
}

ofstream & operator <<(ofstream &arch, Usuario &usu){
    char cadena[200],c;
    
    arch<<setw(15)<<left<<"Codigo"<<": "<<usu.GetCarne()<<endl;
    usu.GetNombre(cadena);
    arch<<cadena<<endl;
    
    if(usu.GetTipo()=='A'){
        arch<<"Administrativo";
    }else if(usu.GetTipo()=='E'){
        arch<<"Estudiante";
    }else arch<<"Docente";
    arch<<endl;
    if(usu.GetCondicion()==1){
        arch<<"HABILITADO";
    }else arch<<"INHABILITADO";
    arch<<endl;
    usu.imprimeLibros(arch);
    imprimeLinea(arch,MAXCANTLINEA,'=');
}