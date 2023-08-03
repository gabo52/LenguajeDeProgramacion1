/*
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesAux.h"
using namespace std;


ofstream abrirArchivoE(const char *nombre,char modo){
    ofstream arch;
    if(modo=='T')arch.open(nombre,ios::out);
    else arch.open(nombre,ios::out|ios::binary);
    if(!arch){
        cout<<"ERROR, no se ha podido abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

ifstream abrirArchivoL(const char *nombre,char modo){
    ifstream arch;
    if(modo=='T')arch.open(nombre,ios::in);
    else arch.open(nombre,ios::in|ios::binary);
    
    if(!arch){
        cout<<"ERROR, no se ha podido abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

void crearCargarMedicosBin(){
    ofstream archBin=abrirArchivoE("Medicos.bin",'B');
    ifstream arch=abrirArchivoL("Medicos.txt",'T');
    char codigo[10],nombre[50],especialidad[20];
    while(1){
        arch>>codigo>>nombre>>especialidad;
        if(arch.eof())break;
        archBin.write(reinterpret_cast<const char*>(codigo),sizeof(char)*10);
        archBin.write(reinterpret_cast<const char*>(nombre),sizeof(char)*50);
        archBin.write(reinterpret_cast<const char*>(especialidad),sizeof(char)*20);
    }
    archBin.close();
    arch.close();
}
void verificarMedicosBin(){
    ifstream archBin=abrirArchivoL("Medicos.bin",'B');
    ofstream arch=abrirArchivoE("ReporteMedicos.txt",'T');
    char codigo[10],nombre[50],especialidad[20];
    arch<<"REPORTE MEDICOS"<<endl;
    while(1){
        archBin.read(reinterpret_cast<char *>(codigo),sizeof(char)*10);
        if(archBin.eof())break;
        archBin.read(reinterpret_cast<char *>(nombre),sizeof(char)*50);
        archBin.read(reinterpret_cast<char *>(especialidad),sizeof(char)*20);
        arch<<setw(10)<<left<<codigo<<setw(40)<<left<<nombre<<setw(20)<<left<<especialidad<<endl;
    }
    archBin.close();
    arch.close();
}
void crearCargarMedicinasBin(){
    ifstream arch=abrirArchivoL("Medicinas.txt",'T');     
    ofstream archBin=abrirArchivoE("Medicinas.bin",'B');
    int codigo;
    char nombre[50];
    while(1){
        arch>>codigo>>nombre;
        if(arch.eof())break;
        archBin.write(reinterpret_cast<const char*>(&codigo),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(nombre),sizeof(char)*50);
    }
    archBin.close();
    arch.close();
}
void verificarMedicinasBin(){
    ifstream archBin=abrirArchivoL("Medicinas.bin",'B');
    ofstream arch=abrirArchivoE("ReporteMedicinas.txt",'T');
//    ifstream archBin("Medicinas.bin",ios::in);
//    ofstream arch("ReporteMedicinas.txt",ios::in);
    int codigo;
    char nombre[50];
    arch<<"REPORTE MEDICINAS"<<endl;
    while(1){
        archBin.read(reinterpret_cast<char *>(codigo),sizeof(int));
        if(archBin.eof())break;
        archBin.read(reinterpret_cast<char *>(nombre),sizeof(char)*50);
        arch<<setw(15)<<left<<codigo<<setw(40)<<left<<nombre<<endl;
    }
    archBin.close();
    arch.close();
}
void crearCargarPacientesBin(){
    
//    ofstream archBin=abrirArchivoE("Pacientes.bin",'B');
//    ifstream arch=abrirArchivoL("Pacientes.txt",'T');
    
    ofstream archBin("Pacientes.bin",ios::out|ios::binary);
    ifstream arch("Pacientes.txt",ios::in);
    char codMed[10],nombre[50];
    int DNI,codMedicina,fecha;
    while(1){
        arch>>codMed;
        if(arch.eof())break;
        arch>>DNI>>nombre>>codMedicina>>fecha;
        archBin.write(reinterpret_cast<const char*>(codMed),sizeof(char)*10);
        archBin.write(reinterpret_cast<const char*>(&DNI),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(nombre),sizeof(char)*50);
        archBin.write(reinterpret_cast<const char*>(&codMedicina),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(&fecha),sizeof(int));
    }
}

void imprimirFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<setw(2)<<right<<mm<<setw(4)<<right
            <<aa<<setfill(' ');
}

void verificarPacientesBin(){
    ifstream archBin=abrirArchivoL("Pacientes.bin",'B');
    ofstream arch=abrirArchivoE("ReportePacientes.txt",'T');
    char codMed[10],nombre[50];
    int DNI,codMedicina,fecha;
    while(1){
        archBin.read(reinterpret_cast<char*>(codMed),sizeof(char)*10);
        if(archBin.eof())break;
        archBin.read(reinterpret_cast<char*>(&DNI),sizeof(int));
        archBin.read(reinterpret_cast<char*>(nombre),sizeof(char)*50);
        archBin.read(reinterpret_cast<char*>(&codMedicina),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&fecha),sizeof(int));
        arch<<setw(10)<<left<<codMed<<setw(10)<<left<<DNI<<setw(50)<<left<<nombre
                <<setw(10)<<left<<codMedicina<<"   ";
        imprimirFecha(fecha,arch);
        arch<<endl;
    }
}

void hallarNombMedicamento(char *nomb,int cod,ifstream &arch){
    int codigo;
    char nombre[50];
    arch.seekg(0,ios::beg);
    while(1){
        arch.read(reinterpret_cast<char *>(codigo),sizeof(int));
        if(arch.eof())break;
        arch.read(reinterpret_cast<char *>(nomb),sizeof(char)*50);
        if(cod==codigo)return; 
    }
    cout<<"ERROR, no se encontro la medicina "<<cod;
    exit(2);
}
void imprimeAtencionPaciente(char *nombre,int DNI,int fecha,int codMedicina,
        ifstream &archBinMedicamentos,ofstream &rep){
    char nombMedicamento[30];
    hallarNombMedicamento(nombMedicamento,codMedicina,archBinMedicamentos);
    rep<<setw(40)<<left<<nombre<<setw(12)<<left<<DNI<<setw(30)<<left<<
            nombMedicamento<<"   ";
    imprimirFecha(fecha,rep);
    rep<<endl;
}

void imprimeAtencionesMedico(char *codigo,ifstream &archBinPac,
        ifstream &archBinMedicamentos,ofstream &rep){
    archBinPac.seekg(0,ios::beg);
    char codMed[10],nombre[50];
    int DNI,codMedicina,fecha;
    while(1){
        archBinPac.read(reinterpret_cast<char*>(codMed),sizeof(char)*10);
        if(archBinPac.eof())break;
        archBinPac.read(reinterpret_cast<char*>(&DNI),sizeof(int));
        archBinPac.read(reinterpret_cast<char*>(nombre),sizeof(char)*50);
        archBinPac.read(reinterpret_cast<char*>(&codMedicina),sizeof(int));
        archBinPac.read(reinterpret_cast<char*>(&fecha),sizeof(int));
        if(strcmp(codigo,codMed)==0){
            imprimeAtencionPaciente(nombre,DNI,fecha,codMedicina,
                    archBinMedicamentos,rep);
        }
    }
}

void imprimeCabeceraMedico(char *codigo,char *nombre,char *especialidad,ofstream &rep){
    rep<<setw(12)<<left<<codigo<<setw(40)<<left<<nombre<<setw(30)<<left
            <<especialidad<<endl;
}

void crearReporteMedicos(){
     ifstream archBinPac=abrirArchivoL("Pacientes.bin",'B');   
     ifstream archBinMedico=abrirArchivoL("Medicos.bin",'B');   
     ifstream archBinMedicamentos=abrirArchivoL("Medicamentos.bin",'B');
     ofstream archRep=abrirArchivoE("Reporte.txt",'T');
     char codigo[10],nombre[50],especialidad[20];
     while(1){
        archBinMedico.read(reinterpret_cast<char*>(codigo),sizeof(char)*10);
        if(archBinMedico.eof())break;
        archBinMedico.read(reinterpret_cast<char*>(nombre),sizeof(char)*50);
        archBinMedico.read(reinterpret_cast<char*>(especialidad),sizeof(char)*20);
        imprimeCabeceraMedico(codigo,nombre,especialidad,archRep);
        imprimeAtencionesMedico(codigo,archBinPac,archBinMedicamentos,archRep);
     }
}