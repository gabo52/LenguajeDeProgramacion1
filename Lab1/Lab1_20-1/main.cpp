/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabri
 *
 * Created on 22 de agosto de 2022, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#define MAXCANTLINEA 100
using namespace std;

/*
 * 
 */


void imprimeLinea(char c,int cant){
    for(int i=0;i<cant;i++)cout<<c;
    cout<<endl;
}
void leeDatos(int &mm,int &aa,int &tipoMov,int &codProd,char *nombreProd,
        double &cant,char *unidad){
    char c;
    cin>>c>>mm>>c>>aa>>tipoMov>>codProd>>nombreProd;
    cin>>cant;
    if(cin.fail()){
        cin.clear();
        cant=1;
    }
    cin>>unidad;
}


void imprimirCabecera(){
    cout<<setw(62)<<"REPORTE KARDEX"<<endl;
}

void imprimeCabeceraTienda(int RUC,char *nombre){
    imprimeLinea('=',MAXCANTLINEA);
    cout<<RUC<<" "<<nombre<<endl;
    imprimeLinea('=',MAXCANTLINEA);
    cout<<"FECHA"<<setw(17)<<right<<"CODIGO"<<setw(19)<<right<<"DESCRIPCION"<<
            setw(40)<<right<<"CANTIDAD"<<setw(13)<<"UNIDAD"<<endl;
    imprimeLinea('-',MAXCANTLINEA);
}

void imprimeDatos(int dd,int mm,int aa,int tipoMov,int codProd,char *nombreProd,
        double cant,char *unidad){
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(2)<<right<<aa;
    cout<<"      "<<setw(8)<<right<<codProd<<"      ";
    cout<<setfill(' ');
    cout<<setw(43)<<left<<nombreProd;
    cout<<setw(8)<<setprecision(2)<<fixed<<right<<cant<<"       "<<
            setw(12)<<left<<unidad<<endl;
}

int cantDigitos(int codigo,int &ultimoDigito){
    int cant=0;
    while(codigo!=0){
        ultimoDigito=codigo;
        codigo/=10;
        cant++;
    }
    return cant;
}


int movValido(int codigo,double &cantidad){
    int ultimoDigito;
    if(cantDigitos(codigo,ultimoDigito)==3){
        if(ultimoDigito==3){
            cantidad*=-1;
            return 1;
        }else if(ultimoDigito==5){
            return 1;
        }else return 0;
    }else{
        return 0;
    }
}

int main(int argc, char** argv) {
    int RUC,dd,mm,aa,tipoMov,codProd,dato,flag=0;
    char nombre[100],nombreProd[100],unidad[30],c;
    double cant;
    imprimirCabecera();
    while(1){
        cin>>dato;
        if(cin.eof())break;
        if(dato>31){
            RUC=dato;
            cin>>nombre;
            imprimeCabeceraTienda(RUC,nombre);
        }else{
            dd=dato;
            leeDatos(mm,aa,tipoMov,codProd,nombreProd,cant,unidad);
            if(movValido(tipoMov,cant)){
                imprimeDatos(dd,mm,aa,tipoMov,codProd,nombreProd,cant,unidad);
            }
        }
    }
    imprimeLinea('=',MAXCANTLINEA);
    return 0;
}

