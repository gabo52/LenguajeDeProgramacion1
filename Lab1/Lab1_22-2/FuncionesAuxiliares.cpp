/* 
 * File:   FuncionesAuxiliares.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 29 de marzo de 2023, 11:02 AM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

void cortaespecialidad(char *nomdoc, char *nomesp, char *espmin){
    int aux, i = 0, j = 0; 
    
    while(nomdoc[i] != '\0') i++; 
    while(nomdoc[i] != '_') i--; 
    aux = i;
    
    i++; 
    while(nomdoc[i] != '\0'){
        if(nomdoc[i] >= 'a' && nomdoc[i] <= 'z') 
            nomesp[j] = nomdoc[i] - ('a' - 'A') ;
        else 
            nomesp[j] = nomdoc[i]; 
        espmin[j] = nomdoc[i]; 
        i++;
        j++;
    }
    nomdoc[aux] = '\0'; 
    nomesp[aux] = '\0'; 
    espmin[j] = '\0'; 
}

