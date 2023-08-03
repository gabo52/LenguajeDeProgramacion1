/*
 * Autor:   Gabriel Omar Durán Ruiz 
 * Código:  20203371
 */


#include <iomanip>
#include <iostream>
#include <fstream>

#include "funcionesAuxiliares.h"
#define nombArchInfracConduct "Infracciones-Conductores.txt"
#define nombArchInfrac "Infracciones.txt"
#define nombArchConducBin "Conductores.bin"
#define nombArchFaltasBin "FaltasCometidas.bin"
#define nombArchInfracBin "ListadoDeInfracciones.bin"
#define MAXCANTNOMBRE 60
using namespace std;


ofstream abrirArchiE(const char*nombre,char modo){
    ofstream arch;
    if(modo=='T') arch.open(nombre,ios::out);
    else arch.open(nombre,ios::out|ios::binary);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

ifstream abrirArchiL(const char*nombre,char modo){
    ifstream arch;
    if(modo=='T') arch.open(nombre,ios::in);
    else arch.open(nombre,ios::in|ios::binary);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}


fstream abrirArchiA(const char*nombre,char modo){
    fstream arch;
    if(modo=='T') arch.open(nombre,ios::out|ios::in);
    else arch.open(nombre,ios::out|ios::binary|ios::in);
    if(!arch){
        cout<<"ERROR, no se pudo abrir el archivo "<<nombre;
        exit(1);
    }
    return arch;
}

void leeFalta(char *placa,int &fecha,char *codigo,ifstream &arch){
    int dd,mm,aa;
    char c;
    arch>>placa>>dd>>c>>mm>>c>>aa>>codigo;
    fecha=dd+mm*100+aa*10000;
}

void cargarGravedadCodigo(char *cod,ofstream &arch){
    char leve[15]="LEVE",grave[15]="GRAVE",muyGrave[15]="MUY GRAVE";
    int i,codigoMul;
    
    switch(cod[0]){
        case 'L':
            arch.write(reinterpret_cast<const char*>(leve),sizeof(char)*15);
            break;
        case 'G':
            arch.write(reinterpret_cast<const char*>(grave),sizeof(char)*15);
            break;
        case 'M':
            arch.write(reinterpret_cast<const char*>(muyGrave),sizeof(char)*15);
            break;
    }
    for(i=1;cod[i];i++){
        cod[i-1]=cod[i];
    }
    cod[i-1]=0;
    codigoMul=atoi(cod);
    arch.write(reinterpret_cast<const char*>(&codigoMul),sizeof(int));
    
}

void cargaFaltaCometidaBin(ofstream &arch,char *placa,int licencia,
        int fecha,char *cod,double monto,int &flag){
    arch.write(reinterpret_cast<const char*>(placa),sizeof(char)*10);
    arch.write(reinterpret_cast<const char*>(&licencia),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&fecha),sizeof(int));
    cargarGravedadCodigo(cod,arch);
    arch.write(reinterpret_cast<const char*>(&monto),sizeof(double));
    flag=1;
}

void cargaRegConductorBin(int licencia,char *nombre,int cantFaltL,int cantFaltG,
        int cantFaltM,double pagarL,double pagarG,double pagarMG,double totPagar,
        ofstream &arch){
    arch.write(reinterpret_cast<const char*>(&licencia),sizeof(int));
    arch.write(reinterpret_cast<const char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
    arch.write(reinterpret_cast<const char*>(&cantFaltL),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantFaltG),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantFaltM),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&pagarL),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&pagarG),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&pagarMG),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&totPagar),sizeof(double));
}
void crearCargarConductorFaltasCometidasBin(){
    char nombre[MAXCANTNOMBRE],placa[10],codigo[10];
    int licencia,fecha,dato,flag=0,i=0;
    ofstream archConductorBin=abrirArchiE(nombArchConducBin,'B');
    ofstream archFaltasBin=abrirArchiE(nombArchFaltasBin,'B');
    ifstream archInfraccion=abrirArchiL(nombArchInfracConduct,'T');
    archInfraccion.seekg(0,ios::beg);
    while(1){
        archInfraccion>>dato;
        if(archInfraccion.eof()){
            cargaRegConductorBin(licencia,nombre,0,0,0,0,0,0,0,archConductorBin);
            break;
        }
        if(archInfraccion.fail()){
            archInfraccion.clear();
            //LeeInfraccion
            leeFalta(placa,fecha,codigo,archInfraccion);
            cargaFaltaCometidaBin(archFaltasBin,placa,licencia,fecha,codigo,0,flag);
        }else{
            if(flag)cargaRegConductorBin(licencia,nombre,0,0,0,0,0,0,0,archConductorBin);
            //Lee licencia y nombre
            licencia=dato;
            archInfraccion>>nombre;
        }
    }
    archConductorBin.close();
    archFaltasBin.close();
    archInfraccion.close();
}

void leerRegConductoresBin(ifstream &arch,int &licencia,int &nFL,int &nFG,
        int &nFMG,double &montFL,double &montFG,double &montFMG,double &totPag,
        char *nombre){
    arch.read(reinterpret_cast<char*>(&licencia),sizeof(int));
    arch.read(reinterpret_cast<char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
    arch.read(reinterpret_cast<char*>(&nFL),sizeof(int));
    arch.read(reinterpret_cast<char*>(&nFG),sizeof(int));
    arch.read(reinterpret_cast<char*>(&nFMG),sizeof(int));
    arch.read(reinterpret_cast<char*>(&montFL),sizeof(double));
    arch.read(reinterpret_cast<char*>(&montFG),sizeof(double));
    arch.read(reinterpret_cast<char*>(&montFMG),sizeof(double));
    arch.read(reinterpret_cast<char*>(&totPag),sizeof(double));
}
     
void verificarConductoresBin(){
    ifstream arch=abrirArchiL(nombArchConducBin,'B');
    ofstream archRep=abrirArchiE("ReporteConductores.txt",'T');
    char nombre[MAXCANTNOMBRE];
    int licencia,nFG,nFL,nFMG;
    double montFL,montFG,montFMG,totPag;
    arch.seekg(0,ios::beg);
    while(1){
        leerRegConductoresBin(arch,licencia,nFL,nFG,nFMG,montFL,montFG,
                montFMG,totPag,nombre);
        if(arch.eof())break;
        archRep<<setw(15)<<left<<licencia<<setw(50)<<left<<nombre;
        archRep<<setw(8)<<left<<nFL<<setw(8)<<left<<nFG<<setw(8)<<left<<nFMG;
        archRep<<setw(10)<<left<<setprecision(2)<<fixed<<montFL;
        archRep<<setw(10)<<left<<setprecision(2)<<fixed<<montFG;
        archRep<<setw(10)<<left<<setprecision(2)<<fixed<<montFMG;
        archRep<<setw(10)<<left<<setprecision(2)<<fixed<<totPag<<endl;
    }
    arch.close();
    archRep.close();
}


void imprimeFecha(int fecha,ofstream &archRep){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    archRep<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm
            <<"/"<<setw(4)<<right<<aa<<setfill(' ');
}

void leerFaltasBin(char  *placa,int &licencia,int &fecha,char *gravedad,int &codigo,
        double &monto,ifstream &arch){
    arch.read(reinterpret_cast<char*>(placa),sizeof(char)*10);
    arch.read(reinterpret_cast<char*>(&licencia),sizeof(int));
    arch.read(reinterpret_cast<char*>(&fecha),sizeof(int));
    arch.read(reinterpret_cast<char*>(gravedad),sizeof(char)*15);
    arch.read(reinterpret_cast<char*>(&codigo),sizeof(int));
    arch.read(reinterpret_cast<char*>(&monto),sizeof(double));
}

void leerActuFaltasBin(char  *placa,int &licencia,int &fecha,char *gravedad,int &codigo,
        double &monto,fstream &arch){
    arch.read(reinterpret_cast<char*>(placa),sizeof(char)*10);
    arch.read(reinterpret_cast<char*>(&licencia),sizeof(int));
    arch.read(reinterpret_cast<char*>(&fecha),sizeof(int));
    arch.read(reinterpret_cast<char*>(gravedad),sizeof(char)*15);
    arch.read(reinterpret_cast<char*>(&codigo),sizeof(int));
    arch.read(reinterpret_cast<char*>(&monto),sizeof(double));
}

void verificarFaltasCometidasBin(){
    ifstream arch=abrirArchiL(nombArchFaltasBin,'B');
    ofstream archRep=abrirArchiE("ReporteFaltas.txt",'T');
    int codigo,licencia,fecha;
    char gravedad[15],placa[10];
    double monto;
    while(1){
        leerFaltasBin(placa,licencia,fecha,gravedad,codigo,monto,arch);
        if(arch.eof())break;
        archRep<<setw(10)<<left<<placa<<setw(10)<<left<<licencia<<setw(4)<<" ";
        imprimeFecha(fecha,archRep);
        archRep<<setw(4)<<" "<<setw(15)<<left<<gravedad<<setw(10)<<left<<codigo;
        archRep<<setw(10)<<right<<setprecision(2)<<fixed<<monto<<endl;
    }
    arch.close();
    archRep.close();
}
void crearCargarListadoInfracciones(){
    ofstream archBin=abrirArchiE(nombArchInfracBin,'B');
    ifstream arch=abrirArchiL(nombArchInfrac,'T');
    int codigo;
    char descripcion[300],gravedad[15];
    double multa;

    while(1){
        arch>>codigo>>descripcion>>gravedad>>multa;
        if(arch.eof())break;
        archBin.write(reinterpret_cast<const char*>(&codigo),sizeof(int));
        archBin.write(reinterpret_cast<const char*>(descripcion),sizeof(char)*300);
        archBin.write(reinterpret_cast<const char*>(gravedad),sizeof(char)*15);
        archBin.write(reinterpret_cast<const char*>(&multa),sizeof(multa));
    }
}

void leerRegListadoBin(ifstream &arch,int &codigo,char *descripcion,
        char *gravedad,double &multa){
    arch.read(reinterpret_cast<char*>(&codigo),sizeof(int));
    arch.read(reinterpret_cast<char*>(descripcion),sizeof(char)*300);
    arch.read(reinterpret_cast<char*>(gravedad),sizeof(char)*15);
    arch.read(reinterpret_cast<char*>(&multa),sizeof(multa));
}

void verificarListadoInfracciones(){
    ifstream archBin=abrirArchiL(nombArchInfracBin,'B');
    ofstream archRep=abrirArchiE("ReporteListadoInfracciones.txt",'T');
    int codigo;
    char descripcion[300],gravedad[15];
    double multa;

    while(1){
        leerRegListadoBin(archBin,codigo,descripcion,gravedad,multa);
        if(archBin.eof())break;
        archRep<<setw(10)<<left<<codigo<<setw(200)<<left<<descripcion<<
                setw(20)<<left<<gravedad<<setw(10)<<left<<setprecision(2)<<
                fixed<<multa<<endl;
    }
}

void leerFaltasBinActu(char  *placa,int &licencia,int &fecha,char *gravedad,int &codigo,
        double &monto,fstream &arch){
    arch.read(reinterpret_cast<char*>(placa),sizeof(char)*10);
    arch.read(reinterpret_cast<char*>(&licencia),sizeof(int));
    arch.read(reinterpret_cast<char*>(&fecha),sizeof(int));
    arch.read(reinterpret_cast<char*>(gravedad),sizeof(char)*15);
    arch.read(reinterpret_cast<char*>(&codigo),sizeof(int));
    arch.read(reinterpret_cast<char*>(&monto),sizeof(double));
}

int hallarLicencia(int licencia,fstream &arch){
    char nombre[MAXCANTNOMBRE];
    int dato,nFG,nFL,nFMG,i=0;
    double montFL,montFG,montFMG,totPag;
    arch.seekg(0,ios::beg);
    while(1){
        arch.read(reinterpret_cast<char*>(&dato),sizeof(int));
        if(arch.eof())break;
        arch.read(reinterpret_cast<char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
        arch.read(reinterpret_cast<char*>(&nFL),sizeof(int));
        arch.read(reinterpret_cast<char*>(&nFG),sizeof(int));
        arch.read(reinterpret_cast<char*>(&nFMG),sizeof(int));
        arch.read(reinterpret_cast<char*>(&montFL),sizeof(double));
        arch.read(reinterpret_cast<char*>(&montFG),sizeof(double));
        arch.read(reinterpret_cast<char*>(&montFMG),sizeof(double));
        arch.read(reinterpret_cast<char*>(&totPag),sizeof(double));
        if(dato==licencia){
            arch.seekg(0,ios::beg);
            return i;
        }
        i++;
    }
    cout<<"ERROR, no se encontro la licencia "<<licencia; 
    exit(1);
}

void  hallarPrecioMulta(int codigo,ifstream &arch,double &costo,int &nivel){
    arch.seekg(0,ios::beg);
    int dato;
    char descripcion[300],gravedad[15];
    double multa;
    while(1){
        leerRegListadoBin(arch,dato,descripcion,gravedad,multa);
        if(arch.eof())break;
        if(codigo==dato){
            costo=multa;
            switch(gravedad[0]){
                case 'L':
                    nivel=1;
                    break;
                case 'G':
                    nivel=2;
                    break;
                case 'M':
                    nivel=3;
                    break;
            }
            arch.seekg(0,ios::beg);
            return;
        }
    }
    cout<<"ERROR, no se encontro el codigo de multa"<<codigo; 
    exit(1);
}

void cargaActualizaRegConductorBin(int licencia,char *nombre,int cantFaltL,int cantFaltG,
        int cantFaltM,double pagarL,double pagarG,double pagarMG,double totPagar,
        fstream &arch,int nivel,double multa){
    if(nivel==1){
        pagarL+=multa;
        cantFaltL++;
    }else if(nivel ==2){
        cantFaltG++;
        pagarG+=multa;
    }else{
        cantFaltM++;
        pagarMG+=multa;
    }
    totPagar+=multa;
    arch.write(reinterpret_cast<const char*>(&licencia),sizeof(int));
    arch.write(reinterpret_cast<const char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
    arch.write(reinterpret_cast<const char*>(&cantFaltL),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantFaltG),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&cantFaltM),sizeof(int));
    arch.write(reinterpret_cast<const char*>(&pagarL),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&pagarG),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&pagarMG),sizeof(double));
    arch.write(reinterpret_cast<const char*>(&totPagar),sizeof(double));
    arch.flush();
}
void actualizaConductores(int nivel,double multa,fstream &arch,int licencia){
    arch.seekg(0,ios::beg);
    int size=4*sizeof(int)+4*sizeof(double)+sizeof(char)*MAXCANTNOMBRE;
    int dato,nFG,nFL,nFMG,i=0;
    double montFL,montFG,montFMG,totPag;
    char nombre[MAXCANTNOMBRE];
    while(1){
        arch.read(reinterpret_cast<char*>(&dato),sizeof(int));
        if(arch.eof())break;
        arch.read(reinterpret_cast<char*>(nombre),sizeof(char)*MAXCANTNOMBRE);
        arch.read(reinterpret_cast<char*>(&nFL),sizeof(int));
        arch.read(reinterpret_cast<char*>(&nFG),sizeof(int));
        arch.read(reinterpret_cast<char*>(&nFMG),sizeof(int));
        arch.read(reinterpret_cast<char*>(&montFL),sizeof(double));
        arch.read(reinterpret_cast<char*>(&montFG),sizeof(double));
        arch.read(reinterpret_cast<char*>(&montFMG),sizeof(double));
        arch.read(reinterpret_cast<char*>(&totPag),sizeof(double));
        if(dato==licencia){
            arch.seekg(i*size,ios::beg);
            cargaActualizaRegConductorBin(licencia,nombre,nFG,nFL,nFMG,montFL,
                    montFG,montFMG,totPag,arch,nivel,multa);
            arch.seekg(0,ios::beg);
            break;
        }
        i++;
    }
}
void completarConductoresFaltasCometidasBin(){
    ifstream listado=abrirArchiL(nombArchInfracBin,'B');
    fstream conductores=abrirArchiA(nombArchConducBin,'B');
    fstream faltas=abrirArchiA(nombArchFaltasBin,'B');
    int codigo,licencia,fecha,pos1,pos2,nivel,i=0,size;
    char gravedad[15],placa[10];
    double monto,multa;
    size=3*sizeof(int)+sizeof(double)+25*sizeof(char);
    while(1){
        leerActuFaltasBin(placa,licencia,fecha,gravedad,codigo,monto,faltas);
        if(faltas.eof())break;
        hallarPrecioMulta(codigo,listado,multa,nivel);
        actualizaConductores(nivel,multa,conductores,licencia);
        faltas.seekg(i*size,ios::beg);
        faltas.seekg(size-sizeof(double),ios::cur);
        faltas.write(reinterpret_cast<const char*>(&multa),sizeof(double));
        faltas.flush();
        i++;
    }
}
        
void leerFecha(int &fecha){
    int dd,mm,aa;
    char c;
    cin>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}
void actualizarConductoresFaltasCometidasBin(){
    int fecha;
    char nombre[MAXCANTNOMBRE];
    int codigo,licencia,fecha;
    char gravedad[15],placa[10];
    double monto;
    leerFecha(fecha);
    fstream faltasBin=abrirArchiL(nombArchFaltasBin,'B');
    while(1){
        leerFaltasBinActu(placa,licencia,fecha,gravedad,codigo,monto,arch);
    }
}