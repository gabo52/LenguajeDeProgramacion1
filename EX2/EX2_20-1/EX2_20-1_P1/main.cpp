/* 
 * File:   main.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 16 de noviembre de 2022, 11:07 PM
 */

#include <iostream>
#include <iomanip>
#include "ConferencePaper.h"
#include "JournalPaper.h"
#include "Paper.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Paper *lstPapers[100]{};
    int n=0;
    ifstream arch;
    arch.open("Papers.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Papers.csv";
        exit(1);
    }
    char tipo,c;
    while(1){
        arch>>tipo>>c;
        if(arch.eof())break;
        if(tipo=='C')lstPapers[n]= new class ConferencePaper;
        else lstPapers[n]= new class JournalPaper;
        lstPapers[n]->leerDatos(arch);
        n++;
    }
    ofstream archRep;
    archRep.open("Reporte.txt",ios::out);
    if(!archRep){
        cout<<"Error no se pudo abrir el archivo Reporte.txt";
        exit(1);
    }
    cout<<"Llegue";
    for(int i=0;i<n;i++)lstPapers[i]->citar(archRep);
    for(int i=0;i<n;i++)delete lstPapers[i];
    return 0;
}

