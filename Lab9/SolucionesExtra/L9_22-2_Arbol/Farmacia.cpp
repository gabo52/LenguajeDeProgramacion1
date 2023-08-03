/* 
 * File:   Farmacia.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 07:16 PM
 */

#include <cstring>
#include "conreceta.h"
#include "sinreceta.h"
#include "Farmacia.h"

Farmacia::Farmacia() {

}



Farmacia::~Farmacia() {
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

void Farmacia::leer(){
    ifstream arch;
    AbrirArchivo("medicos.csv",arch);
    int n=0;
    while(1){
        lmedico[n].leer(arch);
        if(arch.eof())break;
        n++;
    }
    arch.close();
    AbrirArchivo("recetas.csv",arch);
    while(1){
        leerRecetas(arch);
        if(arch.eof())break;
    }
}
void Farmacia::imprimir(){
    ofstream arch;
    AbrirArchivo("AquelArbolito.txt",arch);
    arbol.imprimir(arch);
}

void Farmacia::leerRecetas(ifstream &arch){
    int dd,mm,aa,dni,codMed,codMedicamento,cant,fecha;
    char c,nomb[80],nombreMedicamento[200],nombreMedico[200],especialidad[100];
    double precio;
    arch>>dd>>c>>mm>>c>>aa>>c>>dni>>c;
    if(arch.eof())return;
    fecha=dd+mm*100+aa*10000;
    arch.getline(nomb,80,',');
    arch>>codMed>>c;
    medicamento *med;
    buscaMedico(codMed,nombreMedico,especialidad);
    while(1){
        arch>>codMedicamento>>c>>cant;
        if((codMedicamento/10000)%2==0){
            //conreceta
            med = new class conreceta;
        }else{
            //sinreceta
            med = new class sinreceta;
        }
        buscaMedicamento(codMedicamento,nombreMedicamento,precio);
        med->asigna(codMedicamento,nombreMedico,cant,precio,
        fecha,codMed,especialidad,dni,nomb);
        arbol.insertarArbol(med);
        if(arch.get()=='\n')break;
    }
}


void Farmacia::buscaMedico(int codMed,char *nombreMedico,char *especialidad){
    char cad[200];
    for(int i=0;lmedico[i].GetCodigo();i++){
        if(lmedico[i].GetCodigo()==codMed){
            lmedico[i].GetEspecialidad(cad);
            strcpy(especialidad,cad);
            lmedico[i].GetNombre(cad);
            strcpy(nombreMedico,cad);
            return;
        }
    }
    cout<<"Error, no se encontro el medico "<<codMed;
    exit(1);
}
void buscaMedicamento(int cod,char *nomb,double &precio){
    ifstream arch;
    AbrirArchivo("medicamentos.csv",arch);
    int codmed;
    char c;
    while(1){
        arch>>codmed>>c;
        if(arch.eof())break;
        if(codmed==cod){
            arch.getline(nomb,200,',');
            arch>>precio;
            return;
        }else arch.getline(nomb,200,'\n');
    }
    cout<<"Error, no se encontro el medicamento "<<cod;
    exit(1);
}
