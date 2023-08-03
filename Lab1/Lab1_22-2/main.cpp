/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 29 de marzo de 2023, 10:20 AM
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

int main(int argc, char** argv) {
    int ddv, mmv, aav, dni, cantMed, dd, mm, aa, i, cantPac = 0;
    char esp1[50], esp2[50], nomDoc[100], nomPac[100], c, codDoc[10], codMed[10], descripcion[100];
    char nomesp[50], espmin[50];
    
    cin >> esp1 >> esp2 >> ddv >> c >> mmv >> c >> aav;
    
    while(1){
        cin >> dni; 
        if(cin.eof()){
            break; 
        }
        
        if(cin.fail()){
            cantPac = 0; 
            cin.clear(); 
            cin >> codDoc >> nomDoc; 
            cortaespecialidad(nomDoc, nomesp, espmin); 
            cout << left << setw(40) << nomDoc << " [" << codDoc << "]" << setw(10) << " " << "Especialidad:    " << espmin << endl; 
            cout << right; 
        }else{
            cin >> nomPac >> cantMed;
            cout << setfill('0') << setw(2) << cantPac + 1 << ") " << setfill(' ') 
                 << setw(30) << nomPac << setw(2) << " " << cantMed << endl; 
            for(i=0;i<cantMed;i++){
                cin >> codMed >> descripcion >> dd >> c >> mm >> c >> aa; 
                /*cout << setw(3) << " " << codMed << setw(3) << " " << setw(30) 
                     << descripcion << setw(3) << " " << setfill('0') << setw(2) 
                     << dd << "/" << setw(2) << mm << '/' << aa;*/
                //if(aa*1000000 + mm * 10000 + dd)
            }
            cantPac++; 
        }
        
    }
    
    return 0;
}

