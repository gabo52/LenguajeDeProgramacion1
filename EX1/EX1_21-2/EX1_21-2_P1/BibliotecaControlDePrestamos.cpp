/* 
 * File:   BibliotecaControlDePrestamos.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de octubre de 2022, 04:56 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaControlDePrestamos.h"
#include "FuncionesFecha.h"
#define FECHACOMPARACION 20211019
using namespace std;
// char **codLibro,*tipoUs,**nombreUs,***codLibPrest;
// int *cantLibros,*carneUs,**fechPrest;


void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

//99215341E,ZM20053,10/10/2021
//carneTipo,CodigoLib,fecha
void cargarPrestamos(int **&fechPrest,char ***&codLibPrest,int *carneUs){
    ifstream arch;
    AbrirArchivo("RegistroDePrestamos.csv",arch);
    int carne,fecha,i,pos;
    char tipo,c,*codLib;
    for(i=0;carneUs[i];i++);
    fechPrest = new int *[i+1]{};
    codLibPrest = new char **[i+1]{};
    int nd[i+1]{};
    while(1){
        leerDatos(carne,fecha,tipo,codLib,arch);
        if(arch.eof())break;
        pos=buscarCarne(carne,carneUs);
        if(pos!=-1){
            agregaPrestamo(fechPrest[pos],codLibPrest[pos],nd[pos],fecha,codLib);
        }
    }
    for(i=0;carneUs[i];i++){
        if(fechPrest[i]){
            copiarDinamicamente(fechPrest[i],codLibPrest[i],nd[i]);
        }
    }
}

void copiarDinamicamente(int *&fechPrest,char **&codLibPrest,int nd){
    int *auxInt = new int [nd+1]{};
    char **auxChar = new char *[nd+1]{};
    for(int i=0;i<nd;i++){
        auxInt[i]=fechPrest[i];
        auxChar[i]=codLibPrest[i];
    }
    delete fechPrest;
    delete codLibPrest;
    fechPrest = auxInt;
    codLibPrest = auxChar;
}

void agregaPrestamo(int *&fechPrest,char **&codLibPrest,int &nd,int fecha,
        char *codLib){
    if(fechPrest==nullptr){
        fechPrest = new int [50]{};
        codLibPrest = new char *[50]{};
    }else{
        codLibPrest[nd]=codLib;
        fechPrest[nd]=fecha;
        nd++;
    }
}
int buscarCarne(int carne,int *carneUs){
    for(int i=0;carneUs[i];i++)if(carne==carneUs[i])return i;
    cout<<"ERROR, no se encontro el carne "<<carne;
    return -1;
}

void leerDatos(int &carne,int &fecha,char &tipo,char *&codLib,ifstream &arch){
    arch>>carne>>tipo;
    if(arch.eof())return;
    char c;
    int dd,mm,aa;
    arch.get();
    codLib = leerCadena(arch,',');
    arch>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}

char *leerCadena(ifstream &arch,char c){
    char buff[200],*aux;
    arch.getline(buff,200,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void imprimeCabeceraLibPrest(int carneUs,char tipoUs,ofstream &arch){
    arch<<setw(10)<<left<<"Carne: "<<setw(10)<<left<<carneUs
            <<setw(10)<<left<<"Tipo: "<<setw(10)<<left<<tipoUs<<endl;
}

void mostrarLibrosPrestados(int **fechPrest,char ***codLibPrest,int *carneUs,
        char *tipoUs,const char *nomb){
    ofstream arch;
    AbrirArchivo(nomb,arch);
    for(int i=0;carneUs[i];i++){
        imprimeCabeceraLibPrest(carneUs[i],tipoUs[i],arch);
        if(fechPrest[i]){
            arch<<setw(12)<<left<<"Fecha"<<setw(12)<<left<<"Codigo Libro"<<endl;
            imprimeLibrosUsuario(fechPrest[i],codLibPrest[i],arch);
        }else arch<<"NO SE REGISTRARON LIBROS PRESTADOS"<<endl;
        arch<<endl;
    }
}


void imprimeFecha(int fechPrest,ofstream &arch){
    int dd,mm,aa;
    dd=fechPrest%100;
    fechPrest/=100;
    mm=fechPrest%100;
    aa=fechPrest/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<setw(2)<<right<<mm<<setw(4)<<right
            <<aa<<setfill(' ');
}

void imprimeLibrosUsuario(int *fechPrest,char **codLibPrest,ofstream &arch){
    for(int i=0;fechPrest[i];i++){
        imprimeFecha(fechPrest[i],arch);
        arch<<"     ";
        arch<<left<<codLibPrest[i]<<endl;
    }
}

int cuentaLibros(int *fechPrest){
    int i;
    for(i=0;fechPrest[i];i++);
    return i;
}
//99215341E,P,ZM20053
//CARNE/TIPO,solicitud,codLib
void procesarSolicitudes(int *&carneUs,char *&tipoUs,char **&nombreUs,
        int **&fechPrest,char ***&codLibPrest,char **&codLibro,int *&cantLibros){
    ifstream arch;
    ofstream archRep;
    AbrirArchivo("PedidosYDevoluciones.csv",arch);
    AbrirArchivo("ReporteSolicitudesPrestamo.txt",archRep);
    archRep<<setw(70)<<right<<"RESPUESTA A LAS SOLICITUDES DE PRESTAMO"<<endl;
    int i,contador=0;
    for(i = 0;carneUs[i];i++);
    int librosPedidos[i+1]{};
    for(int i=0;carneUs[i];i++){
        if(fechPrest[i]){
            creaBufferActualiza(fechPrest[i],codLibPrest[i],librosPedidos[i]);
        }
    }
    int carne,pos;
    char tipo,solicitud,codigo[15],*nomb;
    while(1){
        leeDatos(carne,tipo,solicitud,codigo,arch);
        if(arch.eof())break;
        pos=buscarCarne(carne,carneUs);
        if(pos!=-1){
            nomb = nombreUs[pos];
            procesaSolicitud(tipo,solicitud,codigo,fechPrest[pos],codLibPrest[pos],
                    codLibro,cantLibros,librosPedidos[pos],archRep,contador,nomb);
        }
    }
    for(int i=0;carneUs[i];i++){
        asignarEspaciosDinamicamente(fechPrest[i],codLibPrest[i],librosPedidos[i]);
    }
}

void asignarEspaciosDinamicamente(int *&fechPrest,char **&codLibPrest,int nd){
    int *auxInt = new int [nd+1]{};
    char **auxChar = new char *[nd+1]{};
    for(int i=0,nd=0;fechPrest[i];i++){
        if(fechPrest[i]!=-1){
            auxInt[nd]=fechPrest[i];
            auxChar[nd]=codLibPrest[i];
            nd++;
        }else{
            delete codLibPrest[i]; 
        }
    }
    delete fechPrest;
    delete codLibPrest;
    fechPrest = auxInt;
    codLibPrest = auxChar;
}

void creaBufferActualiza(int *&fechPrest,char **&codLibPrest,int &nd){
    int *auxint;
    char **auxChar;
    auxint = new int [100]{};
    auxChar = new char *[100]{};
    for(int i=0,nd=0;fechPrest[i];i++){
        auxint[i]=fechPrest[i];
        auxChar[i]=codLibPrest[i];
        nd++;
    }
    delete fechPrest;
    delete codLibPrest;
    fechPrest = auxint;
    codLibPrest = auxChar;
}

void procesaSolicitud(char tipo,char solicitud,char *codigo,
        int *&fechPest,char **&codLibPrest,char **&codLibro,int *&cantLibros,
        int &nd,ofstream &arch,int &contador,char *nomb){
    int pos,pos2,cuentaStock,noExcedePrestamos,nohayRetrasosDevolucion,noTieneLibro;
    arch<<setw(5)<<left<<contador<<left<<nomb<<endl;
    if(solicitud=='P'){
        pos=buscarLibro(codigo,codLibro);
        pos2=buscarLibro(codigo,codLibPrest);
        cuentaStock = cantLibros[pos]>0;
        noExcedePrestamos =noExcedePrestamosPermitidos(nd,tipo);
        nohayRetrasosDevolucion = noHayRetrasosDevolucion(fechPest,codLibPrest);
        noTieneLibro = (pos2==-1);
        imprimePrestamo(cuentaStock,noExcedePrestamos,nohayRetrasosDevolucion,
                noTieneLibro,fechPest[nd],codLibPrest[nd],nd,arch,codigo,contador,
                nomb);
    }else{
        pos=buscarLibro(codigo,codLibPrest);
        pos2=buscarLibro(codigo,codLibro);
        
        imprimirDevolucion(pos,cantLibros,fechPest,codLibPrest,nd,codigo,arch,pos2);
    }
    contador++;
}

void imprimirDevolucion(int pos,int *&cantLibros,int *&fechPest,
        char **&codLibPrest,int &nd,char *codigo,ofstream &arch,int pos2){
    if(pos!=-1){
        cantLibros[pos2]++;
        fechPest[pos]=-1;
        strcpy(codLibPrest[pos],"NOTFOUND");
        nd--;
        arch<<setw(5)<<left<<" "<<"Sin restricciones, se devolvió el libro No."
                <<codigo<<endl;
    }else{
        arch<<setw(5)<<left<<" "<<"No se pudo devolver el libro porque el usuario"
                "no habia solicitado el libro No."<<codigo<<endl;
    }
}

void imprimePrestamo(int cuentaStock,int noExcedePrestamos,int nohayRetrasosDevolucion,
                int noTieneLibro,int &fecha,char *&codLibPrest,int &nd,
        ofstream &arch,char *codigo,int contador,char *nomb){
    if(cuentaStock &&noExcedePrestamos &&nohayRetrasosDevolucion
            &&noTieneLibro){
        fecha=FECHACOMPARACION;
        codLibPrest=codigo;
        arch<<setw(5)<<left<<" "<<"Sin restricciones, se le entrego el libro No."
                <<codigo<<endl;
        nd++;
    }else{
        arch<<setw(5)<<left<<" "<<"No se le entrego el libro porque:"<<endl;
        if(!cuentaStock){
            arch<<setw(5)<<left<<" "<<"No cuenta con stock"<<endl;
        }
        if(!noExcedePrestamos){
             arch<<setw(5)<<left<<" "<<"Excede la cantidad de prestamos maxima"<<endl;
        }
        if(!nohayRetrasosDevolucion){
             arch<<setw(5)<<left<<" "<<"Tiene retrasos de devoluciones"<<endl;
        }
        if(!noTieneLibro){
             arch<<setw(5)<<left<<" "<<"Ya se retiro el libro pedido No."<<codigo<<endl;
        }
    }
}

int noHayRetrasosDevolucion(int *fechPest,char **codLibPrest){
    int diferencia;
    for(int i=0;fechPest[i];i++){
        if(fechPest[i]!=-1){
            diferencia = numeroDeDias(FECHACOMPARACION,FECHACOMPARACION);
            if(diferencia>0){
                return 0;
            }
        }
    }
    return 1;
}
int noExcedePrestamosPermitidos(int nd,char tipo){
    if(tipo=='E'){
        if(nd<=7)return 1;
        else return 0;
    }else if(tipo=='A'){
        if(nd<=3)return 1;
        else return 0;
    }else if(tipo=='D'){
        if(nd<=15)return 1;
        else return 0;
    }
}

void borraFecha(int fecha,int *&fechPest,char **&codLibPrest){
    int nd;
    for(nd=0;fechPest[nd];nd++);
    int *auxint,aux;
    char **auxChar;
    auxint = new int [nd]{};
    auxChar = new char *[nd]{};
    aux=nd;
    for(int i=0,nd=0;i<aux;i++){
        if(fechPest[i]==fecha)continue;
        auxint[nd]=fechPest[i];
        auxChar[nd]=codLibPrest[i];
        nd++;
    }
    delete fechPest;
    delete codLibPrest;
    fechPest = auxint;
    codLibPrest = auxChar;
}

int buscarLibro(char *codigo,char **codLibPrest){
    for(int i=0;codLibPrest[i];i++){
        if(strcmp(codigo,codLibPrest[i])==0)return i;
    }
    //cout<<"ERROR, no se encontro el codigo "<<codigo;
    return -1;
}
void leeDatos(int &carne,char &tipo,char &solicitud,char *codigo,ifstream &arch){
    char buff[30];
    arch>>carne>>tipo;
    if(arch.eof())return;
    arch.get();
    arch>>solicitud;
    arch.get();
    arch.getline(buff,30,'\n');
    strcpy(codigo,buff);
}