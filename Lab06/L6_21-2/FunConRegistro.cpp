/* 
 * File:   FunConRegistro.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 05:46 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

char *leerCadena(ifstream &arch,char c){
    char *aux,buff[100];
    arch.getline(buff,100,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void *leepedido(ifstream &arch){
    int carne, *auxcarne; 
    char *codlibro, *nombre, *auxtipo, tipo, c, auxnombre[200];
    void **aux; 
    
    arch >> carne;
    if(arch.eof()) return nullptr; 
    arch >> tipo >> c;
    codlibro = leerCadena(arch,','); 
    arch.getline(auxnombre,200); 
    
    aux = new void*[4]; 
    nombre = new char[strlen(auxnombre)+1];
    strcpy(nombre,auxnombre);
    auxcarne = new int;
    auxtipo = new char; 
    
    *auxcarne = carne;
    *auxtipo = tipo; 
    
    aux[0] = auxcarne;
    aux[1] = auxtipo; 
    aux[2] = codlibro;
    aux[3] = nombre; 
    
    return aux; 
}
        
int prioridadpedido(void *dato){
    void **dt = (void**)dato; 
    char *tipo;
    
    tipo = (char*)(dt[1]); 
    
    if(*tipo == 'A') return 3; 
    if(*tipo == 'E') return 2; 
    if(*tipo == 'D') return 1; 
}

/*void imprimir(void *cola,void (*imprime)(void *dato,ofstream &arch)){
    void *dato, **rec;
    void **aux = (void **)cola;

    ofstream arch("Reporte.txt", ios::out); 
    imprimeLinea(arch,150,'='); 
    
    rec = (void **)(aux[0]);
    while(rec){
        dato = rec[0];
        imprime(dato,arch);
        rec = (void **)(rec[1]); 
    }
    imprimeLinea(arch,150,'='); 
}*/

void imprimirped(void *cola, const char *nomarch){
    int i = 0, *carne; 
    char *tipo, *nombre, *codigo; 
    void **rec, *dato, **dt;
    void **aux = (void **)cola;
    
    
    ofstream arch(nomarch, ios::out); 
    
    rec = (void **)(aux[0]);
    
    while(rec){
        dato = rec[0]; 
        dt = (void **)dato;
        carne = (int*)dt[0];
        tipo = (char*)dt[1];
        codigo = (char*)dt[2]; 
        nombre = (char*)dt[3];
        
        arch << *tipo << " " << *carne << " " << nombre << " " << codigo << endl; 
        rec = (void **)(rec[1]); 
    }
    
    /*while(i<3){
        rec = (void **)(aux[i+1]); 
        dato = rec[0];
        num = (int*) dato; 
        arch << "Prioridad " << i + 1 << ": " << *num << endl;  
        i++; 
    }*/
}
        