/* 
 * File:   MemoriaDinamica.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 4 de mayo de 2023, 08:26 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "MemoriaDinamica.h"
#include <cstring>
using namespace std;

void cargarMedicos(char **&codigoMed, char **&medicos, double *&tarifas){
    ifstream arch("RelacionMedicos.csv", ios::in); 
    if(!arch){
        cout << "El archivo RelacionesMedicos.csv no existe";
        exit(1);
    }
    
    int i, numDat = 0;
    double auxtarifa[100], tarifa;
    char *cad1, *cad2, *auxcodigo[100], *auxmedico[100], especialidad[100];
    
    while(1){
        cad1 = leeCadena(arch,',');
        if(arch.eof()) break; 
        cad2 = leeCadena(arch,',');
        arch.getline(especialidad,100,',');
        arch >> tarifa; 
        arch.get(); 
        
        auxcodigo[numDat] = cad1;
        auxmedico[numDat] = cad2;
        auxtarifa[numDat] = tarifa; 
        numDat++; 
    }
    
    codigoMed = new char*[numDat+1];
    medicos = new char*[numDat+1];
    tarifas = new double[numDat+1];
    
    for(i=0;i<numDat;i++){
        codigoMed[i] = auxcodigo[i];
        medicos[i] = auxmedico[i]; 
        tarifas[i] = auxtarifa[i]; 
    }
            
    codigoMed[numDat] = nullptr;       
    medicos[numDat] = nullptr; 
}

void reporteMedicos(char **codigoMed, char **medicos, double *tarifas){
    int i;
    ofstream arch("ReporteMedicos.txt", ios::out);
    if(!arch){
        cout << "El archivo ReporteMedicos.txt no existe";
        exit(1);
    }
    
    arch.precision(2);
    arch << fixed; 
    for(i=0;codigoMed[i];i++) arch << left << setw(10) << codigoMed[i] << setw(50) << medicos[i] << setw(7) << tarifas[i] << endl; 
}

void reporteDeIngresos(char **codigoMed, char **medicos, double *tarifas){
    int *codigoPac, *veces;
    char **pacientes, codMed[7];
    double *porcentajes; 
    
    ifstream archMedicos("Medicos.csv", ios::in); 
    if(!archMedicos){
        cout << "El archivo Medicos.csv no existe";
        exit(1);
    }
    
    while(1){
        archMedicos >> codMed; 
        if(archMedicos.eof()) break; 
        cargarPacientes(codMed,codigoPac,pacientes,porcentajes,veces); 
        reporteDelMedico(codMed,codigoMed,medicos,tarifas,codigoPac,pacientes,porcentajes,veces);
    }
}

void cargarPacientes(char *codMed,int *&codigoPac, char **&pacientes, double *&porcentajes, int *&veces){
    int i, dd, mm, aa, codigopaciente, numDat = 0, pos = 0, auxcodigopac[500], auxveces[500];
    double porc, auxporcentajes[500];
    char *cad, codmedico[200], nombrepac[200], estado, car, *auxpacientes[500]; 
    
    ifstream arch("Pacientes-Atencion.csv", ios::in); 
    if(!arch){
        cout << "El archivo Pacientes-Atencion.csv no existe";
        exit(1);
    }
    
    while(1){
        arch >> dd;
        if(arch.eof()) break; 
        if(arch.fail()){
            arch.clear(); 
            arch >> estado >> car >> codigopaciente >> car;
            cad = leeCadena(arch,','); 
            //arch.getline(nombrepac,200,',');
            arch >> porc >> car;
            arch.getline(codmedico,200,','); 
            if(strcmp(codmedico,codMed) == 0 && estado == 'A'){
                //buscamos si el paciente es repetido
                pos = buscarpaciente(auxcodigopac, numDat,codigopaciente); 
                if(pos != -1){
                    auxveces[pos]++; 
                }else{
                    auxcodigopac[numDat] = codigopaciente;
                    auxpacientes[numDat] = cad; 
                    auxporcentajes[numDat] = porc; 
                    auxveces[numDat] = 0; 
                    numDat++; 
                }
                
            }
        }else{
            arch >> car >> mm >> car >> aa >> car; 
        }
    }
    
    codigoPac = new int[numDat + 1];
    pacientes = new char *[numDat + 1];
    porcentajes = new double[numDat + 1];
    veces = new int[numDat + 1]; 
    
    for(i=0;i<numDat;i++){
        codigoPac[i] = auxcodigopac[i];
        pacientes[i] = auxpacientes[i]; 
        porcentajes[i] = auxporcentajes[i]; 
        veces[i] = auxveces[i]; 
    }
    
    codigoPac[numDat] = -1; 
}

void reporteDelMedico(char *codMed, char **codigoMed, char **medicos, double *tarifas,int *codigoPac, char **pacientes, double *porcentajes, int *veces){
    int i; 
    
    for(i=0;codigoMed[i];i++) if(strcmp(codigoMed[i],codMed) == 0) break; 
    
    ofstream arch("ReporteDelMedico.txt", ios::out);
    
    arch << "Medico: " << medicos[i] << endl;
    arch << "Codigo: " << codigoMed[i] << endl;
    arch << "Honorarios por cita: " << tarifas[i] << endl; 
}

int buscarpaciente(int *auxcodigopac,int numDat, int codigopaciente){
    int i; 
    for(i=0;i<numDat;i++){
        if(auxcodigopac[i] == codigopaciente) return i; 
    }
    return -1; 
}

char *leeCadena(ifstream &arch){
    char *cad, buff[100];
    arch.getline(buff,100);
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char *leeCadena(ifstream &arch,char c){
    char *cad,buff[100];
    arch.getline(buff,100,c);
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}