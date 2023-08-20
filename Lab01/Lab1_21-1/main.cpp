/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de agosto de 2022, 11:26 AM
 */

#include <iostream>
#include <iomanip>
#define MAXCANTLINEA 120
#define leve 5
#define grave 70
#define muyGrave 120
using namespace std;

/*
 * 
 */

void leerFecha(int &dd,int &mm,int &aa){
    int temp;
    dd=mm=aa=-1;
    while(1){
        cin>>temp;
        if(cin.fail()){
            cin.clear();
            break;
        }
        dd=mm;
        mm=aa;
        aa=temp;
    }
}
void imprimeLinea(char c,int cant){
    for(int i=0;i<cant;i++)cout<<c;
    cout<<endl;
}
void imprimeCabeceraConductor(){
    imprimeLinea('=',MAXCANTLINEA);
    cout<<setw(20)<<fixed<<"CONDUCTOR"<<setw(50)<<"INFRACCIONES"<<endl;
    imprimeLinea('-',MAXCANTLINEA);
    cout<<left<<setw(50)<<"Licencia No. Nombre"<<setw(7)<<"Placa"<<setw(10)<<right<<"Fecha"
            <<setw(12)<<right<<"Codigo"<<setw(12)<<right<<"Gravedad"<<setw(12)
            <<right<<"Puntos"<<setw(9)<<right<<"Multa"<<endl;
    imprimeLinea('-',MAXCANTLINEA);
}
void imprimir(int licencia,char *nombre){
    cout <<setw(13)<<fixed<<licencia << nombre <<left<< endl;
    
}

void imprimeCabecera(){
    cout<<setw(80)<<"REGULADORA DE TRANSPORTE URBANO"<<endl;
}

void imprimeTotalMultasTipo(string descripcion,int cantidad,double totPago,
        double totPuntos){
    cout <<left<<setw(28)<<descripcion<<setw(12)<<cantidad<<setw(14)<<right
            <<totPago<<setw(19)<<right<<totPuntos<<endl;
}
void imprimeResumen(int cantLeves,int cantGraves,int cantMGraves,double pagoLeves,
        double pagoGraves,double pagoMGraves,int puntosLeves,int puntosGraves,
        int puntosMGraves){
    double total;
    imprimeLinea('=',MAXCANTLINEA);
    cout <<"RESUMEN:"<<endl;
    cout << setw(25)<<left<<"Gravedad"<< setw(15)<<left<<"Cantidad"<< setw(18)
            <<left<<"Multas Pagadas"<<left<<"Puntos Perdidos"<<endl;
    imprimeTotalMultasTipo("Multas leves",cantLeves,pagoLeves,puntosLeves);
    imprimeTotalMultasTipo("Multas graves",cantGraves,pagoGraves,puntosGraves);
    imprimeTotalMultasTipo("Multas muy graves",cantMGraves,pagoMGraves,puntosMGraves);
    total=pagoLeves+pagoGraves+pagoMGraves;
    imprimeLinea('-',MAXCANTLINEA);
    cout << "Total: "<<total<<endl;
    imprimeLinea('=',MAXCANTLINEA);
    imprimeLinea('/',MAXCANTLINEA);
}

void imprimeGravedad(char gravedad,double multa,int &cantLeve,int &cantGrave,
        int &cantMGrave,double &pagoLeve,double &pagoGrave,double &pagoMGrave,
        int &puntosLeve,int &puntosGrave,int &puntosMGrave){
    switch(gravedad){
        case 'L':
            cantLeve++;
            pagoLeve+=multa;
            puntosLeve+=leve;
            cout<<setw(12)<<"Leve"<<setw(6)<<right<<leve;
            break;
        case 'G':
            cantGrave++;
            pagoGrave+=multa;
            puntosGrave+=grave;
            cout<<setw(12)<<"Grave"<<setw(6)<<right<<grave;
            break;
        case 'M':
            cantMGrave++;
            pagoMGrave+=multa;
            puntosMGrave+=muyGrave;
            cout<<setw(12)<<"Muy Grave"<<setw(6)<<right<<muyGrave;
            break;
    }
}

void imprimeFecha(int dd,int mm,int aa){
    cout.fill('0');
    if(dd!=-1)cout<<right<<setw(2)<<setprecision(2)<<fixed<<dd;
    else cout<<"--";
    cout<<"/";
    if(mm!=-1)cout<<right<<setw(2)<<setprecision(2)<<fixed<<mm;
    else cout<<"--";
    cout<<"/";
    cout<<setfill(' ');
    if(aa!=-1)cout<<setw(8)<<setprecision(4)<<left<<aa;
    else cout<<"----"<<setw(8)<<left;
}
void imprimePlaca(int flag1,int licencia,char *nombre,char *placa,int dd,int mm,
        int aa,int codigo,char gravedad,double multa,int &cantLeve,int &cantGrave,
        int &cantMGrave,double &pagoLeve,double &pagoGrave,double &pagoMGrave,
        int &puntosLeve,int &puntosGrave,int &puntosMGrave){
    if(!flag1){
        cout<<setw(13)<<left<<licencia<<setw(37)<<left<<nombre<<setw(10)
                <<left<<placa;
    }
    else{
        cout<<setw(57)<<right<<placa<<"   ";
    }
    imprimeFecha(dd,mm,aa);
    cout<<setw(11)<<left<<codigo;
    imprimeGravedad(gravedad,multa,cantLeve,cantGrave,cantMGrave,pagoLeve,pagoGrave,
                    pagoMGrave,puntosLeve,puntosGrave,puntosMGrave);
    cout<<setw(9)<<right<<setprecision(2)<<fixed<<multa<<endl;
}

void reseteaContadores(int &cantLeve,int &cantGrave,int &cantMGrave,double &pagoLeve,
        double &pagoGrave,double &pagoMGrave,int &puntosLeve,int &puntosGrave,int &puntosMGrave){
    cantLeve=cantGrave=cantMGrave=0;
    pagoGrave=pagoMGrave=pagoLeve=0;
    puntosLeve=puntosGrave=puntosMGrave=0;
}
int main(int argc, char** argv) {
    char nombre[100],placa[10],gravedad,texto[15];
    int dia,mes,anio,licencia,flag1=0,flag2=0,codigo,backup;
    double multa,pagoLeve,pagoGrave,
                    pagoMGrave;
    int cantGrave=0,cantLeve=0,cantMGrave=0,puntosLeve=0,puntosGrave=0,puntosMGrave=0;
    imprimeCabecera();
    while(1){
        cin>>licencia;
        if(cin.eof()){
            imprimeResumen(cantLeve,cantGrave,cantMGrave,pagoLeve,pagoGrave,
                    pagoMGrave,puntosLeve,puntosGrave,puntosMGrave);
            break;
        }
        if(cin.fail()){
            cin.clear();
            cin >> placa;
            leerFecha(dia,mes,anio);
            cin >>gravedad>>codigo>>texto>>multa;
            imprimePlaca(flag1,backup,nombre,placa,dia,mes,anio,codigo,gravedad,
                    multa,cantLeve,cantGrave,cantMGrave,pagoLeve,pagoGrave,
                    pagoMGrave,puntosLeve,puntosGrave,puntosMGrave);
            flag1=1;
        }else{
            flag1=0;backup=licencia;
            if(flag2)imprimeResumen(cantLeve,cantGrave,cantMGrave,pagoLeve,pagoGrave,
                    pagoMGrave,puntosLeve,puntosGrave,puntosMGrave);
            reseteaContadores(cantLeve,cantGrave,cantMGrave,pagoLeve,pagoGrave,
                    pagoMGrave,puntosLeve,puntosGrave,puntosMGrave);
            cin>>nombre;flag2=1;
            imprimeCabeceraConductor();
        }
    }
    cout <<endl<<"Hola";
    return 0;
}

