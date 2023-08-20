/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: cueva.r
 * 
 * Created on 31 de agosto de 2022, 10:27 AM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Funciones.h"
#define MAX_CAR 100

using namespace std;


void ImprimeLinea(ofstream &arch, char c) {
    for (int i = 0; i < MAX_CAR; i++) arch << c;
    arch << endl;
}

/*
R  20160658  Arca/Amezquita/Edric-Ronald  IngenieriaMecanica  FCI
R  20119778  Morales/Valverde/Ines-Martha  IngenieriaInformatica  FCI
I  5258  Gavidia/Mendoza/Ronald-Johnny 394930 IngenieriaElectronica  FEI
*/


void generaalumno(){
    char tipo, nombre[100],especialidad[100],facultad[10];
    int codigo,carne;
    
    ifstream arch("Alumnos.txt",ios::in);
    if(!arch){
        cout << "No se puede abrir alumnos.txt";
        exit(1);
    }
    ofstream archbin("Alumnos.bin",ios::out|ios::binary);
    if(!archbin){
        cout << "No se puede abrir alumnos.bin";
        exit(1);
    }
    while(1){
        arch >> tipo;
        if(arch.eof()) break;
        arch >> codigo >> nombre >> carne;
        if(arch.fail()){
            arch.clear();
            carne = 0;
        }
        arch >> especialidad >> facultad;
        
        archbin.write(reinterpret_cast<const char*> (&codigo),sizeof(int));
        archbin.write(reinterpret_cast<const char*> (nombre),sizeof(char)*100);
        archbin.write(reinterpret_cast<const char*> (&tipo),sizeof(char));
        archbin.write(reinterpret_cast<const char*> (facultad),sizeof(char)*10);
        archbin.write(reinterpret_cast<const char*> (especialidad),sizeof(char)*100);        
        
        
    }
    muestralumnosbin();
    
}

void muestralumnosbin(){
    char tipo, nombre[100],especialidad[100],facultad[10];
    int codigo,carne;    
    ifstream archbin("Alumnos.bin",ios::in|ios::binary);
    if(!archbin){
        cout << "No se puede abrir alumnos.bin";
        exit(1);
    }    

    while(1){
        archbin.read(reinterpret_cast< char*> (&codigo),sizeof(int));
        if(archbin.eof()) break;
        archbin.read(reinterpret_cast< char*> (nombre),sizeof(char)*100);
        archbin.read(reinterpret_cast< char*> (&tipo),sizeof(char));
        archbin.read(reinterpret_cast< char*> (facultad),sizeof(char)*10);
        archbin.read(reinterpret_cast< char*> (especialidad),sizeof(char)*100);        
        
        cout << codigo <<" "<< nombre <<" "<< tipo <<" "<<facultad <<" "<<especialidad << endl;   
    }
    
    
}

void muestraconsolidado(){
    char tipo,nombre[100],especialidad[100],facultad[10];
    int codigo,snotas=0,matcur=0,estado=0;
    double credcur=0,credapro=0;   
    
    ifstream consobin("Consolidado.bin",ios::in|ios::binary);
    if(!consobin){
        cout << "No se puede abrir consolidado.bin";
        exit(1);
    }  
    
    while(1){
        consobin.read(reinterpret_cast< char*> (&codigo),sizeof(int));
        if(consobin.eof()) break;
        consobin.read(reinterpret_cast< char*> (nombre),sizeof(char)*100);
        consobin.read(reinterpret_cast< char*> (&credcur),sizeof(double));
        consobin.read(reinterpret_cast< char*> (&credapro),sizeof(double));        
        consobin.read(reinterpret_cast< char*> (&matcur),sizeof(int));
        consobin.read(reinterpret_cast< char*> (&snotas),sizeof(int));
        consobin.read(reinterpret_cast< char*> (facultad),sizeof(char)*10);
        consobin.read(reinterpret_cast< char*> (&estado),sizeof(int));
    
        cout << codigo <<" "<< nombre << " " <<  credcur << " " << credapro <<" ";
        cout << matcur <<" "<< snotas << " " << facultad << " " << estado << endl;
    
    }

    
}

void creaconsolidado(){
    char tipo,nombre[100],especialidad[100],facultad[10];
    int codigo,snotas=0,matcur=0,estado=0;
    double credcur=0,credapro=0;      
    
    ifstream archbin("Alumnos.bin",ios::in|ios::binary);
    if(!archbin){
        cout << "No se puede abrir alumnos.bin";
        exit(1);
    }  
    ofstream consobin("Consolidado.bin",ios::out|ios::binary);
    if(!consobin){
        cout << "No se puede abrir consolidado.bin";
        exit(1);
    }     
    
    while(1){
        archbin.read(reinterpret_cast< char*> (&codigo),sizeof(int));
        if(archbin.eof()) break;
        archbin.read(reinterpret_cast< char*> (nombre),sizeof(char)*100);
        archbin.read(reinterpret_cast< char*> (&tipo),sizeof(char));
        archbin.read(reinterpret_cast< char*> (facultad),sizeof(char)*10);
        archbin.read(reinterpret_cast< char*> (especialidad),sizeof(char)*100);        

        consobin.write(reinterpret_cast<const char*> (&codigo),sizeof(int));
        consobin.write(reinterpret_cast<const char*> (nombre),sizeof(char)*100);
        consobin.write(reinterpret_cast<const char*> (&credcur),sizeof(double));
        consobin.write(reinterpret_cast<const char*> (&credapro),sizeof(double));        
        consobin.write(reinterpret_cast<const char*> (&matcur),sizeof(int));
        consobin.write(reinterpret_cast<const char*> (&snotas),sizeof(int));
        consobin.write(reinterpret_cast<const char*> (facultad),sizeof(char)*10);
        consobin.write(reinterpret_cast<const char*> (&estado),sizeof(int));
    
    }
    muestraconsolidado();
}
void leeconsobin(fstream &consobin,int &codigo,char *nombre,double &credcur,
                    double &credapro,int &matcur,int &snotas,char *facultad,
                    int &estado){
    
        consobin.read(reinterpret_cast< char*> (&codigo),sizeof(int));
        if(consobin.eof()) return;
        consobin.read(reinterpret_cast< char*> (nombre),sizeof(char)*100);
        consobin.read(reinterpret_cast< char*> (&credcur),sizeof(double));
        consobin.read(reinterpret_cast< char*> (&credapro),sizeof(double));        
        consobin.read(reinterpret_cast< char*> (&matcur),sizeof(int));
        consobin.read(reinterpret_cast< char*> (&snotas),sizeof(int));
        consobin.read(reinterpret_cast< char*> (facultad),sizeof(char)*10);
        consobin.read(reinterpret_cast< char*> (&estado),sizeof(int));
}



/*
20110165 FIS111 19 2018-0 3.5
20110165 MAT111 8 2017-1 4
4450 FIS208 7 2015-2 3.5*/

void actualizaconsolidado(){
    int numreg,size,total,codigo,nota;
    double creditos;
    char curso[20],ciclo[20];
    
    char nombre[100],facultad[10];
    int code,snotas=0,matcur=0,estado=0;
    double credcur=0,credapro=0;
    
    
    ifstream arch("Cursos.txt",ios::in);
    if(!arch){
        cout << "No se puede abrir cursos.txt";
        exit(1);
    }
    fstream consobin("Consolidado.bin",ios::out|ios::in|ios::binary);
    if(!consobin){
        cout << "No se puede abrir consolidado.bin";
        exit(1);
    }  
    size = 4*sizeof(int)+ sizeof(char)*110 + 2*sizeof(double);
    consobin.seekg(0,ios::end);
    total = consobin.tellg();
    numreg = total / size;
    
    while(1){
        arch >> codigo;
        if(arch.eof()) break;
        arch >> curso >> nota >> ciclo >> creditos;
        
        for(int i=0;i<numreg;i++){
            consobin.seekg(i*size,ios::beg);
            
            leeconsobin(consobin,code,nombre,credcur,
                    credapro,matcur,snotas,facultad,estado);
        
            if(code == codigo){
                matcur++;
                credcur = credcur +  creditos;
                snotas = snotas + nota;
                if(nota>10) credapro = credapro +  creditos;
                if(credapro>=45) estado=1;
                consobin.seekg(i*size,ios::beg);
                
                consobin.write(reinterpret_cast<const char*> (&codigo),sizeof(int));
                consobin.write(reinterpret_cast<const char*> (nombre),sizeof(char)*100);
                consobin.write(reinterpret_cast<const char*> (&credcur),sizeof(double));
                consobin.write(reinterpret_cast<const char*> (&credapro),sizeof(double));        
                consobin.write(reinterpret_cast<const char*> (&matcur),sizeof(int));
                consobin.write(reinterpret_cast<const char*> (&snotas),sizeof(int));
                consobin.write(reinterpret_cast<const char*> (facultad),sizeof(char)*10);
                consobin.write(reinterpret_cast<const char*> (&estado),sizeof(int));

            }
        }
    }
    
    
    muestraconsolidado();
    
}
void imprimeconsolidado(){
    char tipo,nombre[100],especialidad[100],facultad[10];
    int codigo,snotas=0,matcur=0,estado=0;
    double credcur=0,credapro=0;   
    
    ifstream consobin("Consolidado.bin",ios::in|ios::binary);
    if(!consobin){
        cout << "No se puede abrir consolidado.bin";
        exit(1);
    }  
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout << "No se puede abrir Reporte.txt";
        exit(1);
    }      
    ImprimeLinea(arch,'=');  
    arch << setw(10)<<"Codigo"<<left<<setw(50)<<"Nombre"<<right<<setw(10)<<"Cred.Curs.";
    arch << setw(10)<<"Cred.Apr."<<setw(10)<<"Promedio"<<setw(20)<<"Estado"<<endl;    ImprimeLinea(arch,'=');
    while(1){
        consobin.read(reinterpret_cast< char*> (&codigo),sizeof(int));
        if(consobin.eof()) break;
        consobin.read(reinterpret_cast< char*> (nombre),sizeof(char)*100);
        consobin.read(reinterpret_cast< char*> (&credcur),sizeof(double));
        consobin.read(reinterpret_cast< char*> (&credapro),sizeof(double));        
        consobin.read(reinterpret_cast< char*> (&matcur),sizeof(int));
        consobin.read(reinterpret_cast< char*> (&snotas),sizeof(int));
        consobin.read(reinterpret_cast< char*> (facultad),sizeof(char)*10);
        consobin.read(reinterpret_cast< char*> (&estado),sizeof(int));

        arch <<setw(10) <<codigo <<setw(50)<< nombre << setprecision(2)<<fixed;
        arch << setw(10) <<credcur << setw(10)<< credapro <<" ";
        arch << setw(10) <<(double)snotas/matcur;
        if(estado)
            arch << "   Egresado";
        else
            arch << "   No egresado";
        arch << endl;
    
    }    
    
    
}



void generaconsolidado(){
    
    creaconsolidado();
    actualizaconsolidado();
}