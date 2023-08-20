/* 
 * File:   Funciones.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 18 de abril de 2023, 08:13 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define MAXCAD 150
#include "Funciones.h"
using namespace std;

void sacaespecialidad(char *esp, char *medico){
    int flag = 0, j = 0; 
    for(int i=0;i<MAXCAD;i++){
        if(medico[i] == '_' && medico[i+2] >= 'a' && medico[i+2] <= 'z'){
            medico[i] = '\0';
            flag = 1; 
        }
        if(flag){
            esp[j] = medico[i+1];
            j++;
            if(medico[i+1] == '\0') break; 
        }
    }
    esp[j] = '\0'; 
}

void leerarchivos(){
    double precio; 
    int cantMedicinas, dni, dd, mm, aa, codMedicina, i;
    char car, nomDoc[100], codDoc[10], nomPac[100], descripcion[100];
    
    ifstream arch("Medico-Paciente-Medicinas.txt", ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo Medico-Paciente-Medicinas.txt";
        exit(1);
    }
    
    ofstream archMedicos("Medicos.txt", ios::out);
    if(!archMedicos){
        cout << "No se pudo abrir el archivo Medicos.txt";
        exit(1);
    }
    
    ofstream archPacientes("Pacientes.bin", ios::out | ios::binary);
    if(!archPacientes){
        cout << "No se pudo abrir el archivo Pacientes.bin";
        exit(1);
    }
    
    ofstream archMedicinas("Medicinas.bin", ios::out | ios::binary);
    if(!archMedicinas){
        cout << "No se pudo abrir el archivo Medicinas.bin";
        exit(1);
    }
    
    ofstream archConsultas("Consultas.txt", ios::out);
    if(!archConsultas){
        cout << "No se pudo abrir el archivo Consultas.txt";
        exit(1);
    }
    
    while(1){
        arch >> dni; 
        if(arch.eof()) break;
        if(arch.fail()){
            arch.clear();
            arch >> codDoc >> nomDoc;
            insertamedico(archMedicos, codDoc, nomDoc); 
        }else{
            arch >> nomPac >> codDoc >> dd >> car >> mm >> car >> aa >> cantMedicinas;
            insertapaciente(archPacientes, dni, nomPac);
            insertaconsultas(archConsultas, dni, codDoc, dd, mm, aa, cantMedicinas);
            for(i=0;i<cantMedicinas;i++){
                arch >> codMedicina >> descripcion >> precio; 
                insertamedicamento(archMedicinas, codMedicina, descripcion, precio);
                insertaconsultamed(archConsultas, codMedicina);
            }
            archConsultas << endl; 
        }
    }
}

void imprimearchivo(){
    ifstream arch("Medico-Paciente-Medicinas.txt", ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo Medico-Paciente-Medicinas.txt";
        exit(1);
    }
    
    ifstream archMedicos("Medicos.txt", ios::in);
    if(!archMedicos){
        cout << "No se pudo abrir el archivo Medicos.txt";
        exit(1);
    }
    
    ifstream archPacientes("Pacientes.bin", ios::in | ios::binary);
    if(!archPacientes){
        cout << "No se pudo abrir el archivo Pacientes.bin";
        exit(1);
    }
    
    ifstream archMedicinas("Medicinas.bin", ios::in | ios::binary);
    if(!archMedicinas){
        cout << "No se pudo abrir el archivo Medicinas.bin";
        exit(1);
    }
    
    ifstream archConsultas("Consultas.txt", ios::in);
    if(!archConsultas){
        cout << "No se pudo abrir el archivo Consultas.txt";
        exit(1);
    }
    
    ofstream archReporte("Reporte.txt", ios::out);
    if(!archReporte){
        cout << "No se pudo abrir el archivo Reporte.txt";
        exit(1);
    }
    
    imprimirmedicos(archReporte, archMedicos);
   
}

void imprimirmedicos(ofstream &archReporte, ifstream &archMedicos){
    char codmed[10], especialidad[50], medico[100];
    
    while(1){
        archMedicos >> codmed;
        if(archMedicos.eof()) break; 
        archMedicos >> medico >> especialidad;
        archReporte << setw(10) << codmed << setw(50) << medico << setw(50) << especialidad << endl;
    }
}

void insertaconsultamed(ofstream &archConsultas, int codMedicina){
    archConsultas << setw(10) << codMedicina; 
    
}

void insertamedicamento(ofstream &archMedicinas, int codMedicina, char *descripcion, double precio){
    int flag;
    
    flag = verifica(codMedicina, "Medicinas.bin");
    if(!flag){
        archMedicinas.write(reinterpret_cast< const char *>(&codMedicina), sizeof(int));
        archMedicinas.write(reinterpret_cast< const char *>(descripcion), sizeof(char)*100);
        archMedicinas.write(reinterpret_cast< const char *>(&precio), sizeof(double));
        archMedicinas.flush(); 
    }
    
}

void insertaconsultas(ofstream &archConsultas, int dni, char *codDoc, int dd, int mm, int aa, int cantMedicinas){
    archConsultas << setw(10) << dni << setw(10) << codDoc << setw(4) << " " << setw(2) << dd << "/" << setw(2) << mm << "/" << setw(4) << aa << setw(10) << cantMedicinas; 
}

void insertamedico(ofstream &med, char *codmed, char *medico){
    char especialidad[50];
    sacaespecialidad(especialidad, medico);
    med << setw(10) << codmed << setw(50) << medico << setw(50) << especialidad << endl; 
}

void insertapaciente(ofstream &archPacientes, int dni, char *nombre){
    int flag; 
    double gasto = 0; 
    
    flag = verifica(dni, "Pacientes.bin");
    if(!flag){
        archPacientes.write(reinterpret_cast< const char *>(&dni), sizeof(int));
        archPacientes.write(reinterpret_cast< const char *>(nombre), sizeof(char)*100);
        archPacientes.write(reinterpret_cast< const char *>(&gasto), sizeof(double));
        archPacientes.flush(); 
    }
}

void insertamedicinas(ofstream &archMedicinas, int codMedicina, char *descripcion, double precio){
    int flag;
    
    if(!flag){
        archMedicinas.write(reinterpret_cast< const char *>(&codMedicina), sizeof(int));
        archMedicinas.write(reinterpret_cast< const char *>(descripcion), sizeof(char)*100);
        archMedicinas.write(reinterpret_cast< const char *>(&precio), sizeof(double));
        archMedicinas.flush(); 
    }
}

int verifica(int dni, const char *cad){
    int dni2; 
    double gasto; 
    char nombre[100]; 
    
    ifstream archPacientes(cad, ios::in | ios::binary);
    if(!archPacientes){
        cout << "No se pudo abrir el archivo Pacientes.bin";
        exit(1);
    }
    
    while(1){
        archPacientes.read(reinterpret_cast< char *>(&dni2), sizeof(int));
        if(archPacientes.eof()) break; 
        archPacientes.read(reinterpret_cast< char *>(nombre), sizeof(char)*100);
        archPacientes.read(reinterpret_cast< char *>(&gasto), sizeof(double));
        if(dni == dni2) return 1; 
    }
    return 0; 
}







