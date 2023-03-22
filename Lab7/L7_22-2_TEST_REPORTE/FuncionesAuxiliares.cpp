/* 
 * File:   FuncionesAuxiliares.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 10:53 PM
 */

#include <iostream>
#include <iomanip>
#include "Medico.h"
#define MAXCANTLINEA 80
using namespace std;
#include "FuncionesLecturaEscritura.h"



void cargaMedicos(Medico *arr){
    ifstream arch;
    int n=0;
    AbrirArchivo("MedicosLab3.txt",arch);
    while(1){
        arch>>arr[n];
        if(arch.eof())break;
        n++;
    }
}

void cargaPacientes(Paciente *arr){
    ifstream arch;
    int n=0;
    AbrirArchivo("PacientesLab3.txt",arch);
    while(1){
        arch>>arr[n];
        if(arch.eof())break;
        n++;
    }
}

int  buscarPaciente(Paciente *arr,int dni){
    for(int i=0;arr[i].GetDni();i++){
        if(arr[i].GetDni()==dni)return i;
    }
    return -1;
}

void cargaCitas(Paciente *arrPac,Medico *arrMed){
    ifstream arch;
    int n=0,dni,pos;
    Cita cit;
    AbrirArchivo("ConsultasLab3.txt",arch);
    while(1){
        dni=(arch>>cit);
        if(arch.eof())break;
        if(cit<=arrMed){
            pos=buscarPaciente(arrPac,dni);
            if(pos!=-1){
                arrPac[pos]+=cit;
            }
        }
    }
    for(int i=0;arrPac[i].GetDni();i++)(++arrPac[i]);
}
void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
void imprimeReporte(Paciente *arr){
    ofstream arch;
    AbrirArchivo("ReportePacientes.txt",arch);
    for(int i=0;arr[i].GetDni();i++){
        arch<<arr[i];
        imprimeLinea(arch,MAXCANTLINEA,'=');
    }
}
