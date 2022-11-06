/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Estructuras.h"
#include "FuncBiblioteca.h"
using namespace std;

ofstream abrirArchivoE(const char *nombre){
    ofstream arch;
    arch.open(nombre,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}


ifstream abrirArchivoL(const char *nombre){
    ifstream arch;
    arch.open(nombre,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

void cargaMedicamento(Medicinas &med,ifstream &arch,Medicinas *med2,int &k){
    arch>>med.codigo>>med.descripcion>>med.precio;
    med2[k].codigo=med.codigo;
    strcpy(med2[k].descripcion,med.descripcion);
    med2[k].precio=med.precio;
    k++;
}
void leerConsultasYMedicamentos(Consulta *citas,Medicinas *medicinas,
        ifstream &arch,int &j,int &k){
    while(1){
        arch>>citas[j].DNI;
        if(arch.fail()){
            arch.clear();
            return;
        }
        arch>>citas[j].nombre>>citas[j].codMed>>citas[j].fecha>>
                citas[j].cantMedicamentos;
        for(int i=0;i<citas[j].cantMedicamentos;i++){
            cargaMedicamento(citas[j].medicinas[i],arch,medicinas,k);
        }
        j++;
    }
}
void cargarArchivos(Medico *medicos, Paciente *pacientes,
        Medicinas *medicinas, Consulta *citas){
    ifstream arch;
    arch=abrirArchivoL("Datos.txt");
    int i=0,j=0,k=0;
    while(1){
        arch>>medicos[i];
        if(arch.fail())break;
        i++;
        leerConsultasYMedicamentos(citas,medicinas,arch,j,k);
    }
}

void arreglaEspecialidad(char *nombre,char *especialidad){
    int i,j,k,m;
    for(i=0;nombre[i];i++){
        if(nombre[i]=='_')nombre[i]=' ';
    }
    for(j=i-1;j>=0;j--)if(nombre[j]==' ')break;
    for(k=j+1,m=0;nombre[k];k++,m++){
        especialidad[m]=nombre[k];
    }
    especialidad[m]=0;
    nombre[j]=0;
}
void operator >>(ifstream &arch, Medico &med){
    arch<<med.codigo;
    if(arch.fail())break;
    arch<<med.nombre;
    arreglaEspecialidad(med.nombre,med.especialidad);
}
void imprimirArchivos(){
    
}



bool operator += (Medicinas *arr, Medicinas med){
    for(int i=0;arr[i].codigo;i++){
        if(arr[i].codigo==med.codigo)return true;
    }
    return false;
}


bool operator += (Consulta *arr, Consulta med){
    for(int i=0;arr[i];i++){
        if(strcmp(arr[i].codMed,med.codMed)==0)return true;
    }
    return false;
}

double precioCita(Consulta consulta){
    double suma=0;
    for(int i=0;i<consulta.cantMedicamentos;i++){
        suma+=consulta.medicinas[i].precio;
    }
    return suma;
}
double operator ++ (Medico med){
    double suma=0;
    for(int i=0;i<med.cantCitas;i++){
        suma+=precioCita(med.citas[i]);
    }
    return suma;
}

void operator +=(Consulta &consulta,Medicinas med){
    int k=consulta.cantMedicamentos;
    for(int i=0;i<k;i++){
        if(consulta.medicinas[i].codigo==med.codigo){
            consulta.medicinas[i].cantidad++;
        }
    }
    consulta.medicinas[i]=med;
    consulta.medicinas[i+1].codigo=0;
}



