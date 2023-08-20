/* 
 * File:   main.cpp
 * Autora: Acosta Muñoz, Andrea Celeste
 * Codigo: 20202085
 * Created on 22 de marzo de 2023, 11:25 AM
 */

#include <iostream>
#include <iomanip>
#include <valarray>

using namespace std;

int main(int argc, char** argv) {
    int dato, mm, aa, dd, tipo, codigo, cant;
    char nombre[100], car, unidad[10]; 
    while(1){
        cin >> dato; 
        if(cin.eof()) break; 
        //caso en el que sea RUC 
        if(dato > 9999){
            cin >> nombre; 
            cout << dato<<" "<<nombre<<endl; 
        }else{
            dd = dato; 
            cin >> car >> mm >> car >> aa >> tipo >> codigo >> nombre >> cant; 
            if(cin.fail()){
                cin.clear(); 
                cant = 1; 
            }
            cin >> unidad; 
        }
    }
    
    return 0;
}

