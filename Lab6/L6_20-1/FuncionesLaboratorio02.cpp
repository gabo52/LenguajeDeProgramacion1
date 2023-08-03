/* 
 * File:   FuncionesLaboratorio02.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 03:50 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

char *leerCadena(ifstream &arch,char c){
    char buff[100], *aux;
    arch.getline(buff,100,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void *leeregistro(ifstream &arch){
    int *auxdni, *horaLlegada, hh, mm, ss, dni;
    double *tiempoTransaccion;
    char *nombre, c;
    void **aux;
    
    auxdni = new int;
    horaLlegada = new int;
    tiempoTransaccion = new double;
    
    arch >> dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch,',');
    arch >> hh >> c >> mm >> c >> ss >> c >> *tiempoTransaccion;
    *horaLlegada = hh*3600 + mm*60 + ss;
    *auxdni = dni;
    
    aux  = new void *[4];
    aux[0] = auxdni;
    aux[1] = nombre;
    aux[2] = horaLlegada;
    aux[3] = tiempoTransaccion;
    return aux;
}

int hallaHoras(int &hh,int &ss,int &mm,int tiempo){
    hh = tiempo/3600;
    tiempo%=3600;
    mm = tiempo/60;
    ss = tiempo%60;
}

void imprimeregistro(void *dt, ofstream &arch){
    void **dato = (void **)dt;
    int *dni, *horaLleg, hh, ss, mm;
    double *temTrans;
    char *nombre;
    
    dni = (int *)dato[0];
    nombre = (char *)dato[1];
    horaLleg = (int *)dato[2];
    temTrans = (double *)dato[3];
    hallaHoras(hh,ss,mm,*horaLleg);
    
    arch.precision(2);
    arch<<fixed;
    arch << setw(10) << left << *dni << setw(50) << nombre << setw(10) << " " << setfill('0') 
         << setw(2) << right << hh << ":" << setw(2) << mm << ":" << setw(2) << ss << setw(12) 
         << setfill(' ') << *temTrans << endl;
}