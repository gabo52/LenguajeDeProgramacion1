/*
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesAuxiliares.h"
#define MAXCANTNOMBRE 60
#define MAXCANTTITULO 60
using namespace std;

ofstream abrirArchivoE(const char *nombre,char modo){
    ofstream arch;
    if(modo=='T')arch.open(nombre,ios::out);
    else arch.open(nombre,ios::out | ios::binary);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo: "<<nombre<<endl;
        exit(1);
    }
    return arch;
}

ifstream abrirArchivoL(const char *nombre,char modo){
    ifstream arch;
    if(modo=='T')arch.open(nombre,ios::in);
    else arch.open(nombre,ios::in | ios::binary);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo: "<<nombre<<endl;
        exit(1);
    }
    return arch;
}

void cargarRegLibrosBin(char *codigo,char *titulo,char *nombre,
        int aa,int cantLibStock,int cantLibPres,double precio,ofstream &arch){
    arch.write(reinterpret_cast<const char*>(&codigo),sizeof(int));
    arch.write(reinterpret_cast<const char*>(titulo),sizeof(char)*MAXCANTTITULO);
    arch.write(reinterpret_cast<const char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
    arch.write(reinterpret_cast<const char*>(&aa),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantLibStock),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantLibPres),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&precio),sizeof(double));
}
void cargarLibrosBin(ofstream &archLibBin){
    int aa,cantidad,num=0,cantLibStock=0,cantLibPres=0;
    double precio;
    char codigo[12],nombre[MAXCANTNOMBRE],titulo[MAXCANTTITULO];
    ifstream archLib=abrirArchivoL("Libros.txt",'T');
    archLibBin.seekp(0,ios::beg);
    while(1){
        archLib>>codigo>>titulo>>nombre>>aa>>cantidad>>precio;
        if(archLib.eof())break;
        cargarRegLibrosBin(codigo,titulo,nombre,aa,cantLibStock,cantLibPres,precio,archLibBin);
    }
}
void reporteLibrosBin(ofstream &archLibBin,ofstream &archLibRep){
    
}

void crearCargarLibrosBin(){
    ofstream librosBin=abrirArchivoE("libros.bin",'B');
    cargarLibrosBin(librosBin);
    librosBin.close();
}

void imprimeCabeceraLibros(ofstream &librosRep){
    librosRep<<setw(10)<<left<<"Codigo";
    librosRep<<setw(40)<<left<<"Titulo del libro";
    librosRep<<setw(30)<<left<<"Nombre del autor";
    librosRep<<setw(20)<<left<<"Anio de publicacion";
    librosRep<<setw(20)<<left<<"Cantidad de libros";
    librosRep<<setw(20)<<left<<"Precio";
    librosRep<<endl;
}

void leerLibrosBin(ifstream &librosBin,char *codigo,char *titulo,char *autor,
        int &aa,int &cantLibStock,int &cantLibPres,double &precio){
    librosBin.read(reinterpret_cast<char*>(&codigo),sizeof(int));
    librosBin.read(reinterpret_cast<char*>(titulo),sizeof(char)*MAXCANTTITULO);
    librosBin.read(reinterpret_cast<char*>(autor),sizeof(char)*MAXCANTNOMBRE);
    librosBin.read(reinterpret_cast<char*>(&aa),sizeof(int));
    librosBin.read(reinterpret_cast<char*>(&cantLibStock),sizeof(int));
    librosBin.read(reinterpret_cast<char*>(&cantLibPres),sizeof(int));
    librosBin.read(reinterpret_cast<char*>(&precio),sizeof(double));
}
void verificarLibrosBin(){
    ifstream librosBin=abrirArchivoL("libros.bin",'B');
    ofstream librosRep=abrirArchivoE("ReporteLibros.txt",'T');
    int codigo,aa,cantLibStock,cantLibPres;
    char titulo[MAXCANTTITULO],autor[MAXCANTNOMBRE];
    double precio;
    imprimeCabeceraLibros(librosRep);
    while(1){
        if(librosBin.eof())break;
        leerLibrosBin(librosBin,codigo,titulo,autor,aa,cantLibStock,cantLibPres,precio);
        librosRep<<setw(10)<<left<<codigo<<setw(40)<<left<<titulo<<setw(40)<<left
                <<autor<<setw(20)<<left<<aa<<setw(10)<<left<<cantidad<<setw(10)
                <<left<<setprecision(2)<<fixed<<precio<<endl;
    }
    librosBin.close();
    librosRep.close();
}

void leerFecha(int &fecha,ifstream &arch){
    int aa,dd,mm;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}

void cargarPrestamosBin(int carnet,ofstream &prestamosBin,ifstream &archReg){
    int dato;
    while(1){
        archReg>>dato;
        if(archReg.fail()){
            archReg.clear();
            
        }else{
            break;
        }
    }
}

void leeCargaPrestamoLibro(ifstream &arch,ofstream &libBin,int carnet,int &contador,
        int &flag){
    flag=1;
    char codigo[10];
    int fecha;
    arch>>codigo;
    leerFecha(fecha,arch);
    libBin.write(reinterpret_cast<const char *>(&carnet),sizeof(int));
    libBin.write(reinterpret_cast<const char *>(codigo),sizeof(char)*10);
    libBin.write(reinterpret_cast<const char *>(&fecha),sizeof(int));
    contador++;
}

void leeDigitoYNombre(ifstream &archRegPrestamos,char &digito,int &contador,
        char *nombre){
    contador=0;
    archRegPrestamos>>digito>>nombre;
}


void cargaUsuario(int carnet,char digito,char *nombre,int contador,ofstream &usuariosBin){
    int cant=0;
    double multa=0;
    usuariosBin.write(reinterpret_cast<const char*>(&carnet),sizeof(int));
    usuariosBin.write(reinterpret_cast<const char*>(&digito),sizeof(char));
    usuariosBin.write(reinterpret_cast<const char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
    usuariosBin.write(reinterpret_cast<const char*>(&contador),sizeof(int));
    usuariosBin.write(reinterpret_cast<const char*>(&cant),sizeof(int));
    usuariosBin.write(reinterpret_cast<const char*>(&multa),sizeof(double));
}
void crearCargarPrestamosUsuariosBin(){
    ofstream prestamosBin,usuariosBin;
    ifstream archRegPrestamos;
    int carnet,fecha1,dato,contador,flag=0;
    char digito,codigo[12];
    char nombre[MAXCANTNOMBRE];
    prestamosBin=abrirArchivoE("prestamos.bin",'B');
    usuariosBin=abrirArchivoE("usuarios.bin",'B');
    archRegPrestamos=abrirArchivoL("RegistroDePrestamos.txt",'T');
    while(1){
        archRegPrestamos>>dato;
        if(archRegPrestamos.eof()){
            cargaUsuario(carnet,digito,nombre,contador,usuariosBin);
            break;
        }
        if(archRegPrestamos.fail()){
            archRegPrestamos.clear();
            leeCargaPrestamoLibro(archRegPrestamos,prestamosBin,carnet,contador,flag);
        }else{
            if(flag)cargaUsuario(carnet,digito,nombre,contador,usuariosBin);
            carnet=dato;
            leeDigitoYNombre(archRegPrestamos,digito,contador,nombre);
        }
    }
    prestamosBin.close();
    usuariosBin.close();
    archRegPrestamos.close();
}

void leeUsuariosBin(ifstream &archBin,int &carnet,char &digito,char *nombre,int &cantLibPres,
        int &cantLibDeuda,double &multa){
    archBin.read(reinterpret_cast<char*>(&carnet),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&digito),sizeof(char));
    archBin.read(reinterpret_cast<char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
    archBin.read(reinterpret_cast<char*>(&cantLibPres),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&cantLibDeuda),sizeof(int));
    archBin.read(reinterpret_cast<char*>(&multa),sizeof(double));
}
void imprimeCabeceraPrestamos(ofstream &archBin){
    
}
void verificarUsuariosBin(){
    ofstream archRep=abrirArchivoE("ReporteUsuarios.txt",'T');
    ifstream archBin=abrirArchivoL("usuarios.bin",'B');
    int carnet,cantLibPres,cantLibDeuda;
    double multa;
    char digito,nombre[MAXCANTNOMBRE];
    imprimeCabeceraPrestamos(archRep);
    archBin.seekg(0,ios::beg);
    while(1){
        leeUsuariosBin(archBin,carnet,digito,nombre,cantLibPres,cantLibDeuda,multa);
        
        if(archBin.eof())break;

        archRep<<setw(10)<<left<<carnet<<setw(4)<<left<<digito;
        archRep<<setw(50)<<left<<nombre<<setw(4)<<left<<cantLibPres;
        archRep<<setw(4)<<left<<cantLibDeuda<<setw(4)<<left<<setprecision(2)
                <<fixed<<multa<<endl;
    }
    archBin.close();
    archRep.close();
}

void imprimirFecha(ofstream &archRep,int fecha){
    int aa,dd,mm;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    archRep.fill('0');
    archRep<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa;
    archRep.fill(' ');
}
void verificarPrestamosBin(){
    ofstream archRep=abrirArchivoE("ReportePrestamos.txt",'T');
    ifstream archBin=abrirArchivoL("prestamos.bin",'B');
    int carnet,fecha;
    char codigo[10];
    while(1){
        archBin.read(reinterpret_cast<char *>(&carnet),sizeof(int));
        if(archBin.eof())break;
        archBin.read(reinterpret_cast<char *>(codigo),sizeof(char)*10);
        archBin.read(reinterpret_cast<char *>(&fecha),sizeof(int));
        archRep<<setw(10)<<left<<carnet<<setw(10)<<left<<codigo;
        imprimirFecha(archRep,fecha);
        archRep<<endl;
    }
    archBin.close();
    archRep.close();
}
void actualizarLibrosBin(){
    ofstream archLibBin=abrirArchivoE("libros.bin",'B');
    ifstream archPresBin=abrirArchivoL("prestamos.bin",'B');
    int carnet,fecha;
    char codigo[10];
    
    while(1){
        archPresBin.read(reinterpret_cast<char*>(&carnet),sizeof(int));
        if(archPresBin.eof())break;
        archPresBin.read(reinterpret_cast<char*>(codigo),sizeof(char)*10);
        archPresBin.read(reinterpret_cast<char*>(&fecha),sizeof(int));
    }
    archLibBin.close();
    archPresBin.close();
}
void imprimeReporteLibrosBin(){
    
}