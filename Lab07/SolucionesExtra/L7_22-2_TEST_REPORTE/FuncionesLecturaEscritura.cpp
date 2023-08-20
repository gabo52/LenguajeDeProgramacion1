/* 
 * File:   FuncionesLecturaEscritura.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 3 de noviembre de 2022, 09:52 PM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLecturaEscritura.h"
#include "Medico.h"
#include "Paciente.h"
using namespace std;



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

void separaNombreEsp(char *nomb,char *esp){
    int i;
    for(i=0;nomb[i];i++)if(nomb[i]=='_')nomb[i]=' ';
    int j;
    for(j=i;j>=0;j--)if(nomb[j]==' ')break;
    nomb[j]=0;
    int k;
    for(k=0;nomb[k+j+1];k++)esp[k]=nomb[k+j+1];
    esp[k]=0;
}
ifstream & operator >> (ifstream &arch, Medico &med){
    int codigo;
    arch>>codigo;
    if(arch.eof())return arch;
    char cadena[200];
    char especialidad[50];
    double tarifa;
    arch>>cadena>>tarifa;
    separaNombreEsp(cadena,especialidad);
    med.SetCodigo(codigo);
    med.SetEspecialidad(especialidad);
    med.SetNombre(cadena);
    med.SetTarifaxconsulta(tarifa);
    return arch;
}

ifstream & operator >> (ifstream &arch, Paciente &pac){
    int dni;
    arch>>dni;
    if(arch.eof())return arch;
    char nombre[50];
    int telefono;
    arch>>nombre>>telefono;
    pac.SetDni(dni);
    pac.SetNombre(nombre);
    pac.SetTelefono(telefono);
    return arch;
}

int operator >> (ifstream &arch, Cita &cita){
    int dni,codigo,dd,mm,aa;
    arch>>dni;
    if(arch.eof())return -1;
    char c;
    arch>>codigo>>dd>>c>>mm>>c>>aa;
    cita.setCodMed(codigo);
    cita.setFecha(dd+mm*100+aa*10000);
    return dni;
}

ofstream& operator << (ofstream &arch, Paciente &pac){
    char cadena[200];
    arch<<"   DNI"<<setw(29)<<right<<"NOMBRE"<<setw(38)<<right<<"TELEFONO"<<endl;
    pac.GetNombre(cadena);
    arch<<pac.GetDni()<<setw(32)<<right<<cadena<<setw(34)<<right
            <<pac.GetTelefono()<<endl;
    arch<<"RELACION DE CITAS"<<endl<<"No.   FECHA"<<setw(30)<<right
            <<"CODIGO DEL MEDICO"<<setw(30)<<right<<
            "ESPECIALIDAD         TARIFA"<<endl;
    pac.imprimeCitas(arch);
}

