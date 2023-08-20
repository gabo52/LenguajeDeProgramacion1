/* 
 * File:   Registro.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 8 de noviembre de 2022, 06:53 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include "Leve.h"
#include "Grave.h"
#include "MuyGrave.h"
#include "Conductor.h"
#include <fstream>
using namespace std;

class Registro:public Conductor {
public:
    Registro();
    virtual ~Registro();
    void agregaConductor(int cod);
    void agregarFalta(int cod,int fecha,char *placa);
    void agregaFaltaLeve(int cod,double desc,int fecha,char *gravedad,
        double multa,char *placa);
    void agregaFaltaGrave(int cod,double desc,int fecha,char *gravedad,
        double multa,char *placa,int puntos);
    void agregaFaltaMuyGrave(int cod,int meses,int fecha,char *gravedad,
        double multa,char *placa,int puntos);
    int numFaltaLeve();
    int numFaltaGrave();
    int numFaltaMGrave();
    int imprime(ofstream &arch);
    void imprimeFaltasLeves(ofstream &arch);
    void imprimeFaltasGraves(ofstream &arch);
    void imprimeFaltasMuyGraves(ofstream &arch);
    void imprimeConsolidado(ofstream &arch);
    double hallaMontoMultas();
    int hallaPuntosPerdidos();
    int hallaMesesSancionados();
private:
    Leve *lleve;
    Grave *lgrave;
    MuyGrave *lmgrave;
};

#endif /* REGISTRO_H */

