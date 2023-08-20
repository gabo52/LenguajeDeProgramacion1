/* 
 * File:   sobrecarga.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 26 de abril de 2023, 07:43 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "sobrecarga.h"
#include "Estructura.h"
using namespace std;

void operator >> (ifstream &in,struct StMedico &medico){
    in >> medico.codigo;
    if(in.eof()) return;
    in >> medico.nombre >> medico.especialidad >> medico.tarifa;
}

ifstream &operator >> (ifstream &in,struct StPaciente &paciente){
    
    in >> paciente.estado; 
    if(in.eof()) return in;
    in >> paciente.codigo >> paciente.nombre >> paciente.prima;
    
    return in;
}

void operator+(struct StMedico &medico, const struct StPaciente paciente){
    medico.fechas[medico.numPac] = paciente.fecha;
    medico.estado[medico.numPac] = paciente.estado;
    medico.prima[medico.numPac] = paciente.prima;
    medico.pacientes[medico.numPac] = paciente.codigo;
    medico.numPac++; 
}

void operator+(struct StMedico &medico, const int fecha){
    int i; 
    for(i=0;i<medico.numPac;i++){
        if(medico.fechas[i] == fecha) medico.estado[i] = 'R'; 
    }
}

void operator - (struct StMedico &medico, const int fecha){
    int i,j;
    for(i=0;i<medico.numPac;i++){
        if(medico.fechas[i] == fecha && medico.estado[i] == 'R'){
            for(j=i;j<medico.numPac-1;j++){
                medico.fechas[j] = medico.fechas[j+1];
                medico.estado[j] = medico.estado[j+1];
                medico.prima[j] = medico.prima[j+1];
                medico.pacientes[j] = medico.pacientes[j+1];     
            }
            medico.numPac--; 
        }
    }
}
 
void operator / (struct StMedico &medico, const int fecha){
    int i,j;
    for(i=0;i<medico.numPac;i++){
        if(medico.fechas[i] < fecha && medico.estado[i] == 'A'){
            for(j=i;j<medico.numPac-1;j++){
                medico.fechas[j] = medico.fechas[j+1];
                medico.estado[j] = medico.estado[j+1];
                medico.prima[j] = medico.prima[j+1];
                medico.pacientes[j] = medico.pacientes[j+1];     
            }
            medico.numPac--; 
        }
    }
}

void operator ++(struct StMedico &medico, int b){
    int i, ingresosS = 0, ingresosP = 0; 
    for(i=0;i<medico.numPac;i++){
        ingresosP = ingresosP + (double)(medico.prima[i]/100) * medico.tarifa;
        ingresosS = ingresosS + (double)(100 - medico.prima[i])/100 * medico.tarifa;
    }
    medico.ingresosP = ingresosP;
    medico.ingresosS = ingresosS;
}

void operator << (ofstream &out, const struct StMedico &medico){
    int i, aa, mm, dd; 
    out.precision(2);
    out << fixed;
    
    out << "Medico: " << medico.nombre << endl;
    out << "Codigo: " << medico.codigo << endl;
    out << "Especialidad: " << medico.especialidad << endl;
    out << "Honorarios por cita: " << medico.tarifa << endl;
    imprimirLinea(out,100,'=');
    out << "Pacientes atendidos: " << endl;
    imprimirLinea(out,100,'-');
    out << "No.      Fecha      Paciente      Pago     Seguro" << endl;
    int a = 0;
    for(i=0;i<medico.numPac;i++){
        if(medico.estado[i] == 'A'){
            aa = medico.fechas[i] / 10000; 
            mm = (medico.fechas[i] % 10000)/100; 
            dd = (medico.fechas[i] % 10000)%100; 
            out << setw(2) << a+1 << ")   " << left << setfill('0') << setw(2) << dd << "/" << setw(2) << mm << "/" << aa << right << setfill(' ') << setw(5) 
                << " " << medico.pacientes[i] << setw(5) << " " << setw(6) << (double)(medico.prima[i])/100 * medico.tarifa 
                << setw(5) << " " << setw(6) << (double)(100 - medico.prima[i])/100 * medico.tarifa << endl;  
            a++;
        }
    }
    imprimirLinea(out,100,'=');
    out << "Pacientes por atender: " << endl;
    imprimirLinea(out,100,'-');
    out << "No.      Fecha      Paciente      Pago     Seguro" << endl;
    a = 0;
    for(i=0;i<medico.numPac;i++){
        if(medico.estado[i] == 'R'){
            aa = medico.fechas[i] / 10000; 
            mm = (medico.fechas[i] % 10000)/100; 
            dd = (medico.fechas[i] % 10000)%100; 
            out << setw(2) << a+1 << ")   " << left << setfill('0') << setw(2) << dd << "/" << setw(2) << mm << "/" << aa << right << setfill(' ') << setw(5) 
                << " " << medico.pacientes[i] << setw(5) << " " << setw(6) << (double)(medico.prima[i])/100 * medico.tarifa 
                << setw(5) << " " << setw(6) << (double)(100 - medico.prima[i])/100 * medico.tarifa << endl;  
            a++;
        }
    }
    imprimirLinea(out,100,'=');
    out << "Monto total recibir por pacientes:   " << setw(8) << medico.ingresosP << endl;
    out << "Monto a solicitar al seguro:         " << setw(8) << medico.ingresosS << endl;
    imprimirLinea(out,100,'=');
}

void imprimirLinea(ofstream &out, int n, char c){
    int i; 
    for(i=0;i<n;i++) out << c;
    out << endl; 
}