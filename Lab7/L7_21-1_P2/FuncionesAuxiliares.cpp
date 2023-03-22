/* 
 * File:   FuncionesAuxiliares.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 2 de noviembre de 2022, 12:18 AM
 */

#include <iostream>
#include <iomanip>
#include "SobrecargaEntradaSalida.h"
#include "FuncionesAuxiliares.h"
using namespace std;



void cargaConductores(Conductores *arr,int &n){
    n=0;
    ifstream arch;
    AbrirArchivo("Conductores.csv",arch);
    while(1){
        arch>>arr[n];
        if(arch.eof())return;
        n++;
    }
}
void cargaFaltas(Conductores *arr,int n){
    ifstream arch;
    int licencia,num,pos;
    AbrirArchivo("RegistroDeFaltas.csv",arch);
    Falta aux;
    while(1){
        arch>>aux;
        if(arch.eof())return;
        licencia=aux.GetLicencia();
        pos=buscarLicencia(arr,n,licencia);
        if(pos!=-1){
            num=arr[pos].GetNumFaltas();
            arr[pos]+aux;
        }
    }
}

int buscarLicencia(Conductores *arr,int n,int licencia){
    for(int i=0;i<n;i++){
        if(arr[i].GetLicencia()==licencia)return i;
    }
    return -1;
}
void asignarInfracciones(Conductores *arr,int n){
    ifstream arch;
    AbrirArchivo("Infracciones.csv",arch);
    Infraccion aux;
    int codigo,naux;
    while(1){
        arch>>aux;
        if(arch.eof())return;
        codigo=aux.GetCodigo();
        for(int i=0;i<n;i++){
            arr[i]+aux;
        }
    }
}

void imprimirReporte(Conductores *arr,int n){
    ofstream rep;
    AbrirArchivo("Reporte.txt",rep);
    for(int i=0;i<n;i++){
        rep<<arr[i];
    }
}
