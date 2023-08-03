/* 
 * File:   Biblioteca.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 10:36 PM
 */

#include <cstring>

#include "Biblioteca.h"

void AbrirArchivo(const char *nomb, ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb, ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void Biblioteca::leeLibros(const char* nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    Libro lib;
    while(1){
        lib.leeDatos(arch);
        if((arch.eof()))break;
        libros.push_back(lib);
    }
}

void Biblioteca::imprimeLibros(const char*nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    arch<<setw(10)<<left<<"CODIGO"<<setw(35)<<left<<"NOMBRE"<<setw(5)<<left<<"CANT"<<
            setw(5)<<left<<"PREST"<<setw(10)<<right<<"Precio"<<endl;
    for(list<Libro>::iterator it=libros.begin();it!=libros.end();it++){
        (*it).imprimeDatos(arch);
    }
}

void Biblioteca::leerUsuarios(const char*nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    RegistroUsuario usuar;
    while(1){
        usuar.leeDatos(arch);
        if((arch.eof()))break;
        usuarios.push_back(usuar);
    }
}

void Biblioteca::leerPrestamos(const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    int cod,dd,mm,aa,fecha;
    char tipo,c,cad[80];
    while(1){
        arch>>cod>>tipo>>c;
        if(arch.eof())break;
        arch.getline(cad,80,',');
        arch>>dd>>c>>mm>>c>>aa;
        fecha=dd+mm*100+aa*10000;
        actualizarLibros(cad);
        actualizarUsuario(cod,tipo,fecha,cad);
    }
}

void Biblioteca::actualizarUsuario(int cod,char tipo,int fecha,char *cad){
    for(vector<RegistroUsuario>::iterator it=usuarios.begin();it!=usuarios.end();it++){
        if((*it).carne()==cod){
            (*it).agregaPrestamo(cad,fecha);
        }
    }
}
void Biblioteca::actualizarLibros(char *cad){
    char aux[80];
    for(list<Libro>::iterator it=libros.begin();it!=libros.end();it++){
        (*it).GetCodigo(aux);
        if(strcmp(aux,cad)==0){
            (*it).SetPrestados((*it).GetPrestados()+1);
        }
    }
}

void Biblioteca::imprimeUsuarios(const char*nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    for(vector<RegistroUsuario>::iterator it=usuarios.begin();it!=usuarios.end();it++){
        arch<<setw(10)<<left<<"CARNE"<<setw(45)<<left<<"NOMBRE"<<left<<"TIPO"<<endl;
        (*it).imprimeDatos(arch);
        arch<<endl;
    }
}

void Biblioteca::imprimirSuspendidos(const char*nomb,int dd, int mm, int aa){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    arch<<setw(10)<<left<<"CARNE"<<setw(45)<<left<<"NOMBRE"<<left<<"TIPO"<<endl;
    for(vector<RegistroUsuario>::iterator it=usuarios.begin();it!=usuarios.end();it++){
        if((*it).suspendido(dd+mm*100+aa*10000)){
            (*it).imprimeUsuario(arch);
        }
    }
}

