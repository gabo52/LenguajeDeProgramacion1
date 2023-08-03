/* 
 * File:   Nodo.h
 * Autor: Gabriel Omar Durán Ruiz 
 * Código: 20203371
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

