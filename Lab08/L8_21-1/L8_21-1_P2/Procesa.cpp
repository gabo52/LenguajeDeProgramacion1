/* 
 * File:   Procesa.cpp
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:55 PM
 */

#include "Procesa.h"
#include "FuncionesLecturaEscrituraa.h"

Procesa::Procesa() {
    cantidad=0;
}


Procesa::~Procesa() {
    
}

void Procesa::lee(){
    ifstream arch;
    AbrirArchivo("RegistroDeFaltas.csv",arch);
    int codConductor,codInfracc,fecha,pos;
    char placa[10],gravedad[20];
    while(1){
        leeRegistro(arch,codConductor,codInfracc,fecha,placa);
        if(arch.eof())break;
        pos=buscarConductor(codConductor);
        if(pos!=-1){
            lregistro[pos].agregarFalta(codInfracc,fecha,placa);
        }else{
            lregistro[cantidad].agregaConductor(codConductor);
            lregistro[cantidad].agregarFalta(codInfracc,fecha,placa);
            cantidad++;
            cout<<cantidad<<endl;
        }
    }
}

void Procesa::leeRegistro(ifstream &arch,int &codConductor,int &codInfracc,int &fecha,
        char *placa){
    char c;
    int aa,dd,mm;
    arch>>codConductor>>c>>codInfracc>>c>>dd>>c>>mm>>c>>aa>>c;
    arch.getline(placa,9,'\n');
    fecha = dd+mm*100+aa*10000;
}

int Procesa::buscarConductor(int cod){
    for(int i = 0;i<cantidad;i++){
        if(lregistro[i].GetLicencia()==cod)return i;
    }
    return -1;
}


void Procesa::imprime(){
    ofstream arch;
    AbrirArchivo("ReporteProcesa.txt",arch);
    for(int i=0;i<cantidad;i++){
        lregistro[i].imprime(arch);
    }
}
void Procesa::consolida(){
    ofstream arch;
    AbrirArchivo("ReporteConsolida.txt",arch);
    for(int i=0;i<cantidad;i++){
        lregistro[i].imprimeConsolidado(arch);
    }
}



