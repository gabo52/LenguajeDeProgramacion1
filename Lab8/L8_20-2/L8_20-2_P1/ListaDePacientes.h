/* 
 * File:   ListaDePacientes.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
 * Created on 7 de noviembre de 2022, 10:51 AM
 */

#ifndef LISTADEPACIENTES_H
#define LISTADEPACIENTES_H

#include "Ambulatorio.h"
#include "Urgencia.h"
#include "Emergencia.h"


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
private:
    Ambulatorio *lAmb;
    Urgencia *lUrg;
    Emergencia *lEmer;
};

#endif /* LISTADEPACIENTES_H */

