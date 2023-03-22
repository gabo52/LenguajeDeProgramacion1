/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaDePacientes.h
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2022, 10:51 AM
 */

#ifndef LISTADEPACIENTES_H
#define LISTADEPACIENTES_H
#include <fstream>
#include "Ambulatorio.h"
#include "Urgencia.h"
#include "Emergencia.h"
using namespace std;

class ListaDePacientes {
public:
    ListaDePacientes();
    virtual ~ListaDePacientes();
    void operator + (const Ambulatorio &c);
    void operator + (const Urgencia &c);
    void operator + (const Emergencia &c);
    int numAmbulatorio()const;
    int numUrgencia()const;
    int numEmergencia()const;
    void setLEmer(Emergencia* lEmer);
    void getLEmer(Emergencia*aux) const;
    void setLUrg(Urgencia* lUrg);
    void getLUrg(Urgencia*aux) const;
    void setLAmb(Ambulatorio* lAmb);
    void getLAmb(Ambulatorio*aux) const;
    void imprimeEmergencias(ofstream &arch);
    void imprimeUrgencias(ofstream &arch);
    void imprimeAmbulatorio(ofstream &arch);
private:
    Ambulatorio *lAmb;
    Urgencia *lUrg;
    Emergencia *lEmer;
};

#endif /* LISTADEPACIENTES_H */

