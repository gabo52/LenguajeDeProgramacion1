/* 
 * File:   Registro.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371 
 * Created on 8 de noviembre de 2022, 06:53 PM
 */

#include <cstring>
#define MAXCANTLINEA 60
#include "Registro.h"
#include "FuncionesLecturaEscrituraa.h"



void hallaGravedad(int cod,char *gravedad,double &multa,double &desc,
    int &puntos,int &meses);



Registro::Registro() {
    lgrave=nullptr;
    lleve=nullptr;
    lmgrave=nullptr;
}

Registro::~Registro() {
    if(lgrave)delete lgrave;
    if(lleve)delete lleve;
    if(lmgrave)delete lmgrave;
}


void Registro::agregaConductor(int cod){
    ifstream arch;
    AbrirArchivo("Conductores.csv",arch);
    int lic;
    char nomb[50],c;
    while(1){
        arch>>lic>>c;
        if(arch.eof())break;
        arch.getline(nomb,50,'\n');
        if(lic==cod){
            SetLicencia(lic);
            SetNombre(nomb);
            return;
        }
    }
    cout<<"Error, no se pudo encontrar al chofer "<<cod;
    exit(1);
}


void hallaGravedad(int cod,char *gravedad,double &multa,double &desc,
        int &puntos,int &meses){
    ifstream arch;
    AbrirArchivo("Infracciones.csv",arch);
    int codigo;
    char c,descripcion[300];
    while(1){
        arch>>codigo>>c;
        if(arch.eof())break;
        if(codigo==cod){
            arch.getline(descripcion,300,',');
            arch.getline(gravedad,20,',');
            arch>>multa>>c;
            if(strcmp(gravedad,"Leve")==0){
                arch>>desc;
            }else if(strcmp(gravedad,"Grave")==0){
                arch>>desc>>c>>puntos;
            }else{
                arch>>puntos>>c>>meses;
            }
            return;
        }else arch.getline(descripcion,300,'\n');
    }
    cout<<"Error, no se encontro la falta "<<cod;
    exit(2);
}


void Registro::agregarFalta(int cod,int fecha,char *placa){
    char gravedad[20]="Hola";
    int puntos,meses;
    double multa,desc;
    hallaGravedad(cod,gravedad,multa,desc,puntos,meses);
    if(cod/100==2){
        //leve
        agregaFaltaLeve(cod,desc,fecha,gravedad,multa,placa);
    }else if(cod/100==1){
        agregaFaltaGrave(cod,desc,fecha,gravedad,multa,placa,puntos);
    }else{
        agregaFaltaMuyGrave(cod,meses,fecha,gravedad,multa,placa,puntos);
    }
}

void Registro::agregaFaltaLeve(int cod,double desc,int fecha,char *gravedad,
        double multa,char *placa){
    Leve aux;
    aux.SetCodigo(cod);
    aux.SetFecha(fecha);
    aux.SetGravedad(gravedad);
    aux.SetPlaca(placa);
    aux.SetDescuento(desc);
    aux.SetMulta(multa);
    if(lleve){
        return;
        Leve *pointer;
        int n=numFaltaLeve();
        pointer = new Leve [n+2];
        
        for(int i=0;i<n;i++)pointer[i]=lleve[i];
        delete lleve;
        pointer[n]=aux;
        lleve=pointer;
    }else{
        lleve = new Leve [2];
        lleve[0]=aux;
    }
}

void Registro::agregaFaltaGrave(int cod,double desc,int fecha,char *gravedad,
        double multa,char *placa,int puntos){
    Grave aux;
    aux.SetCodigo(cod);
    aux.SetFecha(fecha);
    aux.SetGravedad(gravedad);
    aux.SetPlaca(placa);
    
    aux.SetPuntos(puntos);
    aux.SetDescuento(desc);
    aux.SetMulta(multa);
    if(lgrave){
        Grave *pointer;
        int n=numFaltaGrave();
        pointer = new Grave [n+2];
        
        for(int i=0;i<n;i++){
            pointer[i]=lgrave[i];
        }
        delete lgrave;
        pointer[n]=aux;
        lgrave=pointer;
    }else{
        lgrave = new Grave [2];
        lgrave[0]=aux;
    }
}

void Registro::agregaFaltaMuyGrave(int cod,int meses,int fecha,char *gravedad,
        double multa,char *placa,int puntos){
    MuyGrave aux;
    aux.SetCodigo(cod);
    aux.SetFecha(fecha);
    aux.SetGravedad(gravedad);
    aux.SetPlaca(placa);
    
    aux.SetPuntos(puntos);
    aux.SetMeses(meses);
    aux.SetMulta(multa);
    if(lmgrave){
        MuyGrave *pointer;
        int n=numFaltaMGrave();
        pointer = new MuyGrave [n+2];
        
        for(int i=0;i<n;i++)pointer[i]=lmgrave[i];
        delete lmgrave;
        pointer[n]=aux;
        lmgrave=pointer;
    }else{
        lmgrave = new MuyGrave [2];
        lmgrave[0]=aux;
    }
}

int Registro::numFaltaLeve(){
    if(lleve==nullptr)return 0;
    int i;
    for(i=0;lleve[i].GetCodigo();i++);
    return i;
}

int Registro::numFaltaGrave(){
    if(lgrave==nullptr)return 0;
    int i;
    for(i=0;lgrave[i].GetCodigo();i++);
    return i;
}

int Registro::numFaltaMGrave(){
    if(lmgrave==nullptr)return 0;
    int i;
    for(i=0;lmgrave[i].GetCodigo();i++);
    return i;
}



int Registro::imprime(ofstream &arch){
    char cadena[50];
    GetNombre(cadena);
    
    arch<<setw(15)<<"Conductor: "<<setw(50)<<left<<cadena<<endl<<setw(15)
            <<"Licencia No.: "<<GetLicencia()<<endl;
    if(lleve)imprimeFaltasLeves(arch);
    if(lgrave)imprimeFaltasGraves(arch);
    if(lmgrave)imprimeFaltasMuyGraves(arch);
}

void Registro::imprimeFaltasLeves(ofstream &arch){
    int n=numFaltaLeve();
    for(int i=0;i<n;i++){
        lleve[i].imprime(arch);
    }
}

void Registro::imprimeFaltasGraves(ofstream &arch){
    int n=numFaltaGrave();
    for(int i=0;i<n;i++){
        lgrave[i].imprime(arch);
    }
    
}
void Registro::imprimeFaltasMuyGraves(ofstream &arch){
    int n=numFaltaMGrave();
    for(int i=0;i<n;i++){
        lmgrave[i].imprime(arch);
    }       
}

void Registro::imprimeConsolidado(ofstream &arch){
    char cadena[50];
    arch.precision(2);
    arch<<fixed;
    GetNombre(cadena);
    arch<<setw(15)<<left<<"Conductor: "<<setw(50)<<left<<cadena<<endl;
    arch<<setw(15)<<"Licencia No.: "<<GetLicencia()<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'-');
    arch<<setw(20)<<left<<"Monto de multas:"<<setw(8)<<right<<hallaMontoMultas()<<endl;
    arch<<setw(20)<<left<<"PuntosPerdidos:"<<setw(8)<<right<<hallaPuntosPerdidos()<<endl;
    arch<<setw(20)<<left<<"Meses sancionados:"<<setw(8)<<right<<hallaMesesSancionados()<<endl<<endl;
}

double Registro::hallaMontoMultas(){
    int n;
    double suma=0;
    n=numFaltaLeve();
    for(int i=0;i<n;i++){
        suma+=lleve[i].GetMulta()*(1-lleve[i].GetDescuento());
    }
    
    n=numFaltaGrave();
    for(int i=0;i<n;i++){
        suma+=lgrave[i].GetMulta()*(1-lgrave[i].GetDescuento());
    }
    
    n=numFaltaMGrave();
    for(int i=0;i<n;i++){
        suma+=lmgrave[i].GetMulta();
    }
    return suma;
}

int Registro::hallaPuntosPerdidos(){
    int n;
    int suma=0;
    n=numFaltaGrave();
    for(int i=0;i<n;i++){
        suma+=lgrave[i].GetPuntos();
    }
    
    n=numFaltaMGrave();
    for(int i=0;i<n;i++){
        suma+=lmgrave[i].GetPuntos();
    }
    return suma;
}

int Registro::hallaMesesSancionados(){
    int n;
    int suma=0;
    n=numFaltaMGrave();
    for(int i=0;i<n;i++){
        suma+=lmgrave[i].GetMeses();
    }
    return suma;
}

