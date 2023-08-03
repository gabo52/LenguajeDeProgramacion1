/* 
 * File:   FuncionesEx01_20202_Preg02.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de octubre de 2022, 01:21 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEx01_20202_Preg02.h"
#define INCREMENTO 5
#define MAXCANTLINEA 100
using namespace std;

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

//21034000,Para tu sed,2012/06/02,1233,Gaseosa Koka Kola,20,2012/07/04,2344,Gaseosa Koka Kola Zero,50,2012/08/04,2344,Gaseosa Koka Kola Zero,50
//RUC, nombreTienda,(fecha, codigo, nombre, cantSol)
void leerDatos(char **&clientes,int ***&intProductos,char ***&strProductos){
    int nd=0,numProd[100]{},cap=0,capProd[100]{};
    ifstream arch;
    int ruc;
    char *nombTienda,c;
    AbrirArchivo("pedidos.csv",arch);
    clientes=nullptr;
    while(1){
        arch>>ruc>>c;
        if(arch.eof())break;
        nombTienda=leerCadena(arch,',');
        if(nd==cap)incrementaEspaciosCliente(clientes,intProductos,strProductos,nd,cap);
        agregaProductosACliente(intProductos[nd-1],strProductos[nd-1],arch);
        clientes[nd-1]=nombTienda;
        nd++;
    }
}

int leerFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>aa>>c>>mm>>c>>dd;
    return dd+mm*100+aa*10000;
}

void agregaProductosACliente(int **&intProductos,char **&strProductos,
        ifstream &arch){
    int numProd=0,capProd=0,fecha;
    int codigo,cantSol;
    char c,*nomb;
    intProductos=nullptr;
    while(1){
        fecha=leerFecha(arch);
        if(arch.eof())break;
        arch>>c>>codigo>>c;
        nomb=leerCadena(arch,',');
        arch>>cantSol;
        if(numProd==capProd)incrementaEspacioProd(intProductos,strProductos,numProd,capProd);
        agregaProductoAPedido(intProductos[numProd-1],strProductos[numProd-1],codigo,cantSol,nomb);
        numProd++;
        if(arch.get()=='\n')break;
    }
}

void agregaProductoAPedido(int *&intProductos,char *&strProductos,int codigo,
        int cantSol,char *nomb){
    int *aux;
    aux = new int [2];
    aux[0]=codigo;
    aux[1]=cantSol;
    intProductos=aux;
    strProductos=nomb;
}

void incrementaEspacioProd(int **&intProductos,char **&strProductos,int &numProd,int &capProd){
    capProd+=INCREMENTO;
    if(intProductos==nullptr){
        intProductos = new int *[capProd]{};
        strProductos = new char *[capProd]{};
        numProd=1;
    }else{
        int **auxIntProd;
        char **auxStrProductos;
        auxIntProd = new int *[capProd]{};
        auxStrProductos = new char *[capProd]{};
        for(int i=0;i<numProd;i++){
            auxIntProd[i]=intProductos[i];
            auxStrProductos[i]=strProductos[i];
        }
        delete intProductos;
        delete strProductos;
        intProductos=auxIntProd;
        strProductos=auxStrProductos;
    }
}

void incrementaEspaciosCliente(char **&clientes,int ***&intProductos,char ***&strProductos,
        int &nd,int &cap){
    cap+=INCREMENTO;
    if(clientes==nullptr){
        clientes = new char *[cap]{};
        intProductos = new int **[cap]{};
        strProductos = new char **[cap]{};
        nd=1;
    }else{
        int ***auxIntProd;
        char **auxClientes,***auxStrProductos;
        auxClientes = new char *[cap]{};
        auxIntProd = new int **[cap]{};
        auxStrProductos = new char **[cap]{};
        for(int i=0;i<nd;i++){
            auxClientes[i]=clientes[i];
            auxIntProd[i]=intProductos[i];
            auxStrProductos[i]=strProductos[i];
        }
        delete clientes;
        delete intProductos;
        delete strProductos;
        clientes=auxClientes;
        intProductos=auxIntProd;
        strProductos=auxStrProductos;
    }
}

char *leerCadena(ifstream &arch,char c){
    char *aux,buff[150];
    arch.getline(buff,150,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
void imprimirDatos(char **clientes,int ***intProductos,char ***strProductos){
    ofstream arch;
    AbrirArchivo("ReporteAtencion.txt",arch);
    for(int i=0;clientes[i];i++){
        ordenarProductos(intProductos[i],strProductos[i]);
    }
    arch<<setw(60)<<right<<"REPORTE DE ATENCION"<<endl;
    for(int i=0;clientes[i];i++){
        imprimirReporte(clientes[i],intProductos[i],strProductos[i],arch);
    }
}

void imprimirReporte(char *cliente,int **productos,char **nombProd,ofstream &arch){
    arch<<"Cliente : "<<left<<cliente<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<"  Cod. Producto   "<<setw(50)<<left<<"Producto"<<setw(20)<<left
            <<"Cant. Solicitada"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    for(int i=0;productos[i];i++){
        imprimeRegReporte(productos[i],nombProd[i],arch);
    }
    arch<<endl;
}

void imprimeRegReporte(int *productos,char *nombProd,ofstream &arch){
    arch<<setw(10)<<right<<productos[0]<<"        "<<setw(50)<<left<<nombProd<<
            setw(10)<<right<<productos[1]<<endl;
}

void imprimeLinea(ofstream &arch,int cantidad,char c){
    for(int i=0;i<cantidad;i++)arch<<c;
    arch<<endl;
}

void ordenarProductos(int **&intProductos,char **&strProductos){
    int nd=0;
    for(int i=0;intProductos[i];i++)nd++;
    qSort(intProductos,strProductos,0,nd-1);
}

void qSort(int **&intProductos,char **&strProductos,int izq,int der){
    int limite;
    if (izq>=der) return;
     // Ponemos el elemento pivot al inicio
    cambiar(intProductos,strProductos,izq,(izq+der)/2);
    limite = izq;
    for(int i=izq+1; i<=der; i++){
        if(enDesorden(intProductos[i],intProductos[izq])){
            cambiar(intProductos,strProductos,++limite,i);
            
        }
    }
    cambiar(intProductos,strProductos,izq,limite);
    qSort(intProductos,strProductos,izq, limite-1);
    qSort(intProductos,strProductos,limite+1,der);

}

int enDesorden(int *int1,int *int2){
    return int1[1]<int2[1];
}

void cambiar(int **&intProductos,char **&strProductos,int pos1,int pos2){
    int *auxInt;
    char *auxChar;
    auxInt=intProductos[pos1];
    auxChar=strProductos[pos1];
    
    intProductos[pos1]=intProductos[pos2];
    strProductos[pos1]=strProductos[pos2];
    
    intProductos[pos2]=auxInt;
    strProductos[pos2]=auxChar;
}