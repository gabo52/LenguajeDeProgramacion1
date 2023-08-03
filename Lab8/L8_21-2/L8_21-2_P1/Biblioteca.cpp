/* 
 * File:   Biblioteca.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de noviembre de 2022, 07:37 PM
 */

#include "Biblioteca.h"
#include <cstring>
#define MAXCANTLINEA 100
void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}
void Biblioteca::generaCopias(){
    ifstream arch;
    AbrirArchivo("Libros2.csv",arch);
    int n=0;
    while(1){
        leeLibro(arch,n);
        if(arch.eof())break;
    }
}


//KC34197,Las_demoliciones_de_Paris,Zkenia/Chung/Zuniga,2014,15,294.26,3
//codigo,titulo,autor,aa,cantidad,precio,zona
void Biblioteca::leeLibro(ifstream &arch,int &n){
    Copia copia;
    char codigo[20],titulo[100],autor[50],c;
    arch.getline(codigo,20,',');
    if(arch.eof())return;
    int aa,cant,zona;
    double precio;
    arch.getline(titulo,100,',');
    arch.getline(autor,50,',');
    arch>>aa>>c>>cant>>c>>precio>>c>>zona;
    arch.get();
    copia.SetAutor(autor);
    copia.SetCantidad(cant);
    copia.SetCodigo(codigo);
    copia.SetPrecio(precio);
    copia.SetTitulo(titulo);
    int j=0;
    for(int i=n;j<cant;j++,i++){
        llibros[i]=copia;
        llibros[i].SetNumero(j+1);
        llibros[i].SetDisponible(zona);
    }
    n+=cant;
}

int Biblioteca::numeroLibros(){
    int i;
    for(i=0;llibros[i].GetPrecio();i++);
    return i;
}
//26916299E,SK15788,10,17/09/2021
//codLib,
void Biblioteca::actualizaLibros(){
    char cad[20];
    ifstream arch;
    int cant,fecha,ref=20211115;
    AbrirArchivo("RegistroDePrestamos2.csv",arch);
    while(1){
        leePrestamo(cad,cant,fecha,arch);
        if(arch.eof())break;
        actualizaDisponibilidadLibros(cad,cant,fecha,ref);
    }
}

void Biblioteca::actualizaDisponibilidadLibros(char *cad,int cantSol,int fecha,int ref){
    int cantidad,i=0;
    int pos=buscarLibro(cad,cantidad),dias;
    if(cantSol>cantidad)cantSol=cantidad;
    char codigo[20];
    for(int j=pos;i<cantSol;j++,i++){
        llibros[j].GetEstado(codigo);
        if(strcmp(codigo,"Disponible")==0){
            dias=numeroDeDias(fecha,ref);
            if(dias>60){
                llibros[j].SetPerdida(llibros[j].GetPrecio());
            }else{
                llibros[j].SetPrestamo(dias,fecha);
            }
        }
    }
    
}

int Biblioteca::buscarLibro(char *cad,int &cantidad){
    char cadena[20];
    for(int i=0;llibros[i].GetPrecio();i){
        llibros[i].GetCodigo(cadena);
        if(strcmp(cad,cadena)==0){
            cantidad=llibros[i].GetCantidad();
            return i;
        }else{
            i+=llibros[i].GetCantidad();
        }
    }
    cout<<"error, no se encontró el libro"<<cad;
    exit(1);
    return -1;
}
void Biblioteca::leePrestamo(char *cad,int &cant,int &fecha,ifstream &arch){
    arch.getline(cad,20,',');
    char c;
    int dd,mm,aa;
    if(arch.eof())return;
    arch.getline(cad,20,',');
    arch>>cant>>c>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}


void Biblioteca::imprimeCopias(){
    ofstream arch;
    AbrirArchivo("ReporteCopias.txt",arch);
    char codigo[10]="0",cad[10];
    for(int i=0;llibros[i].GetPrecio();i++){
        llibros[i].GetCodigo(cad);
        if(strcmp(codigo,cad)!=0){
            imprimeLinea(arch,MAXCANTLINEA,'-');
            strcpy(codigo,cad);
            llibros[i].imprimeLibro(arch);
            imprimeLinea(arch,MAXCANTLINEA,'-');
        }
        llibros[i].imprimeCopia(arch);
    }
}

void Biblioteca::imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}


