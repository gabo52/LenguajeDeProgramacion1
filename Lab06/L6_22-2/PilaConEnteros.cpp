/* 
 * File:   PilaConEnteros.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 30 de mayo de 2023, 08:18 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void *leenumero(ifstream &arch){
    int aux, *num; 
    
    arch >> aux;
    if(arch.eof()) return nullptr; 
    num = new int;    
    *num = aux;
    
    return num; 
}

int cmpnumero(const void *a, const void *b){
    int *num1, *num2; 
    void **aux1 = (void **)a; 
    void **aux2 = (void **)b; 
    
    num1 = (int *)(*aux1);
    num2 = (int *)(*aux2);
    
    return *num2 - *num1; 
}