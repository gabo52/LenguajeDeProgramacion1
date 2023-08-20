/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 1 de septiembre de 2022, 09:13 PM
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

void imprimeCabecera(){
    cout<<setw(70)<<right<<"REGISTRO CLIMATICO DEL PAIS"<<endl;
    imprimeLinea('=',MAXCANTLINEA);
}

void agregaCadena(char *nombre,char *cadena,int &num){
    int i,j,flag=1;
    if(num==0)flag=0;
    else nombre[num]=' ';
    for(i=num+flag,j=0;cadena[j];i++,j++){
        nombre[i]=cadena[j];
    }
    nombre[i]=0;
    num=i;
}
void leeNombreYCodigo(char *nombre,int &codigo){
    int i=0;
    char cadena[20];
    while(1){
        cin>>nombre;
        if(cin.fail()){
            cin.clear();
            break;
        }
        agregaCadena(nombre,cadena,i);
    }
}
int main(int argc, char** argv) {
    int codigo;
    char nombre[100];
    imprimeCabecera();
    while(1){
        leeNombreYCodigo(nombre,codigo);
    }
    return 0;
}

