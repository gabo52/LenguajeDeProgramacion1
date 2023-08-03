/* 
 * File:   sobrecarga.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de abril de 2023, 04:15 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "sobrecarga.h"
#include "Estructura.h"
using namespace std;

bool operator >> (ifstream &in, struct ConductorSt &conductor){
    in >> conductor.licencia;
    if(in.eof()) return false;
    in >> conductor.nombre;
    conductor.montoFaltasGraves = 0;
    conductor.montoFaltasLeves = 0;
    conductor.montoFaltasMuyGraves = 0;
    conductor.numFaltas = 0;
    conductor.numFaltasGraves = 0;
    conductor.numFaltasMuyGraves = 0;
    return true; 
}

bool operator >> (ifstream &in, struct InfraccionSt &infraccion){
    int aa, dd, mm;
    char car;
    
    in >> infraccion.licencia;
    if(in.eof()) return false;
    in >> infraccion.placa >> dd >> car >> mm >> car >> aa >> infraccion.codInf;
    infraccion.fecha = aa*10000 + mm*100 + dd; 
    return true;
}

bool operator >> (ifstream &in, struct InfraccionEstabSt &infraccion){
    char descripcion[1000];
    
    in >> infraccion.codigo;
    if(in.eof()) return false;
    in >> descripcion >> infraccion.gravedad >> infraccion.multa;
    return true;
}

void operator+(struct ConductorSt &conductor, const struct InfraccionSt infraccion){
    conductor.faltas[conductor.numFaltas].codInf = infraccion.codInf; 
    conductor.faltas[conductor.numFaltas].fecha = infraccion.fecha; 
    strcpy(conductor.faltas[conductor.numFaltas].placa,infraccion.placa); 
    conductor.numFaltas++; 
}

void operator+(struct ConductorSt &conductor, const struct InfraccionEstabSt infraccion){
    int posicion, i; 
    for(i=0;i<conductor.numFaltas;i++){
        if(conductor.faltas[i].codInf == infraccion.codigo){
            conductor.faltas[i].multa = infraccion.multa; 
            strcpy(conductor.faltas[i].gravedad,infraccion.gravedad); 
        }   
    }    
}

int buscarInfraccion(const struct ConductorSt conductor, int codigo){
    int i; 
    for(i=0;i<conductor.numFaltas;i++){
        if(conductor.faltas[i].codInf == codigo) return i;
    }
    return -1; 
}

void operator ++(struct ConductorSt &conductor, int b){
    int i;
    double montoLeve = 0, montoGrave = 0, montoMuyGrave = 0;
    
    for(i=0;i<conductor.numFaltas;i++){
        if(!strcmp(conductor.faltas[i].gravedad,"Leve")){
            conductor.numFaltasLeves++; 
            conductor.montoFaltasLeves = conductor.montoFaltasLeves + conductor.faltas[i].multa;
        }
        if(!strcmp(conductor.faltas[i].gravedad,"Grave")){
            conductor.numFaltasGraves++; 
            conductor.montoFaltasGraves = conductor.montoFaltasGraves + conductor.faltas[i].multa;
        }
        if(!strcmp(conductor.faltas[i].gravedad,"Muy_Grave")){
            conductor.numFaltasMuyGraves++; 
            conductor.montoFaltasMuyGraves = conductor.montoFaltasMuyGraves + conductor.faltas[i].multa;
        }
    }
}

void operator*(struct ConductorSt &conductor, int fecha){
    int i,j; 
    for(i=0;i<conductor.numFaltas;i++){
        if(conductor.faltas[i].fecha < fecha){
            if(!strcmp(conductor.faltas[i].gravedad, "Leve")){
                conductor.montoFaltasLeves = conductor.montoFaltasLeves - conductor.faltas[i].multa;
                for(j=i;j<conductor.numFaltas-1;j++){
                    conductor.faltas[j].codInf = conductor.faltas[j+1].codInf;
                    conductor.faltas[j].fecha = conductor.faltas[j+1].fecha;
                    conductor.faltas[j].multa = conductor.faltas[j+1].multa;
                    strcpy(conductor.faltas[j].gravedad, conductor.faltas[j+1].gravedad);     
                    strcpy(conductor.faltas[j].placa, conductor.faltas[j+1].placa);     
                }
                conductor.numFaltas--; 
                conductor.numFaltasLeves--;
            }
            if(!strcmp(conductor.faltas[i].gravedad, "Grave")){
                conductor.montoFaltasGraves = conductor.montoFaltasGraves - conductor.faltas[i].multa * (double) 25/100;
                conductor.faltas[i].multa = conductor.faltas[i].multa * (double) 75/100;
            }
            if(!strcmp(conductor.faltas[i].gravedad, "Muy_Grave")){
                conductor.montoFaltasMuyGraves = conductor.montoFaltasMuyGraves - conductor.faltas[i].multa * (double) 8/100;
                conductor.faltas[i].multa = conductor.faltas[i].multa * (double) 92/100;
            }
        }
    }
}

ofstream &operator << (ofstream &out, const struct ConductorSt &conductor){
    int i, dd, mm, aa; 
    out.precision(2);
    out << fixed;
    out << "Conductor    : " << conductor.nombre << endl;
    out << "Licencia No. : " << conductor.licencia << endl;
    imprimirLinea(out,100,'=');
    out << "Infracciones cometidas: " << endl;
    imprimirLinea(out,100,'-');
    for(i=0;i<conductor.numFaltas;i++){
        aa = conductor.faltas[i].fecha / 10000;
        mm = (conductor.faltas[i].fecha%10000)/100;
        dd = (conductor.faltas[i].fecha%10000)%100;
        out << setw(2) << i+1 << ")   " << left << setfill('0') << setw(2) << dd << "/" << setw(2) << mm << "/" << aa << setfill(' ') << right << "   " << conductor.faltas[i].codInf 
            << setw(5) << " " << left << setw(10) << conductor.faltas[i].gravedad << right << setw(5) << " " << setw(6) << conductor.faltas[i].multa << endl; 
    }
    imprimirLinea(out,100,'=');
    out << setw(25) << " " << " Cantidad       Total" << endl;
    out << "Infracciones leves:           " << conductor.numFaltasLeves << setw(10) << " " << conductor.montoFaltasLeves << endl;
    out << "Infracciones graves:          " << conductor.numFaltasGraves << setw(10) << " " << conductor.montoFaltasGraves << endl;
    out << "Infracciones muy graves:      " << conductor.numFaltasMuyGraves << setw(10) << " " << conductor.montoFaltasMuyGraves << endl; 
    imprimirLinea(out,100,'=');
}

void imprimirLinea(ofstream &out, int n, char c){
    int i; 
    for(i=0;i<n;i++) out << c;
    out << endl;
}