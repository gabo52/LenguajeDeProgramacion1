/* 
 * File:   FuncionesLaboratorio01.cpp
 * Author: Gabo
 * Codigo: 20203371
 * Created on 20 de octubre de 2022, 04:38 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
//77763722,Farfan/Salazar/Margot,09:32:27,2.69
//dni, nombre, hora llegada, tiempo transaccion,

char *leerCadena(ifstream &arch,char c){
    char buff[100],*aux;
    arch.getline(buff,100,c);
    aux = new char [strlen(buff)+1];
    strcpy(aux,buff);
    return aux;
}

void *leenumero(ifstream &arch){
    int dni;
    arch>>dni;
    if(arch.eof())return nullptr;
    int *DNIP, *horaLlegada,hora,min,seg;
    double *tiempoTransaccion;
    char *nombre,c;
    DNIP = new int;
    horaLlegada = new int;
    tiempoTransaccion = new double;
    *DNIP=dni;
    arch.get();
    nombre = leerCadena(arch,',');
    arch>>hora>>c>>min>>c>>seg>>c>>*tiempoTransaccion;
    *horaLlegada=hora*3600+min*60+seg;
    void **aux;
    aux  = new void *[4];
    aux[0]=DNIP;
    aux[1]=nombre;
    aux[2]=horaLlegada;
    aux[3]=tiempoTransaccion;
    return aux;
}

int hallaHoras(int &hor,int &seg,int &min,int tiempo){
    hor=tiempo/3600;
    tiempo%=3600;
    min=tiempo/60;
    seg=tiempo%60;
}

void imprimenumero(ofstream &arch,void *dat){
    void **dato=(void **)dat;
    int *DNI,*horaLleg,hor,seg,min;
    double *tiempoTransaccion;
    char *nombre;
    DNI=(int *)dato[0];
    nombre=(char *)dato[1];
    horaLleg=(int *)dato[2];
    tiempoTransaccion=(double *)dato[3];
    hallaHoras(hor,seg,min,*horaLleg);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(10)<<left<<*DNI<<setw(50)<<left<<nombre<<setw(10)<<" ";
    arch<<setfill('0')<<setw(2)<<right<<hor<<":"<<setw(2)<<right<<min<<":"<<
            setw(2)<<right<<min<<setw(12)<<right<<
            setfill(' ')<<*tiempoTransaccion<<endl;
}