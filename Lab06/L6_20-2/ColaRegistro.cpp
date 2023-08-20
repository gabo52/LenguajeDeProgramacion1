/* 
 * File:   ColaRegistro.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 25 de mayo de 2023, 08:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

void *leeRegistro(ifstream &arch){
    int dni, *auxdni, codespecialidad, *auxespecialidad;
    char *auxnombre, *auxtipo, tipo, nombre[200], c;
    double porcTarifa = 100, porcUrgencia = 100, *auxporctarifa, *auxporcurgencia; 
    void **aux; 
    
    arch >> dni >> c;
    if(arch.eof()) return nullptr;
    arch.getline(nombre,200,',');
    arch >> tipo >> c >> codespecialidad >> c; 
    if(tipo == 'A') arch >> porcTarifa>> c; 
    if(tipo == 'U') arch >> porcTarifa >> c >> porcUrgencia >> c; 
    
    aux = new void *[6];
    auxdni = new int;
    auxtipo = new char;
    auxespecialidad = new int; 
    auxporctarifa = new double; 
    auxporcurgencia = new double; 
    auxnombre = new char[strlen(nombre)+1]; 
    
    *auxdni = dni;
    *auxtipo = tipo;
    *auxespecialidad = codespecialidad; 
    *auxporctarifa = porcTarifa; 
    *auxporcurgencia = porcUrgencia; 
    strcpy(auxnombre,nombre); 
    
    aux[0] = auxdni;
    aux[1] = auxnombre;
    aux[2] = auxtipo; 
    aux[3] = auxespecialidad;
    aux[4] = auxporctarifa;
    aux[5] = auxporcurgencia; 
    
    return aux;
}

int hallarprioridadreg(void *dato){
    void **info = (void **)dato;
    char *prioridad;
    int prioridadfinal; 
    
    prioridad = (char*)info[2];
    
    if (*prioridad == 'U') prioridadfinal = 2; 
    if (*prioridad == 'A') prioridadfinal = 1; 
    if (*prioridad == 'E') prioridadfinal = 3; 
    
    return prioridadfinal;
}

void imprimeReg(void *dt,ofstream &arch){
    ifstream archTarifas("Tarifas.txt", ios::in);
    
    void **dato = (void **)dt;
    int *dni, *especialidad, espec;
    char *nombre, *tipo; 
    double *porctarifa, *porcurgencia, tarifa = 0, porc1, porc2, monto; 
    
    dni = (int*)dato[0];
    nombre = (char*)dato[1]; 
    tipo = (char*)dato[2];
    especialidad = (int*)dato[3]; 
    porctarifa = (double*)dato[4]; 
    porcurgencia = (double*)dato[5]; 
    
    arch.precision(2);
    arch << fixed; 
    
    arch << left << setw(10) << *dni << " " << setw(37) << nombre << right << setw(10) << "     " << *especialidad << "     ";
    
    while(1){
        archTarifas >> espec;
        if(archTarifas.eof()) break; 
        archTarifas >> tarifa; 
        if(espec == *especialidad) break; 
    }
    
    porc1 = *porctarifa; 
    porc2 = *porcurgencia; 
    monto = (double)(porc1/100) * (double)(porc2/100) * tarifa; 
    arch << setw(7) << monto << "   "; 
    
    if(*tipo == 'E') arch << "Emergencia";
    if(*tipo == 'U') arch << "Urgencia";
    if(*tipo == 'A') arch << "Ambulatorio";
    arch << endl; 
            
}