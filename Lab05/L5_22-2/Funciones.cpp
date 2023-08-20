/* 
 * File:   Funciones.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 9 de mayo de 2023, 08:29 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define MAX 150
#define INCREMENTO 5
#include "Funciones.h"
using namespace std;

void AbrirArchivoLectura(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout << "ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

void AbrirArchivoEscritura(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout << "ERROR, no se pudo abrir el archivo "<<nomb;
        exit(1);
    }
}

char *leerCadena(ifstream &arch,char c){
    char *aux,buff[100];
    arch.getline(buff,100,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void cargarCitas(char *nomarch, char ***&medicoDatos, double *&medicoTarifaHora, char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago){
    ifstream arch;
    AbrirArchivoLectura(nomarch,arch);
    
    char *codigomedico, *nombremedico, *dni, *nombrepaciente, buffer[50], c;
    int cantidad, Ihh, Imm, Iss, Fhh, Fmm, Fss, posMed, numMed = 0, capMed = 0;
    double tiempo, tarifa; 
    int i, capPac[300]{}, numPac[300]{};
    
    medicoDatos = nullptr; 
    
    while(1){
        dni = leerCadena(arch,','); 
        if(arch.eof()) break;
        nombrepaciente = leerCadena(arch,',');
        codigomedico = leerCadena(arch,',');
        nombremedico = leerCadena(arch,',');
        arch >> tarifa;
        arch.get();
        arch.getline(buffer,50,',');
        arch >> Ihh >> c >> Imm >> c >> Iss >> c >> Fhh >> c >> Fmm >> c >> Fss;
        arch.get();
        
        posMed = buscarMedico(medicoDatos,codigomedico); 
        if (posMed == -1){
            posMed = numMed; 
            if (numMed == capMed) incrementarEspaciosMedicos(citaPaciente, citaCantidad, citaTiempoYPago, medicoDatos, medicoTarifaHora, capMed, numMed);
            agregarMedico(citaPaciente, citaCantidad, citaTiempoYPago, medicoDatos, medicoTarifaHora, codigomedico, nombremedico, tarifa, numMed, capMed);
        }
        agregarCitas(citaPaciente[posMed],citaCantidad[posMed],citaTiempoYPago[posMed],capPac[posMed],numPac[posMed],dni,nombrepaciente,tarifa,Ihh,Imm,Iss,Fhh,Fmm,Fss);
    }
}

int buscarMedico(char ***medicoDatos, char *codigomedico){
    int i;
    char **aux; 
    if(medicoDatos == nullptr) return -1;
    for(i=0;medicoDatos[i];i++){
        aux = medicoDatos[i];
        if(strcmp(aux[0],codigomedico) == 0) return i;
    }
    return -1;
}

int buscarPaciente(char *dni,char ***citaPaciente,int numPac){
    char **aux; 
    int i;
    if(citaPaciente == nullptr) return -1; 
    for(i=0;citaPaciente[i];i++){
        aux = citaPaciente[i]; 
        if(strcmp(dni,aux[0]) == 0) return i;
    }
    return -1; 
}

void agregarCitas(char ***&citaPaciente, int *&citaCantidad, double **&citaTiempoYPago, int &capPac, int &numPac, char *dni, char *nombrepaciente, double tarifa,int Ihh, int Imm, int Iss, int Fhh, int Fmm, int Fss){
    
    if(numPac == capPac) incrementarEspaciosCitas(citaPaciente,citaCantidad,citaTiempoYPago,capPac,numPac);
    
    char **aux1;
    double *aux2; 
    
    aux1 = new char*[2]{};
    aux2 = new double[2]; 
    
    double horas;
    int posPac = 1;
    posPac = buscarPaciente(dni,citaPaciente,numPac);
    
    horas = (Fhh - Ihh) + (Fmm - Imm) / 60.0 + (Fss - Iss)/3600.0;
    if(posPac == -1){
        aux1[0] = dni;
        aux1[1] = nombrepaciente; 

        aux2[0] = horas;
        aux2[1] = horas*tarifa; 
    
        citaPaciente[numPac] = nullptr; //terminador
        citaPaciente[numPac - 1] = aux1;
        citaCantidad[numPac - 1] = 1;
        citaTiempoYPago[numPac - 1] = aux2;
        citaTiempoYPago[numPac] = nullptr; 
        
        numPac++;
    }else{
        citaCantidad[posPac]++;
        aux2 = citaTiempoYPago[posPac];
        aux2[0] = aux2[0] + horas;
        aux2[1] = aux2[1] + horas*tarifa; 
    }
}

void agregarMedico(char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago, char ***&medicoDatos, double *&medicoTarifaHora, char *codigomedico, char *nombremedico, double tarifa, int &numMed, int &capMed){
    char **aux1;
    double aux2; 
    
    aux1 = new char*[2]{};
    
    aux1[0] = codigomedico;
    aux1[1] = nombremedico; 
    
    aux2 = tarifa; 
    
    medicoDatos[numMed] = nullptr;
    medicoDatos[numMed-1] = aux1; 
    medicoTarifaHora[numMed] = -1;
    medicoTarifaHora[numMed-1] = aux2; 
    numMed++; 
}

void incrementarEspaciosCitas(char ***&citaPaciente, int *&citaCantidad, double **&citaTiempoYPago, int &cap, int &numPac){
    char ***auxpaciente;
    double **citatiempo;
    int *citacantidad; 
    
    cap += INCREMENTO;
    if (citaPaciente == nullptr) {
        citaPaciente = new char **[cap];
        citaTiempoYPago = new double *[cap];
        citaCantidad = new int[cap]; 
        
        citaPaciente[0] = nullptr;
        citaTiempoYPago[0] = nullptr;
        citaCantidad[0] = -1; 
        
        numPac = 1;
    }else{
        auxpaciente = new char **[cap];
        citatiempo = new double *[cap];
        citacantidad = new int[cap]; 
        for (int i = 0; i < numPac; i++){
            auxpaciente[i] = citaPaciente[i];
            citatiempo[i] = citaTiempoYPago[i];
            citacantidad[i] = citaCantidad[i]; 
        }
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        
        citaPaciente = auxpaciente;
        citaCantidad = citacantidad;
        citaTiempoYPago = citatiempo; 
    }
}

void incrementarEspaciosMedicos(char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago, char ***&medicoDatos, double *&medicoTarifaHora, int &cap, int &numMed){
    int i; 
    char ***auxC;
    double *auxP;
    char ****aux1;
    int **aux2;
    double ***aux3;
    
    cap += INCREMENTO;
    if (medicoDatos == nullptr) {
        medicoDatos = new char **[cap];
        medicoTarifaHora = new double [cap];
        
        citaPaciente = new char ***[cap]; 
        citaCantidad = new int *[cap];
        citaTiempoYPago = new double **[cap];
        
        for(i=0;i<numMed;i++) citaPaciente[i] = nullptr; 
        
        medicoDatos[0] = nullptr;
        medicoTarifaHora[0] = -1;
        
        numMed = 1;
    }else{
        auxC = new char **[cap];
        auxP = new double [cap];
        
        aux1 = new char ***[cap]; 
        aux2 = new int *[cap];
        aux3 = new double **[cap];
        
        
        for (i = 0; i < numMed; i++){
            auxC[i] = medicoDatos[i];
            auxP[i] = medicoTarifaHora[i];
        }
        
        for (i = 0; i < numMed; i++){
            aux1[i] = citaPaciente[i];
            aux2[i] = citaCantidad[i];
            aux3[i] = citaTiempoYPago[i]; 
        }
        
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        citaPaciente = aux1;
        citaCantidad = aux2;
        citaTiempoYPago = aux3;
        
        delete medicoDatos;
        delete medicoTarifaHora;
        medicoDatos = auxC;
        medicoTarifaHora = auxP;
    }
}

void ReporteDeCitasPorMedico(const char*nombArch,char ***medicoDatos,double *medicoTarifaHora,
        char ****citaPaciente,int **citaCantidad,double ***citaTiempoYPago){
    ofstream repo(nombArch,ios::out);
    if(!repo){
        cout <<"no se pudo abir el archivo de reporte prueba";
        exit(1);
    }
    char **auxMedDat, ***auxCit,**auxUnPac;
    int *auxCitCant;
    double **auxCitTiemPag,*auxUnCita;
    repo << "CLINICA PSICOLOGICA LP1" << endl;
    imprimeLinea(repo,MAX,'=');
    repo << "RELACION DE CITAS POR MEDICO" << endl;
    
    int totCit;
    double tiemTot,PagTot;
    for(int i=0;medicoDatos[i];i++){
        imprimeLinea(repo,MAX,'=');
        repo << left << setw(20) << "CODIGO" << setw(50) << "NOMBRE" << setw(50) << "TARIFA POR HORA DE CONSULTA: " << medicoTarifaHora[i] << endl;
        auxMedDat = medicoDatos[i];
        repo << setw(20) << auxMedDat[0] << setw(20) <<auxMedDat[1] << endl;
        imprimeLinea(repo,MAX,'-');
        repo << "RELACION DE PACIENTES ATENDIDOS" << endl;
        imprimeLinea(repo,MAX,'-');
        auxCit = citaPaciente[i];
        auxCitCant = citaCantidad[i];//seria tipo ese paciente tiene # de citas para este medico
        auxCitTiemPag = citaTiempoYPago[i];
        repo << setw(20) << "DNI" << setw(20) << "Nombre" << setw(20) << "Cantidad de Citas" << setw(20) << "Tiempo Total (hrs)" << setw(20) << "Pago Total"<< endl;
        imprimeLinea(repo,MAX,'-');
        tiemTot=0;PagTot=0; totCit =0;
        for(int k=0;auxCit[k];k++){//AHORA RECORREMOS POR PACIENTE
            auxUnPac = auxCit[k];
            auxUnCita = auxCitTiemPag[k];
            repo << setw(2) << k+1 << left << setw(10) << " " << setw(10) << auxUnPac[0] << setw(50) << auxUnPac[1] 
                    << setw(10) << auxCitCant[k] << setw(10) << auxUnCita[0] 
                    << setw(10) << auxUnCita[1] << endl;
            tiemTot += auxUnCita[0];
            PagTot += auxUnCita[1];
            totCit += auxCitCant[k];
        }
        imprimeLinea(repo,MAX,'-');
        repo << "TOTAL:" << setw(20) << totCit << setw(20) << tiemTot << setw(20) << PagTot << endl;
    }
}

void imprimeLinea(ofstream &repo,int n,char c){
    for(int i=0;i<n;i++) repo << c;
    repo << endl;
}