/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 30 de agosto de 2022, 05:13 PM
 */

#include <iostream>
#include <iomanip>
#define MAXCANTLINEA 110
using namespace std;

/*
 * 
 */

void imprimeLinea(char c,int cant){
    for(int i=0;i<cant;i++)cout<<c;
    cout<<endl;
}

void imprimeCabecera(){
    cout<<left<<"ESTADO DE CUENTAS DEL BANCO ABCD"<<endl;
    imprimeLinea('=',MAXCANTLINEA);
}

void imprimeCantYTipoMoneda(char letra,double saldoIni){
    switch(letra){
        case '$':
            cout<<setw(15)<<left<<"Dolar "<<setw(15)<<right<<setprecision(2)<<fixed<<saldoIni<<endl;
            imprimeLinea('=',MAXCANTLINEA);
            cout<<setw(15)<<left<<"FECHA"<<setw(25)<<left<<"RETIROS DOLARES"<<setw(25)<<left<<"DEPOSITOS DOLARES"<<
            setw(25)<<left<<"SALDO DOLARES"<<left<<"OBSERVACION"<<endl;
            return;
        case '&':
            cout<<setw(15)<<left<<"Euros "<<setw(15)<<right<<setprecision(2)<<fixed<<saldoIni<<endl;
            imprimeLinea('=',MAXCANTLINEA);
            cout<<setw(15)<<left<<"FECHA"<<setw(25)<<left<<"RETIROS EUROS"<<setw(25)<<left<<"DEPOSITOS EUROS"<<
            setw(25)<<left<<"SALDO EUROS"<<left<<"OBSERVACION"<<endl;
            return;
        case 'S':
            cout<<setw(15)<<left<<"Soles "<<setw(15)<<right<<setprecision(2)<<fixed<<saldoIni<<endl;
            imprimeLinea('=',MAXCANTLINEA);
            cout<<setw(15)<<left<<"FECHA"<<setw(25)<<left<<"RETIROS SOLES"<<setw(25)<<left<<"DEPOSITOS SOLES"<<
            setw(25)<<left<<"SALDO SOLES"<<left<<"OBSERVACION"<<endl;
            return;
    }
    imprimeLinea('-',MAXCANTLINEA);
}


void imprimeCabeceraCliente(char *nombre,int codCuen,char letra,double saldoIni){
    cout<<setw(50)<<left<<"CLIENTE"<<setw(25)<<left<<"CODIGO DE CUENTA"
            <<setw(20)<<left<<"MONEDA"<<left<<"SALDO INICIAL"<<endl;
    cout<<setw(58)<<left<<nombre<<setw(17)<<left<<codCuen;
    imprimeCantYTipoMoneda(letra,saldoIni);
}

double hallarCantDolar(double saldoFin,char letra,double dolar,double euro){
    switch(letra){
        case '$':
            return saldoFin;
        case '&':
            return (saldoFin/euro)*dolar;
        case 'S':
            return saldoFin*dolar;
    }
}
void imprimeObservacionFinal(double saldoFin,char letra,double dolar,double euro){
    double cantDolar;
    cantDolar=hallarCantDolar(saldoFin,letra,dolar,euro);
    if(cantDolar<1000){
        if(cantDolar<0){
            cout<<"CUENTA EN SOBREGIRO"<<endl;
        }else cout<<"CUENTA BAJO EL MINIMO"<<endl;
        
    }else cout<<endl;
    imprimeLinea('=',MAXCANTLINEA);
}

void reiniciaVariables(int &cantRetir,int &cantDep,double &totRetir,double &totDep){
    cantRetir=0;
    cantDep=0;
    totRetir=0;
    totDep=0;
}
void imprimeResumen(int &cantRetir,int &cantDep,char letra,double &totRetir,
        double &totDep,double &saldoFin,double dolar,double euro){
    imprimeLinea('=',MAXCANTLINEA);
    cout<<left<<"RESUMEN"<<endl;
    cout<<setw(20)<<left<<"CANTIDAD TOTAL DE RETIROS:"<<setw(9)<<right<<
            cantRetir<<setw(22)<<" "<<left<<"TOTAL DE RETIROS:      "<<letra<<
            setw(12)<<right<<setprecision(2)<<fixed<<totRetir<<endl;
    cout<<setw(20)<<left<<"CANTIDA TOTAL DE DEPOSITOS:"<<setw(8)<<right<<
            cantDep<<setw(22)<<" "<<left<<"TOTAL DE DEPOSITOS:    "<<letra<<
            setw(12)<<right<<setprecision(2)<<fixed<<totDep<<endl;
    cout<<left<<"SALDO FINAL:   "<<letra<<setw(19)<<right<<setprecision(2)<<
            fixed<<saldoFin<<setw(22)<<" "<<left<<"OBSERVACION FINAL:     ";
    imprimeObservacionFinal(saldoFin,letra,dolar,euro);
    reiniciaVariables(cantRetir,cantDep,totRetir,totDep);
}

double convertirMoneda(double cantidad,char monedaOrigen,char monedaFin,
        double dolar,double euro){
    if(monedaOrigen==monedaFin)return cantidad;
    if(monedaOrigen=='S'){
        if(monedaFin=='$')return cantidad/dolar;
        else return cantidad/euro;
    }else if(monedaOrigen=='&'){
        if(monedaFin=='$')return (cantidad*euro)/dolar;
        else return cantidad*euro;
    }else{
        //Es dolar
        if(monedaFin=='S')return cantidad*dolar;
        else return (cantidad*dolar)/euro;
    }
}
void procesaDeposito(double &depositos,int &cantDep,char moneda,
        double dolar,double euro,int flag,char letra){
    char monedaLeida;
    double cantidad,cantidadConvertida;
    if(flag)cin>>monedaLeida;
    else monedaLeida=letra;
    cin>>cantidad;
    cantidadConvertida=convertirMoneda(cantidad,monedaLeida,moneda,dolar,euro);
    cantDep++;
    depositos+=cantidadConvertida;
}

void procesaRetiro(double &retiros,int &cantRep,char moneda,
        double dolar,double euro,int flag,char letra){
    char monedaLeida;
    double cantidad,cantidadConvertida;
    if(flag)cin>>monedaLeida;
    else monedaLeida=letra;
    cin>>cantidad;
    cantidadConvertida=convertirMoneda(cantidad,monedaLeida,moneda,dolar,euro);
    cantRep++;
    retiros+=cantidadConvertida;
}

void procesaMovimientosFecha(double &retiros,double &depositos,double saldo,
        int &cantRetir,int &cantDep,double acumulado,char moneda,double dolar,double euro){
    char letra,backup;
    while(1){
        cin>>letra;
        if(letra=='D'||letra=='R'){
            if(letra=='D')procesaDeposito(depositos,cantDep,moneda,dolar,euro,1,letra);
            else procesaRetiro(retiros,cantRetir,moneda,dolar,euro,1,letra);
            backup=letra;
        }else{
            if(backup=='D')procesaDeposito(depositos,cantDep,moneda,dolar,euro,0,letra);
            else procesaRetiro(retiros,cantRetir,moneda,dolar,euro,0,letra);
        }
        if(cin.get()=='\n')break;
    }
}

void imprimeFecha(int dd,int mm,int aa){
    cout<<setfill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa;
    cout<<setfill(' ');
}

void imprimeMonto(int cant,char moneda,double monto){
    cout<<setw(cant)<<" "<<moneda<<setw(10)<<right<<setprecision(2)<<fixed<<monto;
}
void imprimeMovimientos(int dd,int mm,int aa,double retiros,double depositos,
        double saldo,char moneda){
    imprimeFecha(dd,mm,aa);
    imprimeMonto(6,moneda,retiros);
    imprimeMonto(14,moneda,depositos);
    imprimeMonto(14,moneda,saldo);
    if(saldo<1000){
        cout<<setw(13)<<" ";
        if(saldo<0){
            cout<<"SOBREGIRO";
        }else cout<<"BAJO EL MINIMO";
    }
    cout<<endl;
}
//Procesa las fechas de una persona
void procesaFechas(char moneda,double &saldoIni,int &cantRetir,int &cantDep,
        double &totRetir,double &totDep,double dolar,double euro){
    double retiros=0,depositos=0,cant,acumulado;
    int dd,mm,aa,contador=0;
    char c,letra;
    while(1){
        cin>>dd>>c>>mm>>c>>aa;
        procesaMovimientosFecha(retiros,depositos,saldoIni,cantRetir,cantDep,acumulado,moneda,dolar,euro);
        totRetir+=retiros;
        totDep+=depositos;
        saldoIni=saldoIni-retiros+depositos;
        imprimeMovimientos(dd,mm,aa,retiros,depositos,saldoIni,moneda);
        retiros=0;depositos=0;
        if(cin.get()=='\n')break;
    }
}

void agregaCadenaNombre(char *nombre,char *cadena,int &longitud,int flag){
    int i,j,valor;
    nombre[longitud]=' ';
    valor=flag;
    for(i=longitud+flag,j=0;cadena[j];i++,j++){
        nombre[i]=cadena[j];
    }
    nombre[i]=0;
    longitud=i;
}
void arreglaCadena(char *cadena){
    int i;
    for(i=1;cadena[i];i++)cadena[i]=cadena[i]+'a'-'A';
}

void leeNombre(char *nombre,int &valor){
    int longitud=0,flag=0;
    char cadena[20];
    while(1){
        cin>>valor;
        if(cin.fail()){
            cin.clear();
            cin>>cadena;
            arreglaCadena(cadena);
            agregaCadenaNombre(nombre,cadena,longitud,flag);
            flag=1;
        }else{
            if(cin.eof())break;
            else{
                return;
            }
        }
    }
}

int main(int argc, char** argv) {
    int codCuen,flag=0,cantRetir=0,cantDep=0;
    double dolar,euro,saldoIni,totRetir=0,totDep=0;
    char nombre[100],letra;
    imprimeCabecera();
    cin>>dolar>>euro;
    while(1){
        leeNombre(nombre,codCuen);
        if(cin.eof()){
            imprimeResumen(cantRetir,cantDep,letra,totRetir,totDep,saldoIni,dolar,euro);
            break;
        }
        cin>>letra>>saldoIni;
        imprimeCabeceraCliente(nombre,codCuen,letra,saldoIni);
        procesaFechas(letra,saldoIni,cantRetir,cantDep,totRetir,totDep,dolar,euro);
        imprimeResumen(cantRetir,cantDep,letra,totRetir,totDep,saldoIni,dolar,euro);
    }
    return 0;
}

