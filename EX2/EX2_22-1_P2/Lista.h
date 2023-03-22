/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: Gabo
 *
 * Created on 27 de noviembre de 2022, 03:11 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"


class Lista {
public:
    Lista();
    void inserta(Pedido &ped);
    virtual ~Lista();
    void imprime(ofstream &arch);
    void actualizaPrioridad(int prioridad,int cod);
    void reordenar();
private:
    void insertarAlInicio(Pedido &ped);
    class  Nodo *lini;
    class Nodo *lfin;
};

#endif /* LISTA_H */

