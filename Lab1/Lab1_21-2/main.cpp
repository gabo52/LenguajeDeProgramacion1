/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 29 de agosto de 2022, 10:41 AM
 */

#include <iostream>
#include <iomanip>
#define MAXCANTLINEA 120
using namespace std;

/*
 * 
 */

void leeFecha(int &fecha){
    int dd,mm,aa;
    char c;
    cin>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}

void leerFechas(int &fecha1,int &fecha2,int &fecha3){
    leeFecha(fecha1);
    leeFecha(fecha2);
    leeFecha(fecha3);
}

void imprimeLinea(char c,int cant){
    for(int i=0;i<cant;i++)cout<<c;
    cout<<endl;
}
void leeLibro(char *codLib,int &fechaLib,double &valor){
    char c;
    int dd,mm,aa;
    cin>>codLib>>dd>>c>>mm>>c>>aa>>valor;
    fechaLib=dd+mm*100+aa*10000;
}

void hallaFecha(int &dd,int &mm,int &aa,int fecha){
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    fecha/=100;
    aa=fecha;
}
void imprimeFecha(int fecha){
    int dd,mm,aa;
    hallaFecha(dd,mm,aa,fecha);
    cout<<setfill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa;
    cout<<setfill(' ');
}

void imprimeTipo(char letra){
    switch(letra){
        case 'A':
            cout<<setw(20)<<"Administrativo";
            return;
        case 'D':
            cout<<setw(20)<<"Docente";
            return;
        case 'E':
            cout<<setw(20)<<"Estudiante";
            return;
    }
}
void imprimeCabeceraUsuario(char *nombre,char *codLib,int fechaLib,double valor,
        int carne,char letra){
    cout<<setw(22)<<right<<"USUARIO"<<setw(55)<<right<<"LIBROS PRESTADOS"<<endl;
    imprimeLinea('-',MAXCANTLINEA);
    cout<<setw(15)<<left<<"Carne No."<<setw(40)<<left<<"Nombre"<<setw(20)<<left
            <<"Tipo"<<setw(12)<<left<<"Codigo"<<setw(15)<<left<<"F. de retiro"
            <<left<<"Observacion"<<endl;
    imprimeLinea('-',MAXCANTLINEA);
    //Imprimimos el nombre de la persona con su tipo
    cout<<setw(15)<<left<<carne<<setw(40)<<left<<nombre;
    imprimeTipo(letra);
}

void imprimeCabecera(int fecha1,int fecha2,int fecha3){
    cout<<setw(75)<<right<<"BIBLIOTECA GENERAL DE LA UNIVERSIDAD"<<endl;
    imprimeLinea('=',MAXCANTLINEA);
    
    cout<<"Fechas limite de devolucion"<<endl;
    cout.width(7);
    cout<<setw(15)<<left<<"Docentes";
    imprimeFecha(fecha1);
    cout<<endl;
    cout<<setw(15)<<left<<"Estudiantes";
    imprimeFecha(fecha2);
    cout<<endl;
    cout<<setw(15)<<left<<"Administrativo";
    imprimeFecha(fecha3);
    cout<<endl;
    imprimeLinea('-',MAXCANTLINEA);
}

int fechaUsuario(int fechaDoc,int fechaEst,int fechaAdmin,char letra){
    switch(letra){
        case 'A':
            return fechaAdmin;
        case 'D':
            return fechaDoc;
        case 'E':
            return fechaEst;
    }
    return 0;
}
void imprimeLibro(char *codLib,int fechaLib,double valor,int fechaDoc,
        int fechaEst,int fechaAdmin,char letra,int &flag,int &cantLib,double &totMul){
    cout<<setw(12)<<left<<codLib;
    imprimeFecha(fechaLib);
    flag=1;
    cout<<"     ";
    if(fechaUsuario(fechaDoc,fechaEst,fechaAdmin,letra)>fechaLib){
        cout<<left<<"EN DEUDA"<<endl;
        cout<<setw(111)<<right<<"Multa: $ "<<setprecision(2)<<fixed<<valor<<endl;
        totMul+=valor;cantLib++;
    }else cout<<"--"<<endl;
}

void imprimeResumen(int &cantLib,double &totMul){
    imprimeLinea('=',MAXCANTLINEA);
    cout.width(6);
    cout<<setw(20)<<left<<"Cantidad de libros adeudados:"<<setw(8)<<right<<cantLib<<endl;
    cout<<setw(20)<<left<<"Total de deudas por multa:";
    cout<<setw(14)<<setprecision(2)<<fixed<<right<<totMul<<endl;
    cantLib=0;
    totMul=0;
    imprimeLinea('=',MAXCANTLINEA);
    imprimeLinea('/',MAXCANTLINEA);
    imprimeLinea('=',MAXCANTLINEA);
}
int main(int argc, char** argv) {
    int fecha1,fecha2,fecha3,carnet,fechaLib,cantLib=0,carne,flag=0;
    char letra,nombre[100],codLib[10];
    double valor,totDeuda=0,totMul=0;
    leerFechas(fecha1,fecha2,fecha3);
    imprimeCabecera(fecha1,fecha2,fecha3);
    while(1){
        cin>>carne>>letra;
        if(cin.eof()){
            imprimeResumen(cantLib,totMul);
            break;
        }
        if(cin.fail()){
            //Sigue leyendo libros
            cin.clear();
            leeLibro(codLib,fechaLib,valor);
            cout<<setw(75)<<" ";
            imprimeLibro(codLib,fechaLib,valor,fecha1,fecha2,fecha3,letra,flag,cantLib,totMul);
        }else{
            //Lee libros de un nuevo usuario
            if(flag)imprimeResumen(cantLib,totMul);
            cin>>nombre;
            leeLibro(codLib,fechaLib,valor);
            imprimeCabeceraUsuario(nombre,codLib,fechaLib,valor,carne,letra);
            imprimeLibro(codLib,fechaLib,valor,fecha1,fecha2,fecha3,letra,flag,cantLib,totMul);
        }
    }
    return 0;
}

