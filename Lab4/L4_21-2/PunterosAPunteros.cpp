/* 
 * File:   PunterosAPunteros.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 22 de septiembre de 2022, 04:52 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "PunterosAPunteros.h"
#include "FuncionesFecha.h"
#define  MAXCANTLINEA 120
using namespace std;



void AbrirArchivoEscritura(const char *nombre,ofstream &arch){
    arch.open(nombre,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

void AbrirArchivoLectura(const char *nombre,ifstream &arch){
    arch.open(nombre,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
}

char *leeCadena(ifstream &arch,char c){
    char buff[250],*aux;
    arch.getline(buff,250,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

char *leeCadena(ifstream &arch){
    char buff[250],*aux;
    arch.getline(buff,250);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

//KC34197,Las_demoliciones_de_Paris,Zkenia/Chung/Zuniga,2014,15,294.26
//codigo,titulo,autor,edicion,stock,precio
void estructuraParaLosLibros_CargaDeDatos(char **&codigo,char **&titulo,
        int *&cantEnBibl,double *&precio){
    ifstream arch;
    char *cod,*tit,*autor,c,*buffCod[100],*buffTit[100],*buffAut[100],buff[100];
    int edicion,stock,numDat=0,buffEdic[100],buffStock[100];
    double prec,buffPrecio[100];
    AbrirArchivoLectura("Libros.csv",arch);
    while(1){
        cod=leeCadena(arch,',');
        if(arch.eof())break;
        tit=leeCadena(arch,',');
        arch.getline(buff,100,',');
        arch>>edicion>>c>>stock>>c>>prec;
        arch.get();
        buffCod[numDat]=cod;
        buffTit[numDat]=tit;
        buffStock[numDat]=stock;
        buffPrecio[numDat]=prec;
        numDat++;
    }
    codigo = new char*[numDat+1];
    titulo = new char*[numDat+1];
    cantEnBibl = new int[numDat+1]{};
    precio = new double[numDat+1];
    
    for(int i=0;i<numDat;i++){
        codigo[i]=buffCod[i];
        titulo[i]=buffTit[i];
        cantEnBibl[i]=buffStock[i];
        precio[i]=buffPrecio[i];
    }
    codigo[numDat]=nullptr;
}

void estructuraParaLosLibros_Reporte(char **codigo,char **titulo,
        int *cantEnBibl,double *precio){
    ofstream arch;
    AbrirArchivoEscritura("ReporteLibros.txt",arch);
    for(int i=0;codigo[i];i++){
        arch<<setw(10)<<left<<codigo[i]<<setw(40)<<left<<titulo[i]<<setw(10)
                <<left<<cantEnBibl[i]<<setw(12)<<right<<setprecision(2)
                <<fixed<<precio[i]<<endl;
    }
}

void usuarioDeLaBiblioteca_CargaDeDatos(int *&carne,char *&tipo,char **&nombre){
    char buffTipo[200], *buffNombre[200],tip,c;
    char *auxNomb;
    int numDat=0,auxCarne,buffCarne[200];
    ifstream arch;
    AbrirArchivoLectura("Usuarios.csv",arch);
    while(1){
        arch>>auxCarne>>tip>>c;
        if(arch.eof())break;
        auxNomb=leeCadena(arch);
        buffCarne[numDat]=auxCarne;
        buffNombre[numDat]=auxNomb;
        buffTipo[numDat]=tip;
        numDat++;
    }
    carne = new int [numDat+1];
    nombre = new char* [numDat+1];
    tipo = new char [numDat+1];
    for(int i=0;i<numDat;i++){
        carne[i]=buffCarne[i];
        tipo[i]=buffTipo[i];
        nombre[i]=buffNombre[i];
    }
    carne[numDat]=0;
    tipo[numDat]=0;
    nombre[numDat]= nullptr;
}
void usuarioDeLaBiblioteca_Reporte(int *carne,char *tipo,char **nombre){
    ofstream arch;
    AbrirArchivoEscritura("ReporteUsuarios.txt",arch);
    for(int i=0;carne[i];i++){
        arch<<setw(15)<<left<<carne[i]<<setw(5)<<left<<tipo[i]<<left<<nombre[i]<<endl;
    }
}

void libroYUsuariosInhabilitados_Reporte(char **&codigo,char **&titulo,
        int *&cantEnBibl,double *&precio,int *carne,char *tipo,char **nombre){
    ofstream archRep;
    ifstream arch;
    double *deudaLib;
    int i;
    for(i=0;codigo[i];i++);
    deudaLib = new double [i+1]{};
    AbrirArchivoEscritura("Reporte_Deudores.txt",archRep);
    AbrirArchivoLectura("RegistroDePrestamos.csv",arch);
    elaborarReporteSegunTipo(codigo,titulo,cantEnBibl,precio,carne,tipo,nombre,'E',arch,archRep,deudaLib);
    elaborarReporteSegunTipo(codigo,titulo,cantEnBibl,precio,carne,tipo,nombre,'D',arch,archRep,deudaLib);
    elaborarReporteSegunTipo(codigo,titulo,cantEnBibl,precio,carne,tipo,nombre,'A',arch,archRep,deudaLib);
    elaborarReporteLibros(codigo,titulo,cantEnBibl,precio,archRep,deudaLib);

}

//45834351A,LM05731,22/09/2021
//carne/tipo,codLib,fecha
void elaborarReporteSegunTipo(char **codigo,char **titulo,
        int *&cantEnBibl,double *precio,int *carne,char *tipo,char **nombre,
        char tip,ifstream &arch,ofstream &archRep,double *&deudaLib){
    int auxCarne,fecha,dd,mm,aa,numDat=0,buffCarne[200]={},buffCantLib[200]={};
    char *buffNomb[200]={},auxTipo,c,codLib[20],**nombDeuda;
    int *carneDeuda,datoFecha=20210924,*cantLibDeuda;
    double *montoDeuda,penalidad,buffDeuda[200]={};
    arch.seekg(0,ios::beg);
    while(1){
        arch>>auxCarne>>auxTipo>>c;
        if(arch.eof())break;
        arch.getline(codLib,20,',');
        arch>>dd>>c>>mm>>c>>aa;
        fecha=dd+mm*100+aa*10000;
        if((auxTipo==tip)&&diasNoPermitidos(datoFecha,fecha,tip,penalidad)&&datoFecha>fecha){
            cargarDeudor(buffCarne,buffCantLib,buffNomb,buffDeuda,numDat,auxCarne,
                    codigo,precio,carne,nombre,penalidad,codLib,cantEnBibl,deudaLib);
        }
    }
    arch.clear();
    carneDeuda = new int [numDat+1];
    cantLibDeuda = new int [numDat+1];
    montoDeuda = new double [numDat+1];
    nombDeuda = new char *[numDat+1];
    for(int i=0;i<numDat;i++){
        carneDeuda[i]=buffCarne[i];
        cantLibDeuda[i]=buffCantLib[i];
        montoDeuda[i]=buffDeuda[i];
        nombDeuda[i]=buffNomb[i];
    }
    cout<<"Llegue uwu";
    carneDeuda[numDat]=0;
    imprimeReporteTipo(carneDeuda,cantLibDeuda,montoDeuda,nombDeuda,tip,archRep);
    delete carneDeuda;
    delete montoDeuda;
    delete nombDeuda;
    delete cantLibDeuda;
}

void imprimeReporteTipo(int *carneDeuda,int *cantLibDeuda,double *montoDeuda,
        char **nombDeuda,char tip,ofstream &archRep){
    imprimeLinea(archRep,MAXCANTLINEA,'=');
    if(tip=='E')archRep<<setw(60)<<right<<"ESTUDIANTES DEUDORES"<<endl;
    else if(tip=='D')archRep<<setw(58)<<right<<"DOCENTES DEUDORES"<<endl;
    else archRep<<setw(64)<<right<<"ADMINISTRATIVOS DEUDORES"<<endl;
    imprimeLinea(archRep,MAXCANTLINEA,'-');
    archRep<<"No.    " <<setw(9)<<left<<"CARNE"<<setw(9)<<right<<"NOMBRE"
            <<setw(65)<<right<<"CANT. DE LIB. ADEUDADOS"<<setw(23)<<right<<
            "MONTO ADEUDADO"<<endl;
    for(int i=0;carneDeuda[i];i++){
        archRep<<setw(2)<<right<<i+1<<")    "<<setw(12)<<left<<carneDeuda[i]<<
                setw(60)<<left<<nombDeuda[i]<<setw(12)<<left<<cantLibDeuda[i]
                <<setw(18)<<right<<setprecision(2)<<fixed<<montoDeuda[i]<<endl;
    }
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
int buscarCarne(int dato,int *arr){
    for(int i=0;arr[i];i++){
        if(arr[i]==dato)return i;
    }
    return -1;
}

int buscarLibro(char *codLib,char **codigo){
    for(int i=0;codigo[i];i++){
        if(strcmp(codLib,codigo[i])==0)return i;
    }
    cout<<"Error, no se encontro el libro "<<codLib;
    exit(1);
}

int buscarCarne(int carne,int *buff,int numDat){
    for(int i=0;i<numDat;i++){
        if(carne==buff[i])return i;
    }
    return -1;
}

void cargarDeudor(int *buffCarne,int *buffCantLib,char **buffNomb,
        double *buffDeuda,int &numDat,int auxCarne,char **codigo,double *precio,
        int *carne,char **nomb,double penalidad,char *codLib,int *&cantEnBibl,
        double *&deudaLib){
    int pos,pos2;
    pos=buscarCarne(auxCarne,buffCarne,numDat);
    pos2=buscarLibro(codLib,codigo);
    if(pos!=-1){
        buffCantLib[pos]++;
        buffDeuda[pos]+=precio[pos2]*penalidad/100;
        
    }else{
        pos=buscarCarne(auxCarne,carne);
        if(pos==-1)cout<<"ERRROR, NO LEE CARNE";
        buffCarne[numDat]=auxCarne;
        buffNomb[numDat]=nomb[pos];
        buffCantLib[numDat]=1;
        buffDeuda[numDat]+=(precio[pos2]*penalidad/100);
        numDat++;
    }
    deudaLib[pos2]+=precio[pos2]*penalidad/100;
    cantEnBibl[pos2]--;
}

int diasNoPermitidos(int datoFecha,int fecha,char tip,double &penalidad){
    if(tip=='A'){
        if(numeroDeDias(datoFecha,fecha)>3){
            penalidad=1.5;
            return 1;
        }
        else return 0;
    }
    if(tip=='D'){
        if(numeroDeDias(datoFecha,fecha)>15){
            penalidad=2.25;
            return 1;
        }
        else return 0;
    }
    if(tip=='E'){
        if(numeroDeDias(datoFecha,fecha)>7){
            penalidad=1;
            return 1;
        }
        else return 0;
    }
    cout<<"ERROR";
    exit(1);
}


void elaborarReporteLibros(char **codigo,char **titulo,int *cantEnBibl,
        double *precio,ofstream &archRep,double *deudaLib){
    imprimeLinea(archRep,MAXCANTLINEA,'=');
    archRep<<setw(80)<<right<<"STOCK DE LIBROS DE LA BIBLIOTECA"<<endl;
    imprimeLinea(archRep,MAXCANTLINEA,'-');
    for(int i=0;codigo[i];i++){
        archRep<<setw(2)<<right<<i+1<<")     "<<setw(15)<<left<<codigo[i]<<
                setw(50)<<left<<titulo[i]<<setw(5)<<right<<cantEnBibl[i]<<
                setw(20)<<right<<setprecision(2)<<fixed<<precio[i]<<setw(18)
                <<right<<setprecision(2)<<fixed<<deudaLib[i]<<endl;
    }
    
}
