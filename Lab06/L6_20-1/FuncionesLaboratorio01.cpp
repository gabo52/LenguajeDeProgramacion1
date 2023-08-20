/* 
 * File:   FuncionesLaboratorio01.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 27 de mayo de 2023, 03:34 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void *leenumero(ifstream &arch){
    int num, *auxnum;
    
    arch >> num;
    if(arch.eof()) return nullptr;
    
    auxnum = new int; 
    *auxnum = num; 
    
    return auxnum;
}
        
void imprimenumero(void *dato, ofstream &arch){
    int *numero; 
    numero = (int*)dato; 
    
    arch << *numero << endl; 
}
