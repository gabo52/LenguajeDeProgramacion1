/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabri
 *
 * Created on 17 de agosto de 2022, 10:18 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 * Miguel 19 20 11 Cesar 10 11 10 11 Rony 15 17 6 12 16 -1
 */


void imprimeResumen(char *nombre,int *notas,int cantNot){
    cout<<"Nombre del alumno: "<<nombre<<setw(10);
    cout<<setw(10)<<"Notas: ";
    double sumNot=0;
    for(int i=0;i<cantNot;i++){
        cout<<setw(2)<<notas[i];
        cout<<" ";
        sumNot+=notas[i];
    }
    cout<<endl;
    cout<<"El promedio es: "<<setprecision(2)<<fixed<<sumNot/cantNot<<endl;
}
int main(int argc, char** argv) {
    FILE *arch;
    
    char nombre[20];
    int flag=0,nota,notas[10],cantNot=0;
    cin >> nombre;
    while(1){
        cin >> nota;
        if(nota<0){
            imprimeResumen(nombre,notas,cantNot);
            break;
        }
        if(cin.fail()){
            //Importante usar el cin.clear
            imprimeResumen(nombre,notas,cantNot);
            cantNot=0;
            cin.clear();
            cin>>nombre;
        }
        notas[cantNot]=nota;
        cantNot++;
    }
    return 0;
}

