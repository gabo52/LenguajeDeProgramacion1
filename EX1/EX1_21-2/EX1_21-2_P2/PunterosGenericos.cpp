/* 
 * File:   PunterosGenericos.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 10 de octubre de 2022, 07:43 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"
#include "imprimevoid.h"
using namespace std;

void imprimeregistro(ofstream &arch,void*registro){
    void **lregistro=(void**)registro;
    char *codigo,*nombre,*autor;
    int *stock,*copias;
    double *precio;
    
    codigo=(char*)lregistro[0];
    nombre=(char*)lregistro[1];
    autor=(char*)lregistro[2];
    copias=(int*)lregistro[3];
    stock=(int*)lregistro[4];
    precio=(double*)lregistro[6];    
    
    arch << codigo <<" "<<nombre<<" "<<autor;
    arch <<" "<<*copias<<" "<<*stock<<" "<<*precio<<endl;
    
}

void imprimeLibros(void *stock){
    int i=0;
    void **lstock=(void**)stock;
    ofstream arch("Reprueba.txt",ios::out);
    if(!arch){
       cout << "No se puede leer Reprueba.txt"; 
       exit(1);
    }    
    while(lstock[i]){
        imprimeregistro(arch,lstock[i]);
        i++;
    }
}

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

void cargalibros(void *&st){
    ifstream arch;
    AbrirArchivo("libros2.csv",arch);
    void **stock,*buffSt[200];
    int nd=0;
    while(1){
        cout<<"owo "<<nd+1<<endl;
        buffSt[nd]=leerRegLib(arch);
        if(arch.eof())break;
        nd++;
    }
    stock =  new void *[nd+1]{};
    for(int i=0;i<nd;i++){
        stock[i]=buffSt[i];
    }
    
    st=stock;
    imprimeLibros(st);
}
//KC34197,Las_demoliciones_de_Paris,Zkenia/Chung/Zuniga,2014,15,294.26
//codigo,ttulo,autor,edicion,stock,precio
void *leerRegLib(ifstream &arch){
    void **stock;
    char *codigo,*titulo,*autor,c;
    int edicion,*edicionP,*stockP,*cantidadP;
    double *precioP;
    codigo=leerCadena(arch,',');
    if(arch.eof())return nullptr;
    titulo=leerCadena(arch,',');
    autor=leerCadena(arch,',');
    edicionP = new int;
    stockP = new int;
    precioP = new double;
    arch>>*edicionP>>c>>*stockP>>c>>*precioP;
    arch.get();
    cantidadP = new int;
    *cantidadP = *stockP;
    stock = new void *[7];
    stock[0]=codigo;
    stock[1]=titulo;
    stock[2]=autor;
    stock[3]=cantidadP;
    stock[4]=stockP;
    stock[5]=crea3erNivel(*stockP);
    stock[6]=precioP;
    return stock;
}

void *crea3erNivel(int numStock){
    void **aux;
    cout<<numStock<<endl;
    aux = new void *[numStock+1]{};
    for(int i=0;i<numStock;i++){
        aux[i]=creaDinamico4toNivel(i+1);
    }
    return aux;
}

void *creaDinamico4toNivel(int num){
    void **aux;
    int *ncopiaP;
    char *estado;
    int *fechaP;
    double *valorP;
    ncopiaP = new int;
    estado = new char[15];
    fechaP = new int;
    valorP = new double;
    strcpy(estado,"Disponible");
    *ncopiaP = num+1;
    *fechaP = 0;
    *valorP = 0;  
    aux = new void *[4];
    aux[0]=ncopiaP;
    aux[1]=estado;
    aux[2]=fechaP;
    aux[3]=valorP;
    return aux;
}
char *leerCadena(ifstream &arch,char c){
    char buff[200],*aux;
    arch.getline(buff,200,c);
    if(arch.eof())return nullptr;
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
//26916299E,SK15788,10,17/09/2021
//carnetipo,codLib,numCop,fechaRet
void actualiza(void *&st){
    ifstream arch;
    AbrirArchivo("RegistroDePrestamos2.csv",arch);
    void **stock = (void **)st,*nivel3;
    int carne,pos,nCopia,fecha,*disponible;
    char *codLib,tipo,c;
    double precio;
    while(1){
        cout<<"unu";
        arch>>carne>>tipo>>c;
        if(arch.eof())break;
        codLib=leerCadena(arch,',');
        arch>>nCopia>>c;
        fecha=leerFecha(arch);
        pos = buscarCodLib(codLib,stock,disponible,nivel3,nCopia,precio);
        if(pos!=-1&&(*disponible)>0){
            (*disponible)--;
            actualiza4toNivel(nivel3,fecha,precio);
        }
        cout<<"cout";
    }
}

void actualiza4toNivel(void *&nivel3,int fecha,double precio){
    void **nivel4=(void**)nivel3;
    int *fechaP,mm=obtieneMes(fecha);
    char *estado;
    double *monto;
    estado = (char *)nivel4[1];
    fechaP = (int *)nivel4[2];
    monto = (double *)nivel4[3];
    if(mm-8>=2){
        strcpy(estado,"Perdida");
        *monto = precio;
    }else{
        strcpy(estado,"Prestamo");
    }
    *fechaP=fecha;
}

int obtieneMes(int fecha){
    fecha/=100;
    return fecha%100;
}

int buscarCodLib(char *codLib,void **stock,int *&disponible,void *&nivel3,
        int nCopia,double &precio){
    for(int i=0;stock[i];i++){
        if(comparaLibro(codLib,stock[i],disponible,nivel3,nCopia,precio))return i;
    }
    cout<<"ERROR, no se pudo encontrar el libro"<<codLib;
    return -1;
}

int comparaLibro(char *codLib,void *st,int *&disponible,void *&nivel3,int nCopia,
        double &precio){
    void **stock=(void **)st;
    char *aux;
    aux = (char *)stock[0];
    if(strcmp(codLib,aux)==0){
        disponible = (int *)stock[3];
        double *auxPrec=(double *)stock[6];
        nivel3 = buscaNCopia(stock[5],nCopia);
        precio=*auxPrec;
        return 1;
    }
    return 0;
}

void *buscaNCopia(void *st,int nCopia){
    void **stock =(void**)st;
    if(stock[nCopia-1]==nullptr){
        cout<<"ERROR, LA COPIA NO SE ENCUENTRA";
    }
    return stock[nCopia-1];
}

int leerFecha(ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    return dd+mm*100+aa*10000;
}

void imprimestock(void *&st){
    ofstream arch;
    AbrirArchivo("ReporteStock.txt",arch);
    arch<<"  "<<setw(15)<<left<<"COD: DE LIB"<<"  "<<setw(40)<<left<<
            "Titulo"<<setw(40)<<left<<"Autor"<<setw(24)<<left
            <<"# Copias"<<left<<"Stock"<<endl;
    void **stock=(void **)st;
    for(int i=0;stock[i];i++){
        imprimeStockLibro(stock[i],arch);
    }
}

void imprimeStockLibro(void *&st,ofstream &arch){
    void **stock=(void **)st;
    char *cod,*titulo,*autor;
    int *ncopia,*cantstock;
    cod = (char *)stock[0];
    titulo = (char *)stock[1];
    autor = (char *)stock[2];
    ncopia = (int *)stock[3];
    cantstock = (int *)stock[4];
    arch<<"  "<<setw(15)<<left<<cod<<"  "<<setw(40)<<left<<
            titulo<<setw(44)<<left<<autor<<setw(22)<<left
            <<*ncopia<<left<<*cantstock<<endl;
    imprimeDetalleCopias(stock[5],arch);
}
void imprimeDetalleCopias(void *st,ofstream &arch){
    void **stock=(void **)st;
    arch<<"Detalle de copias"<<endl;
    for(int i=0;stock[i];i++){
        imprimeDetalleUnaCopia(stock[i],i,arch);
    }
    arch<<endl;
}

void imprimeDetalleUnaCopia(void *st,int i,ofstream &arch){
    void **stock=(void **)st;
    char *estado=(char *)stock[1];
    int *fecha=(int *)stock[2];
    double *monto=(double *)stock[3];
    arch<<"      "<<setw(7)<<left<<i+1;
    arch<<setw(40)<<left<<estado;
    if(*fecha==0){
        arch<<endl;
    }else{
        imprimeFecha(*fecha,arch);
        if(*monto>0){
            arch<<setw(15)<<right<<setprecision(2)<<fixed<<*monto<<endl;
        }else{
            arch<<endl;
        }
    } 
    
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    char c;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<setfill(' ');
}