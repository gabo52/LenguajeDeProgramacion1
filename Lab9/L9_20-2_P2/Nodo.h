/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Gabo
 *
 * Created on 15 de noviembre de 2022, 12:54 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Paciente.h"
#include "ListaDePacientes.h"


class Nodo{
public:
    Nodo();
    friend class ListaDePacientes;
private:
    Paciente *pac;
    Nodo *sig;
};

#endif /* NODO_H */

