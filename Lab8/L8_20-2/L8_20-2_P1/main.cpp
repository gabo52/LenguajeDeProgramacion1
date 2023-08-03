/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:35 AM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "ListaDePacientes.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ListaDePacientes lista;
    Ambulatorio amb,arrAmb[20];
    Urgencia urg,arrUrg[20];
    Emergencia emer,arrEmer[20];
    char cadena[200];
    strcpy(cadena,"Juan Perez 1");
    amb.SetDni(12345671);
    amb.SetNombre(cadena);
    
    strcpy(cadena,"Juan Perez 2");
    urg.SetDni(12345672);
    urg.SetNombre(cadena);
    
    strcpy(cadena,"Juan Perez 3");
    emer.SetDni(12345673);
    emer.SetNombre(cadena);
    
    lista+amb;
    lista+urg;
    lista+emer;
    
    lista.getLAmb(arrAmb);
    lista.getLEmer(arrEmer);
    lista.getLUrg(arrUrg);
    
    arrAmb[0].GetNombre(cadena);
    cout<<"Ambulatorio: "<<arrAmb[0].GetDni()<<setw(20)<<cadena<<endl;
    arrUrg[0].GetNombre(cadena);
    cout<<"Urgencia: "<<arrUrg[0].GetDni()<<setw(20)<<cadena<<endl;
    arrEmer[0].GetNombre(cadena);
    cout<<"Emergencia: "<<arrEmer[0].GetDni()<<setw(20)<<cadena<<endl;

    return 0;
}

