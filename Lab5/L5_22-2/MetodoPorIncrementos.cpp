/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MetodoPorIncrementos.cpp
 * Author: cesar
 * 
 * Created on 07 May 2023, 20:14
 */

#include "MetodoPorIncrementos.h"
#define INCREMENTO 5
#define MAXLINEA 200
//51873364,Calixto/Erick,DY2694,DELICIA ARCA AQUINO,523.53,8/07/2022,11:45:44,12:49:11
//dniPac,nomPac,codMed,nomMed,tarifaxhora,dd/mm/aa,hi:mi:si,hf:mf:sf
void cargarCitas(const char* nomArch,char***& medicoDatos,double*& medicoTarifaHora,
char****& citaPaciente,int**& citaCantidad,double***& citaTiempoYPago){
    ifstream arch(nomArch, ios::in);
    if(!arch){
        cerr << "ERROR No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int ind,cond, dd, mm, aa, hi, mi, si, hf, mf, sf, nd = 0, cap = 0, nPac[300], capPac[300]; //nd incrementa con el num med
    char c, *dni, *nomPac, *nomMed, *codMed;
    double tarifa;
    for(int i = 0; i < 300; i++){ 
        nPac[i] = 0;
        capPac[i] = 0;
    }
    while(1){
        cond = leerCadena(arch,dni);
        if(cond == 0) break;
        leerCadena(arch,nomPac);
        leerCadena(arch,codMed);
        leerCadena(arch,nomMed);
        arch >> tarifa >> c >> dd >> c >> mm >> c >> aa >> c >> hi >> c >> mi 
        >> c >> si >> c >> hf >> c >> mf >> c >> sf >> c; //ultimo c para el salto de linea
        ind = noesrepetido(codMed,medicoDatos,nd);
        if(nd == cap)
            incrementarArrMed(medicoDatos, medicoTarifaHora, citaPaciente,
            citaCantidad,citaTiempoYPago,cap,nd);
        if(ind == -1){ //solo caso nuevo med
            ind = nd;
            agregarMedico(medicoDatos[nd - 1],medicoTarifaHora[nd - 1],tarifa,codMed,nomMed,nd);
            medicoDatos[nd - 1] = nullptr; //en la funcion agregar se increment'o
        }
        if(nPac[ind] == capPac[ind]) //solo si ya no caben pacientes
            incrementarArrCitas(citaPaciente[ind],citaCantidad[ind],citaTiempoYPago[ind],capPac[ind], nPac[ind]);
        agregarDatos(citaPaciente[ind],dni,nomPac,citaCantidad[ind],citaTiempoYPago[ind],
        nPac[ind],hi,mi,si,hf,mf,sf,tarifa);
    }
}

void incrementarArrMed(char***& medicoDatos,double*& medicoTarifaHora,char****& citaPaciente,
int**& citaCantidad,double ***&citaTiempoYPago,int& cap,int& nd){
    cap += INCREMENTO;
    char ***auxDat, ****auxPac;
    int **auxCant;
    double *auxTarif, ***auxTiemp;
    if(nd == 0){
        medicoDatos = new char**[cap];
        medicoTarifaHora = new double[cap];
        citaPaciente = new char***[cap];
        citaCantidad = new int *[cap];
        citaTiempoYPago = new double**[cap];
        medicoDatos[0] = nullptr;
        nd = 1;
    }
    if(nd > 1){
        auxDat = new char**[cap];
        auxTarif = new double[cap];
        auxPac = new char***[cap];
        auxCant = new int *[cap];
        auxTiemp = new double**[cap];
        for(int i = 0; i < nd; i++){
            auxDat[i] = medicoDatos[i];
            auxTarif[i] = medicoTarifaHora[i];
            auxPac[i] = citaPaciente[i];
            auxCant[i] = citaCantidad[i];
            auxTiemp[i] = citaTiempoYPago[i];
        }
        delete medicoDatos;
        delete medicoTarifaHora;
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        medicoDatos = auxDat;
        medicoTarifaHora = auxTarif;
        citaPaciente = auxPac;
        citaCantidad = auxCant;
        citaTiempoYPago = auxTiemp;
    }    
}
void incrementarArrCitas(char***& citaPaciente,int*& citaCantidad,
double**& citaTiempoYPago,int& capPac, int& nPac){
    capPac += INCREMENTO;
    char*** auxPac;
    int *auxCant;
    double **auxTiemp;
    if(nPac == 0){
        citaPaciente = new char**[capPac];
        citaCantidad = new int[capPac];
        citaTiempoYPago = new double*[capPac];
        citaPaciente[0] = nullptr;
        nPac = 1;
    }
    if(nPac > 1){
        auxPac = new char**[capPac];
        auxCant = new int[capPac];
        auxTiemp = new double*[capPac];
        for(int i = 0; i < nPac; i++){
            auxPac[i] = citaPaciente[i];
            auxCant[i] = citaCantidad[i];
            auxTiemp[i] = citaTiempoYPago[i];
        }
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        citaPaciente = auxPac;
        citaCantidad = auxCant;
        citaTiempoYPago = auxTiemp;
    }
}
void agregarDatos(char***& citaPaciente,char* dni,char* nomPac,int*& citaCantidad,
double**& citaTiempoYPago,int& nPac,int hi,int mi,int si,int hf,int mf,int sf,
double tarifa){
    char** pacAux;
    double horas, *auxValores;
    int ind;
    ind = noesrepetido(dni,citaPaciente,nPac);
    horas = (hf - hi) + (mf - mi) / 60.0 + (sf - si)/3600.0;
    if(ind == -1){
        citaPaciente[nPac - 1] = new char*[2];
        pacAux = citaPaciente[nPac - 1];
        citaPaciente[nPac] = nullptr; //terminador
        pacAux[0] = dni;
        pacAux[1] = nomPac;
        citaCantidad[nPac - 1] = 1;
        citaTiempoYPago[nPac - 1] = new double[2];
        auxValores = citaTiempoYPago[nPac - 1];
        auxValores[0] = horas;
        auxValores[1] = horas * tarifa;
        nPac++;
    }
    else{
        citaCantidad[ind]++;
        auxValores = citaTiempoYPago[ind];
        auxValores[0] += horas;
        auxValores[1] += horas * tarifa;
    }   
}

void agregarMedico(char**& datos,double& tarif,double tarifa,
char* codMed,char* nomMed,int& nd){
    datos = new char*[2];
    datos[0] = codMed;
    datos[1] = nomMed;
    tarif = tarifa;
    nd++;
}


int noesrepetido(char* cod,char*** estructura,int nd){
    char** aux;
    for(int i = 0; i < nd - 1; i++){
        aux = estructura[i];
        if(!strcmp(aux[0],cod))
            return i;
    }
    return -1;
}
int leerCadena(ifstream& arch,char*& str){
    char buff[200];
    arch.getline(buff,200,',');
    if(arch.eof()) return 0; //llego al final del arch
    str = new char[strlen(buff) + 1];
    strcpy(str,buff);
    return 1;
}
void pruebaDeCargaDeCitas(const char* nomArch,char*** medicoDatos,
double* medicoTarifaHora,char**** citaPaciente,int** citaCantidad,double*** citaTiempoYPago){
    ofstream arch(nomArch, ios::out);
    if(!arch){
        cerr << "ERROR No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    char **auxMed, ***auxCitas, **auxPac;
    int *auxCant;
    double **auxTiempo, *auxDetalle;
    for(int i = 0; medicoDatos[i] != nullptr; i++){
        auxMed = medicoDatos[i];
        arch << left << setw(15) << auxMed[0] << setw(45) << auxMed[1] << right 
        << fixed << setprecision(2) << setw(8) << medicoTarifaHora[i] << endl;
        auxCitas = citaPaciente[i];
        auxCant = citaCantidad[i];
        auxTiempo = citaTiempoYPago[i];
        for(int j = 0; auxCitas[j] != nullptr; j++){ //
            auxPac = auxCitas[j];
            auxDetalle = auxTiempo[j]; //detalle de tiempo de dicho paciente
            arch << left << setw(15) << auxPac[0] << setw(40) << auxPac[1] << right 
            << fixed << setprecision(2) << setw(10) << auxCant[j] << setw(10) << auxDetalle[0] << setw(10) 
            << auxDetalle[1] << endl; 
        } 
    }
}

void reporteDeCitasPorMedico(const char* nomArch,char*** medicoDatos,
double* medicoTarifaHora,char**** citaPaciente,int** citaCantidad,double*** citaTiempoYPago){
    ofstream arch(nomArch, ios::out);
    if(!arch){
        cerr << "ERROR No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    char **auxMed, ***auxCitas, **auxPac;
    int *auxCant;
    double **auxTiempo, *auxDetalle;
    arch << right << setw(60) << " " << left << setw(40) << "CLINICA PSICOLOGICA LP1" << endl;
    for(int i = 0; i < MAXLINEA; i++) arch << '=';
    arch << endl;
    arch << left << setw(40) << "RELACION DE CITAS POR MEDICO" << endl;
    for(int i = 0; i < MAXLINEA; i++) arch << '=';
    arch << endl;
    for(int i = 0; medicoDatos[i] != nullptr; i++){
        auxMed = medicoDatos[i];
        arch << setw(15) << "CODIGO" << setw(45) << "Nombre" << 
        "TARIFA POR HORA DE CONSULTA" << right << fixed << setprecision(2) 
        << setw(8) << medicoTarifaHora[i] << endl << left << setw(15) << auxMed[0] 
        << setw(45) << auxMed[1] << endl;
        for(int i = 0; i < MAXLINEA; i++) arch << '-';
        arch << endl;
        arch << left << setw(40) << "RELACION DE PACIENTES ATENDIDOS" << endl;
        for(int i = 0; i < MAXLINEA; i++) arch << '-';
        arch << endl;
        arch << right << setw(10) << " " << left << setw(15) << "DNI" << setw(42) 
        << "Nombre" << setw(30) << "Cantidad de citas" << setw(30) << "Tiempo total(hrs)" 
        << setw(20) << "Pago total" << endl;
        for(int i = 0; i < MAXLINEA; i++) arch << '-';
        arch << endl;
        auxCitas = citaPaciente[i];
        auxCant = citaCantidad[i];
        auxTiempo = citaTiempoYPago[i];
        for(int j = 0; auxCitas[j] != nullptr; j++){ //
            auxPac = auxCitas[j];
            auxDetalle = auxTiempo[j]; //detalle de tiempo de dicho paciente
            arch << right << setw(5) << j + 1 << setw(5) << " " << left << setw(15)
            << auxPac[0] << setw(40) << auxPac[1] << right << fixed << setprecision(2) 
            << setw(10) << auxCant[j] << setw(30) << auxDetalle[0] << setw(30) 
            << auxDetalle[1] << endl; 
        }
        for(int i = 0; i < MAXLINEA; i++) arch << '-';
        arch << endl << left;
    } 
}