/* 
 * File:   medped.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 17 de noviembre de 2022, 10:13 PM
 */

#include "medped.h"
#include "conreceta.h"
#include "sinreceta.h"
medped::medped() {
    ptrmedped=nullptr;
}



medped::~medped() {
    if(ptrmedped)delete &ptrmedped;
}


void medped::leer(ifstream &arch){
    int cant,cod;
    
}

void medped::asignar(int medicamento,char *nombMedicamento,int cant,double precio,
                int fecha,int codmed,int dni,char *nombPac){
    char esp[80];
    if((medicamento/10000)%2==0){
        //conreceta
        ptrmedped = new class conreceta;
    }else{
        //sinreceta
        ptrmedped = new class sinreceta;
    }
    ptrmedped->asignar(medicamento,nombMedicamento,cant,precio,fecha,codmed,esp,
            dni,nombPac);
}

int medped::activo(){
    return ptrmedped!=nullptr;
}

int medped::codigo(){
    if(ptrmedped)return ptrmedped->GetCodigo();
    return 0;
}

void medped::imprime(ofstream &arch){
    ptrmedped->imprime(arch);
}
