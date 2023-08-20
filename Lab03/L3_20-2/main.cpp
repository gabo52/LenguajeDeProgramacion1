/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 26 de abril de 2023, 07:43 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Estructura.h"
#include "sobrecarga.h"
using namespace std;

int buscaMedico(char *codigoMedico, struct StMedico *medicos, int n){
    int i;
    for(i=0;i<n;i++){
        if(!strcmp(medicos[i].codigo,codigoMedico)) return i;
    }
    return -1; 
}


int main(int argc, char** argv) {
    int i = 0, j = 0, dd, mm, aa, fecha = 0, posicion = 0, opcion;
    char car, codigoMedico[10], codigo[10];
    struct StMedico medicos[300]; 
    struct StPaciente pacientes[3000]; 
    
    ifstream archMedicos("Medicos.txt", ios::in);
    if(!archMedicos){
        cout << "El archivo Medicos.txt no existe";
        exit(1);
    }
    
    ifstream archConsultas("AtencionPacientes.txt", ios::in);
    if(!archConsultas){
        cout << "El archivo AtencionPacientes.txt no existe";
        exit(1);
    }
    
    ifstream archAcciones("Acciones.txt", ios::in);
    if(!archAcciones){
        cout << "El archivo Acciones.txt no existe";
        exit(1);
    }
    
    ofstream archReporte("Reporte.txt", ios::out);
    if(!archReporte){
        cout << "El archivo Reporte.txt no existe";
        exit(1);
    }
    
    while(1){
        archMedicos >> medicos[i]; 
        if(archMedicos.eof()) break; 
        i++; 
    }
    
    int flag = 1; 
    while(1){
        archConsultas >> dd;
        if(archConsultas.eof()) break;
        if(archConsultas.fail()){
            archConsultas.clear(); 
            pacientes[j].fecha = fecha;
            archConsultas >> pacientes[j];
            archConsultas >> codigoMedico; 
            posicion = buscaMedico(codigoMedico,medicos,i); 
            
            medicos[posicion] + pacientes[j]; 
            j++; 
        }else{
            archConsultas >> car >> mm >> car >> aa; 
            fecha = aa*10000 + mm*100 + dd;
        }
    }
    
    for(int l=0;l<i;l++) medicos[l]++;
    for(int l=0;l<i;l++) archReporte << medicos[l];
    
    int main(){
    int d, mm, aa, dd;
    char cad[30], c;
    while(1){
        archAcciones >> d;
	  if(cin.eof()) break;
	  cout << d << " ";
	  while(1){
	  	cin >> dd;
            if(cin.fail()){ //no es ni el inicio ni el dia
            	cin.clear();
            	cin >> cad;
			cout <<  cad << endl;
        	}
        	else{ //dia
            	cin >> c >> mm >> c >> aa;
			cout << dd << c << mm << c << aa << endl;
        	}
		if (cin.get() == '\n') break;
        }
    }

}
    
    return 0;
}


