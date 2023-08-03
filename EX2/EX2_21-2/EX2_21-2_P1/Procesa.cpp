/* 
 * File:   Procesa.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 26 de noviembre de 2022, 08:41 PM
 */

#include <cstring>

#include "Procesa.h"


void AbrirArchivo(const char*nomb,ifstream &arch);
void AbrirArchivo(const char*nomb,ofstream &arch);

void AbrirArchivo(const char*nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char*nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void Procesa::Carga(){
    CargaLibros("libros2.csv");
    CargaUsuarios("Usuarios2.csv");
    LeeSolicitudes("SolicitudDePrestamos2.csv");
}

void Procesa::CargaLibros(const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    Libro lib;
    while(1){
        lib.leelibros(arch);
        if(arch.eof())break;
        llibros.push_back(lib);
    }
}

void Procesa::CargaUsuarios(const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);
    NUsuario aux;
    while(1){
        aux.leer(arch);
        if(arch.eof())break;
        vusuarios.push_back(aux);
    }
}

void Procesa::LeeSolicitudes(const char *nomb){
    ifstream arch;
    AbrirArchivo(nomb,arch);  
    int cod;
    char tipo,c,cad[80];
    while(1){
        arch>>cod>>tipo>>c;
        if(arch.eof())break;
        arch>>cad;
        cola.encola(cad,cod);
    }
}

void Procesa::Atiende(){
    char cad[80];
    int carne,flag,n=cola.size();
    for(int i=0;i<n;i++){
        cola.desencola(cad,carne);
        actualiza(cad,carne);
    }
}

void Procesa::actualiza(char *cad,int carne){
    char aux[80];
    for(list<class Libro>::iterator it=llibros.begin();it!=llibros.end();it++){
        (*it).GetCodigo(aux);
        if(strcmp(aux,cad)==0){
            if((*it).GetStock()>0){
                (*it).SetStock((*it).GetStock()-1);
                return;
            }
        }
    }
    cout<<"Llegue";
    cola.encola(cad,carne);
}
void Procesa::Imprime(){
    ImprimeLibros();
    ImprimeCola();
}

void Procesa::ImprimeLibros(){
    ofstream arch;
    AbrirArchivo("ReporteLibros.txt",arch);
    for(list<class Libro>::iterator it=llibros.begin();it!=llibros.end();it++){
        (*it).imprimelibro(arch);
    }
    
}

void Procesa::ImprimeCola(){
    ofstream arch;
    AbrirArchivo("ReporteColas.txt",arch);
    char cad[80];
    int carne;
    while(cola.notEmpty()){
        cola.desencola(cad,carne);
        arch<<setw(10)<<left<<"Libro:"<<left<<cad<<endl;
        imprimeUsuario(carne,arch);
        arch<<endl;
    }
}

void Procesa::imprimeUsuario(int carne,ofstream &arch){
    for(vector<class NUsuario>::iterator it=vusuarios.begin();it!=vusuarios.end();it++){
        if((*it).carne()==carne){
            (*it).imprime(arch);
        }
    }
}

