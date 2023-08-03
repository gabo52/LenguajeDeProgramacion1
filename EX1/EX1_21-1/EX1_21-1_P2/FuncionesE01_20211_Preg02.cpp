/* 
 * File:   FuncionesE01_20211_Preg02.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 9 de octubre de 2022, 08:12 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Imprime_Examen01_2021_1.h"
#include "FuncionesE01_20211_Preg02.h"
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

void cargaDatos(void *&conductor,void *&falta){
    cargaConductor(conductor);
    cargaFaltas(falta);
    cout<<"Llegue";
    imprimeconductor(conductor);
    imprimefalta(falta);
}

void cargaConductor(void *&conduc){
    ifstream arch;
    void **conductor;
    AbrirArchivo("Conductores.csv",arch);
    void *buffConductor[200];
    int nd=0;
    while(1){
        buffConductor[nd]=leeConductor(arch);
        if(arch.eof())break;
        nd++;
    }
    conductor= new void *[nd+1]{};
    for(int i=0;i<nd;i++){
        conductor[i]=buffConductor[i];
    }
    conduc=conductor;
}
//39244942,PENA SUAREZ GLENDA MARGOT
//licencia,nombre conductor 
void *leeConductor(ifstream &arch){
    int licencia,*licP;
    char *nomb;
    arch>>licencia;
    if(arch.eof())return nullptr;
    arch.get();
    nomb=leerCadena(arch,'\n');
    void **aux;
    aux = new void *[2];
    licP = new int;
    *licP = licencia;
    aux[0]=licP;
    aux[1]=nomb;
    return aux;
}

char *leerCadena(ifstream &arch,char c){
    char buff[300],*aux;
    arch.getline(buff,300,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}
void cargaFaltas(void *&falt){
    ifstream arch;
    AbrirArchivo("Infracciones.csv",arch);
    void *buffFalta[200],**falta;
    int nd=0;
    while(1){
        buffFalta[nd]=leeRegFalta(arch);
        if(arch.eof())break;
        nd++;
    }
    falta = new void *[nd+1]{};
    for(int i=0;i<nd;i++)falta[i]=buffFalta[i];
    falt=falta;
}

void *leeRegFalta(ifstream &arch){
    char *desc,c,buff[30];
    int codigo,*PCodigo;
    double precio,*precioP;
    arch>>codigo;
    if(arch.eof())return nullptr;
    arch>>c;
    desc = leerCadena(arch,',');
    arch.getline(buff,30,',');
    arch>>precio;
    precioP= new double;
    PCodigo = new int;
    *precioP = precio;
    *PCodigo=codigo;
    void **aux;
    aux = new void *[3];
    aux[0]=PCodigo;
    aux[1]=desc;
    aux[2]=precioP;
    return aux;
}
    

//Consolidado
//licencia, nombre,aa,mm,monto
//81485316,J5T-691,24/12/2020,128
//licencia,placa,fecha,infraccion
void registrafaltas(void *&aux,void *&conductor,void *&falta){
    ifstream arch;
    AbrirArchivo("registrodefaltas.csv",arch);
    void *buffConsolidado[500],**consolidado;
    int licencia,*mm,*aa,infraccion,pos,nd=0;
    while(1){
        leerDatos(licencia,mm,aa,infraccion,arch);
        if(arch.eof())break;
        pos=buscaConsolidado(buffConsolidado,nd,licencia,*mm,*aa);
        if(pos!=-1){
            agregaMonto(buffConsolidado[pos],infraccion,falta);
            delete mm;
            delete aa;
        }else{
            creaConsolidado(buffConsolidado[nd],licencia,mm,aa,infraccion,conductor,falta);
            nd++;
        }
    }
    consolidado = new void *[nd+1]{};
    for(int i=0;i<nd;i++){
        consolidado[i]=buffConsolidado[i];
    }
    aux=consolidado;
}

void creaConsolidado(void *&Consolidado,int licencia,int *mm,int *aa,
        int infraccion,void *conductor,void *falta){
    void **aux;
    aux = new void *[5];
    int *licenciaP;
    char *nomb;
    licenciaP = new int;
    *licenciaP;
    buscaConductor(licencia,conductor,nomb,licenciaP);
    double *montoP;
    montoP = new double;
    (*montoP)= hallaCostoInfraccion(infraccion,falta);
    aux[0]=licenciaP;
    aux[1]=nomb;
    aux[2]=aa;
    aux[3]=mm;
    aux[4]=montoP;
    Consolidado = aux;
}

void buscaConductor(int licencia,void *conduct,char *&nomb,int *&licenciaP){
    void **conductor=(void **)conduct;
    for(int i=0;conductor[i];i++){
        if(comparaConductor(licencia,conductor[i],nomb,licenciaP))return;
    }
    cout<<"ERROR, no se encontro la licencia "<<licencia;
}

int comparaConductor(int licencia,void *conduct,char *&nomb,int *&licenciaP){
    void **conductor=(void **)conduct;
    int *licenc;
    licenc = (int *)conductor[0];
    if(*licenc==licencia){
        licenciaP=licenc;
        nomb = (char *)conductor[1];
        return 1;
    }
    return 0;
}

void agregaMonto(void *&buff,int infraccion,void *falta){
    void **NBuff=(void **)buff;
    double *monto;
    monto = (double *)NBuff[4];
    (*monto)+=hallaCostoInfraccion(infraccion,falta);
}

double hallaCostoInfraccion(int infraccion,void *fault){
    void **falta = (void**)fault;
    double monto;
    for(int i=0;falta[i];i++){
        if(comparaInfraccion(infraccion,falta[i],monto))return monto;
    }
    cout<<"ERROR, no se encontro la infraccion "<<infraccion;
    return 0;
}

int comparaInfraccion(int &infraccion,void *fault,double &monto){
    void **falta=(void**)fault;
    double *aux;
    int *codigo;
    codigo = (int *)falta[0];
    if(*codigo==infraccion){
        aux=(double *)falta[2];
        monto=(*aux);
        return 1;
    }
    return 0;
}
int buscaConsolidado(void **buffConsolidado,int nd,int licencia,int mm,int aa){
    for(int i=0;i<nd;i++){
        if(comparaConsolidado(buffConsolidado[i],licencia,mm,aa))return i;
    }
    return -1;
}

int comparaConsolidado(void *aux,int licencia,int mm,int aa){
    void **consolidado=(void **)aux;
    int *auxmm,*auxaa,*auxLicencia;
    auxLicencia = (int *)consolidado[0];
    auxmm = (int *)consolidado[3];
    auxaa = (int *)consolidado[2];
    return (*auxLicencia==licencia)&&(*auxmm==mm)&&(*auxaa==aa);
}
void leerDatos(int &licencia,int *&mm,int *&aa,int &infraccion,ifstream &arch){
    char c;
    arch>>licencia>>c;
    if(arch.eof())return;
    char buff[100];
    arch.getline(buff,100,',');
    int auxDD,auxMM,auxAA;
    arch>>auxDD>>c>>auxMM>>c>>auxAA>>c>>infraccion;
    mm = new int;
    aa = new int;
    *mm = auxMM;
    *aa = auxAA;
}

void imprime(void *aux){
    ofstream arch;
    AbrirArchivo("ReporteConsolidado.txt",arch);
    void **consolidado=(void **)aux;
    ordenaConsolidado(consolidado);
    int lic=1,licAnt=-1,flag=0;
    char *nomb;
    for(int i=0;consolidado[i];i++){
        lic=obtieneLicencia(consolidado[i],nomb);
        if(lic!=licAnt){
            if(flag)arch<<endl;
            flag=1;
            imprimeCabecera(lic,nomb,arch);
        }
        imprimeRegConsolidado(consolidado[i],arch);
        licAnt=lic;
    }
}

void ordenaConsolidado(void **&consolidado){
    int nd=0;
    for(int i=0;consolidado[i];i++)nd++;
    qSort(consolidado,0,nd-1);
}

void qSort(void **consolidado,int izq,int der){
    int limite;
    if (izq>=der) return;
    // Ponemos el elemento pivot al inicio
    cambiar(consolidado[izq],consolidado[(izq+der)/2]);
    limite = izq;
    for(int i=izq+1; i<=der; i++){
         if(enDesorden(consolidado[i],consolidado[izq])){
              cambiar(consolidado[++limite], consolidado[i]);
         }
    }
    cambiar(consolidado[izq], consolidado[limite]);
    qSort(consolidado,izq, limite-1);
    qSort(consolidado,limite+1,der);
}

int enDesorden(void *aux1,void *aux2){
    void **consolidado1=(void **)aux1,**consolidado2=(void **)aux2;
    int *licP1=(int *)consolidado1[0],*mm1=(int *)consolidado1[3],*aa1=(int *)consolidado1[2];
    int *licP2=(int *)consolidado2[0],*mm2=(int *)consolidado2[3],*aa2=(int *)consolidado2[2];
    return ((*licP2)>(*licP1))||((*licP1)==(*licP2) && (*aa2)>(*aa1))||
            ((*licP1)==(*licP2) && (*aa2)==(*aa1) && (*mm2)>(*mm1));
}

void cambiar(void *&dato1,void *&dato2){
    void *aux;
    aux=dato1;
    dato1=dato2;
    dato2=aux;
}

int obtieneLicencia(void *aux,char *&nomb){
    void **consolidado=(void **)aux;
    int *lic;
    lic = (int *)consolidado[0];
    nomb = (char *)consolidado[1];
    return *lic;
}

void imprimeCabecera(int lic,char *nomb,ofstream &arch){
    arch<<setw(10)<<left<<"Licencia: "<<setw(15)<<left<<lic<<setw(15)<<left<<
            "Nombre: "<<left<<nomb<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(15)<<left<<"Anio"<<setw(15)<<left<<"Mes"<<setw(25)<<left<<"Monto"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimeRegConsolidado(void *aux,ofstream &arch){
    void **consolidado=(void **)aux;
    int *aa=(int *)consolidado[2],*mm=(int *)consolidado[3];
    double *monto = (double *)consolidado[4];
    arch<<setw(16)<<left<<*aa<<setw(2)<<setfill('0')<<right<<*mm<<setfill(' ')<<setw(18)<<right<<setprecision(2)<<fixed<<*monto<<endl;
}

