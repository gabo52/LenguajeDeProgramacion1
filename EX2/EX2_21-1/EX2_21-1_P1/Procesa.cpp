/* 
 * File:   Procesa.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 27 de noviembre de 2022, 08:48 PM
 */



#include "Procesa.h"

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

void Procesa::lee(){
    ifstream arch;
    AbrirArchivo("Conductores.csv",arch);
    Nodo nod;
    while(1){
        nod.leer(arch);
        if(arch.eof())break;
        lrenueva.push_back(nod);
    }
    
}

void Procesa::imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void Procesa::imprime(){
    ofstream arch;
    AbrirArchivo("ReporteRenovacion.txt",arch);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(80)<<right<<"Renovacion de Licencias"<<endl;
    imprimeLinea(arch,150,'=');
    arch<<setw(12)<<left<<"Licencia"<<setw(36)<<left<<"Nombre"<<setw(25)<<left<<
            "           Observacion"<<setw(10)<<right<<"Multas"<<setw(10)<<right
            <<"Tramites"<<setw(10)<<right<<"Ex.Med"<<setw(20)<<right<<"Manejo/Reglas"
            <<setw(15)<<right<<"Total"<<endl;
    lrenueva.sort();
    for(list<Nodo>::iterator it = lrenueva.begin();it!=lrenueva.end();it++){
        (*it).imprime(arch);
    }
}