/* 
 * File:   Procesa.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 09:52 AM
 */

#include "Procesa.h"

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void Procesa::carga(){
    ifstream archPed,archCli;
    AbrirArchivo("pedidos4.csv",archPed);
    int n=0;
    while(1){
        lpedido[n].lee(archPed);
        if(archPed.eof())break;
        n++;
    }
    n=0;
    AbrirArchivo("clientes3.csv",archCli);
    while(1){
        ldeudor[n].leer(archCli);
        if(archCli.eof())break;
        n++;
    }
}

void Procesa::muestra(){
    ofstream arch;
    arch.precision(2);
    arch<<fixed;
    AbrirArchivo("Reporte.txt",arch);
    arch<<setw(50)<<"REPORTE DE DEUDAS"<<endl;
    imprimeLinea(arch,100,'=');
    for(int i=0;ldeudor[i].activo();i++){
        ldeudor[i].imprimir(arch);
        arch<<endl;
    }
}

void Procesa::actualiza(){
    for(int i=0;ldeudor[i].activo();i++){
        ldeudor[i].actualiza(lpedido);
    }
}

