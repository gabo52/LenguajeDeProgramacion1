/* 
 * File:   Procesa.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 28 de noviembre de 2022, 06:36 PM
 */

#include "Procesa.h"
#define MAXCANTLINEA 170

void Procesa::lee(ifstream &arch){
    int i=0;
    while(1){
        pacientes[i].leer(arch);
        if(arch.eof())break;
        i++;
    }
}

void Procesa::ordena(){
    list<NPaciente>lista;
    int prio,i;
    for(i=0;pacientes[i].activo();i++){
        lista.push_back(pacientes[i]);
    }
    lista.sort();
    lista.unique();
    cout<<i<<endl;
    i=0;
    for(list<NPaciente>::iterator it =lista.begin();it!=lista.end();it++,i++){
        pacientes[i]=(*it);
    }
    pacientes[i].setNull();
    cout<<i<<endl;
}

void Procesa::imprime(){
    ofstream arch;
    int i,pacR=0,pacM=0;
    arch.open("ReportePacientes.txt");
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo ReportePacientes.txt";
        exit(1);
    }
    arch<<setw(70)<<right<<"INSTITUTO DE SALUD SA"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(75)<<right<<"Orden de atencion de los pacientes"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(9)<<left<<"No."<<setw(15)<<left<<"DNI"<<setw(48)<<left<<"Edad"
            <<setw(13)<<left<<"Edad"<<setw(66)<<left<<"Observacion"
            <<setw(12)<<left<<"Referencia"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    for(i=0;pacientes[i].activo();i++){
        arch<<setw(3)<<right<<i+1<<")     ";
        pacientes[i].imprimir(arch);
        pacientes[i].actualizaObservaciones(pacR,pacM);
    }
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(12)<<left<<"Pacientes: "<<setw(4)<<i-1<<left
            <<setw(25)<<left<<"Personas de riesgo: "<<setw(4)<<pacR<<endl;
    arch<<setw(30)<<left<<"Menores de Edad sin apoderado: "<<setw(4)<<pacM<<endl;
}

void Procesa::imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}